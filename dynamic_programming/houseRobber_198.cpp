#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n {nums.size()};
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int sum1 {nums[0]};
        int sum2 {max(nums[0], nums[1])};
        int sum3;
        int i {2};
        while (i < n) {
            sum3 = max(sum1 + nums[i], sum2);
            sum1 = sum2;
            sum2 = sum3;
            ++i;
        } 
        return sum3;
    }
};

int main() {
    vector<int> nums {5,1,20,30,50,3};
    Solution S;
    cout << S.rob(nums) << endl;
    return 0;
}