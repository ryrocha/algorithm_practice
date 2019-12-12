#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int count {0};
        while(n != 0) { // also can use while(n)
            if (n & 1) count += 1; // more optimal: count += n & 1 
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution S;
    cout << S.hammingWeight(1) << endl;
    return 0;
}