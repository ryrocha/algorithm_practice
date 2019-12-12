#include <iostream>
using namespace std;

class Solution {
public: 
    int getSum(int a, int b) {
        unsigned int x {a}; // converts to unsigned int and preserves sign bit
        unsigned int y {b};
        while(y != 0) {
            // dont want to shift signed ints
            unsigned int carry = x & y; 
            x ^= y;
            y = carry << 1;
        }
        return x; // function returns int, sign bit is reverted back 
    }
};

int main() {
    Solution S;
    cout << S.getSum(-2, -12) << endl;
    return 0;
}