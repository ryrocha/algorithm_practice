#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t vec_size {nums.size()};
        int sum_num {0};
        int sum_ideal {0};
        for (int i = 0; i < vec_size; i++) {
            sum_num += nums[i];
            sum_ideal += i;
        }
        sum_ideal += vec_size;
        int missing {sum_ideal - sum_num};
        return missing;
    }
};

int main() {
    Solution S;
    vector<int> nums {9,6,4,2,3,5,7,0,1};
    cout << S.missingNumber(nums) << endl; 
    return 0;
}