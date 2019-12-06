#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    // brute force approach for 16 bit unsigned int
    unsigned short int SwapBits(unsigned short int x) {
        unsigned short int bit_mask;
        for (int i = 0; i < 8; i++) {
            if (((x >> 15 - i) & 1) != ((x >> i) & 1)) {
                bit_mask = (1 << 15 - i) | (1 << i);
                x ^= bit_mask;
            }
        }
        return x;
    }

    // optimal approach (to be pursued) uses lookup table for many operations
};

int main() {
    unsigned short int x {40000};
    Solution S;
    cout << S.SwapBits(x) << endl;
    return 0;
}