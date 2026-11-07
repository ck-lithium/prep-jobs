/*
 * Min Stack
 * LeetCode 155 (Medium) - https://leetcode.com/problems/min-stack/
 *
 * Design a stack that can also return its smallest element, with every
 * operation in O(1) time.
 *
 * Implement the MinStack class:
 *   MinStack()         Creates an empty stack.
 *   void push(int val) Pushes val.
 *   void pop()         Removes the top element.
 *   int top()          Returns the top element.
 *   int getMin()       Returns the smallest element in the stack.
 *
 * Example:
 *   MinStack s;
 *   s.push(-2);
 *   s.push(0);
 *   s.push(-3);
 *   s.getMin();   // -3
 *   s.pop();
 *   s.top();      // 0
 *   s.getMin();   // -2
 *
 * Constraints:
 *   -2^31 <= val <= 2^31 - 1
 *   pop, top and getMin are only called on a non-empty stack.
 *   At most 3 * 10^4 calls in total.
 *
 * Target: O(1) per operation. Hint: when you pop the minimum, you need to know
 * what the minimum was before it was pushed. Store that alongside.
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        // TODO
    }

    void push(int val) {
        // TODO
    }

    void pop() {
        // TODO
    }

    int top() {
        // TODO
        return 0;
    }

    int getMin() {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_minStack.cpp && ./a.out
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
    // The example from the problem.
    {
        MinStack s;
        s.push(-2);
        s.push(0);
        s.push(-3);
        check(s.getMin(), -3);
        s.pop();
        check(s.top(), 0);
        check(s.getMin(), -2);
    }
    // The same minimum pushed twice: popping one copy keeps the other.
    {
        MinStack s;
        s.push(1);
        s.push(1);
        s.push(2);
        s.pop();
        s.pop();
        check(s.getMin(), 1);
        check(s.top(), 1);
    }
    // Extreme values (tricks that store val - min overflow here).
    {
        MinStack s;
        s.push(INT_MAX);
        s.push(INT_MIN);
        check(s.getMin(), INT_MIN);
        check(s.top(), INT_MIN);
        s.pop();
        check(s.getMin(), INT_MAX);
        s.push(-1);
        check(s.getMin(), -1);
    }
    // Decreasing then popping back up.
    {
        MinStack s;
        for (int v = 10; v >= 1; v--) s.push(v);
        check(s.getMin(), 1);
        for (int i = 0; i < 5; i++) s.pop();
        check(s.getMin(), 6);
        check(s.top(), 6);
    }

    cout << passed << "/" << total << " tests passed\n";
}
