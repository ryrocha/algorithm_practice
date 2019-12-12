#include <iostream>
using namespace std;

// same as leetcode 50
class Solution {
public:
    double myPow(double x, int n) {
        double result {1.0};
        long long power {n};
        if (power < 1) {
            power = -power;
            x = 1.0 / x;
        }
        while (power) {
            if (power & 1) {
                result *= x;
            }
            x *= x;
            power >>= 1;
        }
        return result;
    }
};

int main() {
    Solution S;
    cout << S.myPow(2.0, 10) << endl;
    return 0;
}