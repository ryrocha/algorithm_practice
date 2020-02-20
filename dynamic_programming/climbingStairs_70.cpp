#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //// top down approach using recursion
    // int result;
    // vector<int> memo {1,1};
    // int climbStairs(int n) {
    //     if(n == -1) return 1;
    //     if(n < memo.size()) return memo[n];
    //     result = climbStairs(n-1) + climbStairs(n-2);
    //     memo.push_back(result);
    //     return result;
    // }

    // bottom up approach
    int result;
    int left {1};
    int right {1};
    int climbStairs(int n) {
        for (int i {1}; i < n; ++i) {
            int tmp {right};
            right += left;
            left = tmp;
        }
        return right;
    }

};

int main() {
    Solution S;
    cout << S.climbStairs(2) << endl;
    return 0;
}