#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> nums{1,2,4,5,3};
    int minNum {nums[0]}, minInd {0};
    int maxNum {nums[0]}, maxInd {0};
    size_t leftInd {nums.size()}, leftTmpInd {nums.size()};
    int rightInd {0}, rightTmpInd {0};
    int shortSize {0};

    /* First attempt at one pass; wrong
     * only tracks lowest and highest numbers
     * will not pick up order issues caused by numbers that fall between the low and high
     */
    for (size_t i {1}; i < nums.size(); ++i) {
        if (nums[i] < minNum) {
            leftTmpInd = minInd;
            rightTmpInd = i;
            minNum = nums[i];
            minInd = i;
        } else if (nums[i] < maxNum) {
            leftTmpInd = maxInd;
            rightTmpInd = i;
        } else if (nums[i] > maxNum) {
            maxNum = nums[i];
            maxInd = i;
        } 

        if (leftTmpInd < leftInd) 
            leftInd = leftTmpInd;

        if (rightTmpInd > rightInd) 
            rightInd = rightTmpInd;
    }

    if (rightInd > leftInd) {
        shortSize = rightInd - leftInd + 1;
        cout << shortSize << endl;
    } else {
        cout << shortSize << endl;
    }

    int shortSize1 {0};
    size_t leftInd1 {nums.size()}, leftTmpInd1 {nums.size()};
    int rightInd1 {0}, rightTmpInd1 {0};
    int tmpSize {0};

    // Nested loop; second try, exceeds time limit
    for (size_t i {0}; i < nums.size(); ++i) {
        for (size_t j {i+1}; j < nums.size(); ++j) {
            if (nums[i] > nums[j]) {
                leftTmpInd1 = i;
                rightTmpInd1 = j;

                if (leftTmpInd1 < leftInd1) 
                    leftInd1 = leftTmpInd1;
                
                if (rightTmpInd1 > rightInd1)
                    rightInd1 = rightTmpInd1;
            }
        }
    }
    if (rightInd1 > leftInd1) {
        shortSize1 = rightInd1 - leftInd1 + 1;
        cout << shortSize1 << endl;
    } else {
        cout << shortSize1 << endl;
    }

    // Single pass using sort; completed after seeing hint to use sort
    vector<int> nums_sorted {nums};
    sort(nums_sorted.begin(), nums_sorted.end());
    size_t leftInd2 {nums.size()}, leftTmpInd2 {nums.size()};
    int rightInd2 {0};
    int shortSize2 {0};

    for (size_t i {0}; i < nums.size(); ++i) {
        if (nums[i] != nums_sorted[i]) {
            leftTmpInd2 = i;
            rightInd2 = i;

            if (leftTmpInd2 < leftInd2) 
                leftInd2 = leftTmpInd2;
        }
    }
    if (rightInd2 > leftInd2) {
        shortSize2 = rightInd2 - leftInd2 + 1;
        cout << shortSize2 << endl;
    } else {
        cout << shortSize2 << endl;
    }
}