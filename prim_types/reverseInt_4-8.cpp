#include <iostream>
using namespace std;

// leetcode 7
class Solution {
public:
    int reverse(int x) {
        long long reverse {0};
        while (x) {
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        if ((reverse > 2147483647) | (reverse < -2147483648)) {
            return 0;
        } else {
            return reverse;
        }
    }
};

int main() {
    Solution S;
    cout << S.reverse(123) << endl;
    return 0;
}