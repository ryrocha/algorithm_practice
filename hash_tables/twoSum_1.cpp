#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Nested loops: first approach, brute force solution
        int vec_size = nums.size();
		int ind1, ind2;
		vector<int> result1;
		for( int i = 0; i < vec_size - 1; i++ ) {
			for( int j = i + 1; j < vec_size; j++ ) {
				int sum = nums[i] + nums[j];
				if( sum == target ) {
					result1.push_back(i);
					result1.push_back(j);
				}
			}
		}
		return result1;

        // Hash table: pursued after seeing solution
		map<int, int> hash_map;
        vector<int> result2;
        for (size_t i; i < nums.size(); ++i) {
			int compliment = target - nums[i];
			if (hash_map.find(compliment) != hash_map.end()) {
				int compliment_ind {hash_map.find(compliment)->second};
				result2.push_back(compliment_ind);
                result2.push_back(i);
			} else {
			    hash_map.insert(make_pair(nums[i], i));
            }
        }
        return result2;	
    }
};

int main() {
	return 0;
}