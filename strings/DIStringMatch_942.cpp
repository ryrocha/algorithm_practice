#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    // first attempt, inserting and erasing isn't optimal
    vector<int> diStringMatch(string S) {
        vector<int> nums (S.size() + 1);
        for (int i = 0; i <= S.size(); ++i) {
            nums[i] = i;
        }

        int count {0};
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'D') {
                ++count;
            } else {
                count = 0;
            }

            if (count) {
                nums.insert(nums.begin() + (i + 1 - count), nums[i + 1]); 
                nums.erase(nums.begin() + (i + 2));
            } 
        }

        return nums;        
    }
    // after seeing solution:
    // i = 0; j = S.size(); vector n;
    // if "I": n.push_back(i++);
    // if "D": n.push_pack(j--);
};

int main() {
    Solution sol;
    vector<int> nums {sol.diStringMatch("IDIDDIIIDDD")};
    for (int num : nums) {
        cout << num << endl;
    }
    return 0;
}