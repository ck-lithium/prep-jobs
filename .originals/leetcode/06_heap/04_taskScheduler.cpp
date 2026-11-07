/*
 * Task Scheduler
 * LeetCode 621 (Medium) - https://leetcode.com/problems/task-scheduler/
 *
 * A CPU has to run a list of tasks, each labelled with a letter A-Z. Every
 * task takes one time unit, and in each unit the CPU either runs one task or
 * sits idle. Tasks can run in any order.
 *
 * Two tasks with the same label must be at least `n` units apart: after
 * running an A, the CPU must wait n units before the next A.
 *
 * Return the minimum number of time units needed to run every task.
 *
 * Example 1:
 *   Input:  tasks = [A, A, A, B, B, B], n = 2
 *   Output: 8
 *   Why:    A B idle A B idle A B.
 *
 * Example 2:
 *   Input:  tasks = [A, C, A, B, D, B], n = 1
 *   Output: 6
 *   Why:    A B C D A B, with no idle time.
 *
 * Example 3:
 *   Input:  tasks = [A, A, A, B, B, B], n = 3
 *   Output: 10
 *   Why:    A B idle idle A B idle idle A B.
 *
 * Constraints:
 *   1 <= tasks.length <= 10^4
 *   tasks[i] is an uppercase English letter.
 *   0 <= n <= 100
 *
 * Target: O(number of tasks). You can simulate with a max-heap of counts
 * (always run the task with the most copies left), or find a closed formula
 * from the most frequent task.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_taskScheduler.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    // Tasks are written as a string and converted to vector<char>.
    struct Case { string tasks; int n; int expected; };
    vector<Case> cases = {
        {"AAABBB", 2, 8},
        {"ACABDB", 1, 6},
        {"AAABBB", 3, 10},
        {"A", 5, 1},
        {"AA", 0, 2},
        {"AAA", 2, 7},
        {"AAAAAABCDEFG", 2, 16},
        {"ABCDEABCDE", 4, 10},
        {"ABCDEABCDE", 1, 10},
    };
    for (auto& c : cases) {
        vector<char> tasks(c.tasks.begin(), c.tasks.end());
        check(sol.leastInterval(tasks, c.n), c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
