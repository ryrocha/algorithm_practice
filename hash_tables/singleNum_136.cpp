#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> nums{1,1,2,3,2};
    unordered_map<int, int> hash_map;

    // wanted to try a hash table approach, I believe sort is better
    for (size_t i {0}; i < nums.size(); ++i) {
        if (hash_map.find(nums[i]) != hash_map.end()) {
            hash_map.find(nums[i])->second = 2;
        } else {
            hash_map.insert(make_pair(nums[i], 1));
        }
    }

    for (size_t i {0}; i < nums.size(); ++i) 
        if (hash_map.find(nums[i])->second == 1) 
            cout << hash_map.find(nums[i])->first << endl;

    // using sort
    vector<int> nums_sorted {nums};
    sort(nums_sorted.begin(), nums_sorted.end());
    int current_num {nums_sorted[0]};
    bool pair {false};

    for (size_t i {1}; i < nums.size(); ++i) {
        if (nums_sorted[i] == current_num) {
            pair = true;
        } else if (pair) {
            current_num = nums_sorted[i];
            pair = false;
        } else {
            break;
        }
    }
    cout << current_num << endl;

    /* improvement to hash table approach after seeing solutions
     * erase element after finding element
     * in the end the hash table only has one element
     */
    unordered_map<int, int> map;

    for (int num: nums) {
        if (map.find(num) != map.end()) {
            map.erase(num);
        } else {
            map.insert(make_pair(num, 1));
        }
    }
    cout << map.begin()->first << endl;
}