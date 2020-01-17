#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isBadVersion(int version) {
        if(version < 2) {
            return false;
        }
        return true;
    }

    int firstBadVersion(int n) {
        int left {1};
        int right {n};
        while(left < right) {
            double mean {(double)(left + (right - left)/2)};
            if(isBadVersion(mean)) {
                right = mean;
            } else {
                left = mean + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution S;
    cout << S.firstBadVersion(1) << endl;
    return 0;
}