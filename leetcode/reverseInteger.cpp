#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    // int reverse(int x) {

    //     long long int result = 0;
    //     long long int power = 1;

    //     long long int temp = x;

    //     while(temp != 0){
    //         temp /= 10;
    //         power *= 10;
    //     }

    //     power /= 10;

    //     while( x != 0 ){
    //         result += (x % 10) * power;
    //         x /= 10;
    //         power /= 10;
    //     }

    //     if (result > pow(2,31) - 1 || result < pow(2,31) * -1) return 0;
        
    //     return result;
    // }

    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int d = x % 10;          //
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && d > 7))  return 0;  
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && d < -8)) return 0; 
            rev = rev * 10 + d;
        }
        return rev;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // // Example 1
    int x1 = 123;
    cout << "Test Case 1 Output: " << solution.reverse(x1) << " (Expected: 321)\n";

    // Example 2
    int x2 = -123;
    cout << "Test Case 2 Output: " << solution.reverse(x2) << " (Expected: -321)\n";

    // // Example 3
    int x3 = 120;
    cout << "Test Case 3 Output: " << solution.reverse(x3) << " (Expected: 21)\n";

    return 0;
}