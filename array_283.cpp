#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums {0,0,0,1,0};
    int i {0};

    // First approach; one-pass
    for (int num: nums) {
        if (nums[i] == 0) {
            nums.erase(nums.begin()+i);
            nums.push_back(0);
            continue;
        }
        ++i;
    }

    for (int num: nums) 
        cout << num << " ";
    cout << endl;

    // Using swap; pursued after seeing solution
    vector<int> nums1 {0,0,0,1,0};
    int j {0};
    for (int& num: nums1) 
        if (num != 0)
            swap(nums1[j++], num);

    for (int num: nums1) 
        cout << num << " ";
    cout << endl;
}