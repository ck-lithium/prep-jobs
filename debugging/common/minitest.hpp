// minitest: a tiny unit-test framework with GoogleTest-style macros, so the
// exercises build with nothing but g++ and make. You don't need to read it.
//
//   TEST(Suite, Name) { ... }                 defines a test
//   EXPECT_EQ(actual, expected)               records a failure and keeps going
//   ASSERT_EQ(actual, expected)               records a failure and ends the test
//   EXPECT_TRUE(x) / EXPECT_FALSE(x) / ASSERT_TRUE(x)
//   EXPECT_THROW(statement, exception_type)
//
// Like in GoogleTest, a macro argument can't contain a bare comma, so build
// vectors in a variable first:  std::vector<int> expected = {1, 2};
#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace minitest {

struct Test {
    std::string name;  // "Suite.Name"
    void (*body)();
};

inline std::vector<Test>& allTests() {
    static std::vector<Test> tests;
    return tests;
}

inline bool& currentTestFailed() {
    static bool failed = false;
    return failed;
}

struct Register {
    Register(const char* suite, const char* name, void (*body)()) {
        allTests().push_back({std::string(suite) + "." + name, body});
    }
};

struct StopTest {};  // thrown by a failed ASSERT_* to end the current test

template <typename T, typename = void>
struct Printable : std::false_type {};
template <typename T>
struct Printable<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const T&>())>>
    : std::true_type {};

template <typename T>
std::string show(const T& value);

template <typename T>
std::string show(const std::vector<T>& values) {
    std::string out = "[";
    for (std::size_t i = 0; i < values.size(); i++) out += (i ? ", " : "") + show(values[i]);
    return out + "]";
}

template <typename T>
std::string show(const T& value) {
    if constexpr (std::is_same_v<T, bool>) {
        return value ? "true" : "false";
    } else if constexpr (std::is_same_v<T, std::string>) {
        return '"' + value + '"';
    } else if constexpr (Printable<T>::value) {
        std::ostringstream out;
        out << value;
        return out.str();
    } else if constexpr (std::is_enum_v<T>) {
        return std::to_string(static_cast<long long>(value));
    } else {
        return "(can't print this value)";
    }
}

inline void fail(const char* file, int line, const std::string& message, bool fatal) {
    currentTestFailed() = true;
    std::cout << "  " << file << ":" << line << ": " << message << "\n";
    if (fatal) throw StopTest{};
}

template <typename A, typename B>
void checkEqual(const A& actual, const B& expected, const char* actualText,
                const char* expectedText, const char* file, int line, bool fatal) {
    if (actual == expected) return;
    fail(file, line,
         std::string(actualText) + " should equal " + expectedText + "\n" +
             "      got:      " + show(actual) + "\n" +
             "      expected: " + show(expected),
         fatal);
}

inline void checkTrue(bool ok, const char* message, const char* file, int line, bool fatal) {
    if (!ok) fail(file, line, message, fatal);
}

}  // namespace minitest

#define TEST(suite, name)                                                           \
    static void suite##_##name##_test();                                            \
    static const ::minitest::Register suite##_##name##_registered(#suite, #name,    \
                                                                  suite##_##name##_test); \
    static void suite##_##name##_test()

#define EXPECT_EQ(actual, expected) \
    ::minitest::checkEqual((actual), (expected), #actual, #expected, __FILE__, __LINE__, false)
#define ASSERT_EQ(actual, expected) \
    ::minitest::checkEqual((actual), (expected), #actual, #expected, __FILE__, __LINE__, true)
#define EXPECT_TRUE(condition) \
    ::minitest::checkTrue(static_cast<bool>(condition), #condition " should be true", __FILE__, __LINE__, false)
#define ASSERT_TRUE(condition) \
    ::minitest::checkTrue(static_cast<bool>(condition), #condition " should be true", __FILE__, __LINE__, true)
#define EXPECT_FALSE(condition) \
    ::minitest::checkTrue(!(condition), #condition " should be false", __FILE__, __LINE__, false)

#define EXPECT_THROW(statement, exception_type)                                    \
    do {                                                                            \
        bool minitestThrew = false;                                                 \
        try {                                                                       \
            statement;                                                              \
        } catch (const exception_type&) {                                           \
            minitestThrew = true;                                                   \
        } catch (...) {                                                             \
        }                                                                           \
        if (!minitestThrew)                                                         \
            ::minitest::fail(__FILE__, __LINE__,                                    \
                             #statement " should throw " #exception_type, false);   \
    } while (false)
