#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums{-2,1};
    int maxsum {nums[0]};

    for (size_t i {1}; i <= nums.size(); ++i) {
        for (size_t j {0}; j <= nums.size() - i; ++j) {
            int sum {0};
            for (size_t k {j}; k <= j+(i-1); ++k)
                sum += nums[k];
            if (sum > maxsum) 
                maxsum = sum;
        }  
    }
    cout << maxsum << endl;
}