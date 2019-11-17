#include <iostream>
using namespace std;

/* The parity of a word is 1 if the number of ones in the word is odd; otherwise it is 0.
 * Find the parity of a large number of 64-bit words
 */

class Solution {
public:
    short Parity(unsigned long long x) {
        short result = 0;
        while(x) {
            result ^= (x & 1); // apply mask to result using XOR assign to result 
            x >>= 1; // shift bits of x to the right by one
        }
        return result;
    }
};

int main() {
	return 0;
}