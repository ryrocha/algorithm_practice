#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        int left {1};
        int right {x};
        while (left + 1 < right) {
            int mean {left + (right - left)/2};
            if(mean > x/mean) {
                right = mean;
            } else {
                left = mean;
            } 
        }
        return left;
    }
};

int main() {
    Solution S;
    cout << S.mySqrt(11) << endl;
    return 0;
}