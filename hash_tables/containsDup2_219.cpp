#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) {
            if (num_map.find(nums[i]) != num_map.end()) {
                int diff {i - num_map.find(nums[i])->second};
                if (diff <= k) {
                    return true;
                } else {
                    num_map.find(nums[i])->second = i;
                } 
            } else {
                num_map.insert(make_pair(nums[i], i));
            }
        }
        return false;
    }
};

int main() {
    return 0;
}