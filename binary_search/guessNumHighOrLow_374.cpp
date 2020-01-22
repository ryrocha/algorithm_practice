#include <iostream>

using namespace std;



class Solution {
public:
    int guess(int num) {
        int choice {2};
        if(num == choice) {
            return 0;
        } else if(num > choice) {
            return -1;
        } else if(num < choice) {
            return 1;
        }
    }

    int guessNumber(int n) {
        int left {1};
        int right {n};
        if(guess(left) == 0) return left;
        while(left + 1 < right) {
            int mean {left + (right - left)/2};
            if(guess(mean) == 1) {
                left = mean;
            } else if(guess(mean) == -1) {
                right = mean;
            } else {
                return mean;
            }
        }
        return left + 1;
    }

    // another approach is to use while(left <= right)
    // left = mean + 1 whenever its higher than mean 
    // right = mean - 1 whenever its lower than mean
    // if rightmost is chosen, left will move until left == right
    // mean will evaluate to chosen with left == right and function will return
};

int main() {
    Solution S;
    cout << S.guessNumber(31) << endl;
    return 0;
}