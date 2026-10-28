// Runs every test, or only the ones whose name contains the text given as the
// first argument:  ./build/visible_tests Merge
#include <string>
#include <vector>

#include "minitest.hpp"

int main(int argc, char** argv) {
    std::cout << std::unitbuf;  // print each line right away, even if a test crashes
    const std::string filter = argc > 1 ? argv[1] : "";
    std::vector<std::string> failed;
    int total = 0;

    for (const minitest::Test& test : minitest::allTests()) {
        if (test.name.find(filter) == std::string::npos) continue;
        total++;
        minitest::currentTestFailed() = false;
        std::cout << "[ RUN    ] " << test.name << "\n";
        try {
            test.body();
        } catch (const minitest::StopTest&) {
        } catch (const std::exception& e) {
            minitest::currentTestFailed() = true;
            std::cout << "  unexpected exception: " << e.what() << "\n";
        } catch (...) {
            minitest::currentTestFailed() = true;
            std::cout << "  unexpected exception\n";
        }
        bool ok = !minitest::currentTestFailed();
        if (!ok) failed.push_back(test.name);
        std::cout << (ok ? "[     OK ] " : "[ FAILED ] ") << test.name << "\n";
    }

    std::cout << "\n";
    if (!failed.empty()) {
        std::cout << "Failed:\n";
        for (const std::string& name : failed) std::cout << "  " << name << "\n";
    }
    std::cout << total - static_cast<int>(failed.size()) << "/" << total << " tests passed\n";
    return failed.empty() ? 0 : 1;
}
