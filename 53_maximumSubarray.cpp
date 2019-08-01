#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int maxsum {nums[0]}, sum {nums[0]};

    /* Treated as a rolling sum:
     * check if the current element of nums > current sum + current element
     * if it is current sum = current element 
     * if it is not current sum += current element
     */
    for (size_t i {1}; i < nums.size(); ++i) {
        if (nums[i] > (sum + nums[i])) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }
        if (maxsum < sum)
            maxsum = sum;
    }
}