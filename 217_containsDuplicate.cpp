#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    bool contains {false};
    vector<int> nums{4,2,3,1};

    // Hash table; fast search and insert operations, first/optimal approach
    unordered_map<int, int> hash_map; // changed map > unordered_map for increased speed
    for (size_t i {0}; i < nums.size(); ++i)
        if (hash_map.find(nums[i]) != hash_map.end()) {
            contains = true;
            break;
		} else {
			hash_map.insert(make_pair(nums[i], i));
        }
    cout << contains << endl;
}