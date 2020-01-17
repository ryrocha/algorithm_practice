#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int x) {
        if(!x) return true;
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
        if(left == (double)x/left) return true;
        return false;
    }
};

int main() {
    Solution S;
    cout << S.isPerfectSquare(0) << endl;
    return 0;
}