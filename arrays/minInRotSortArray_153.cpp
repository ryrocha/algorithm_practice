#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l {0}, r {nums.size()-1};
        while (l < r) {
            int m {l + (r - l)/2};
            if (nums[m] <= nums[r]) r = m;
            else l = m + 1;
        }
        return nums[l];
    }
};

int main() {
    vector<int> nums {6,7,0,1,2,3,4,5};
    Solution S;
    cout << S.findMin(nums) << endl;
    return 0;
}