#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd {nums[0]}, left {0}, right {0};
        for (int i {0}; i < nums.size(); ++i) {
            if (left == 0) {
                left = nums[i];
            } else {
                left *= nums[i];
            }
            if (right == 0) {
                right = nums[nums.size()-1-i];
            } else {
                right *= nums[nums.size()-1-i];
            }
            maxProd = max(maxProd, max(left, right));
        }
        return maxProd;      
    }
    // much cleaner approach is to use ? operator
    // condition ? true : false
    // 0 returns false, any other integer returns true
    // left = (left ? left : 1) * nums[i]
    // right = (right ? right : 1) * nums[nums.size()-1-i]
};

int main() {
    vector<int> nums {-4,-1};
    Solution S;
    cout << S.maxProduct(nums) << endl;
    return 0;
}