#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool left {rec1[0] >= rec2[2]};
        bool right {rec1[2] <= rec2[0]};
        bool above {rec1[1] >= rec2[3]};
        bool below {rec1[3] <= rec2[1]};

        bool overlap {true};
        if (left | right | above | below) {
            overlap = false; 
        }

        return overlap;
    }
};

int main() {
    return 0;
}