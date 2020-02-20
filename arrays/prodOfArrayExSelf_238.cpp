#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left {1};
        vector<int> right {1};
        for (int i {1}; i < nums.size(); ++i) {
            left.push_back(left[i-1]*nums[i-1]);
            right.push_back(right[i-1]*nums[nums.size()-i]);
        }
        vector<int> product;
        for (int j {0}; j < nums.size(); ++j) {
            product.push_back(left[j]*right[nums.size()-1-j]);
        }
        return product;
    }

    // faster/less space approach is to keep a single array
    // contrust the array of left products then loop to multiply those by right products
    // no need to contruct two arrays then multiply them together and place them in another array
};

int main() {
    vector<int> nums {1,2,3,4};
    Solution S;
    vector<int> out {S.productExceptSelf(nums)};
    for (int num : out) {
        cout << num << endl;
    }
    return 0;
}