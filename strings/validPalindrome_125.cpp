#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // first attempt, dynamic vector uses a lot of memory and is not optimal
    bool isPalindrome(string s) {
        vector<char> schars {}; 
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) {
                schars.push_back(tolower(s[i]));
            }
        }

        vector<char> copy {schars};
        reverse(copy.begin(), copy.end());

        if (copy == schars) return true;
        return false; 

    }

    // optimal is to use the two pointer approach and start from either end
    // use while loop and skip non alphanum chars
    // speed up by replacing isalnum with operators checking against 'a', 'z', 'A', etc. 
};

int main() {
    Solution S;
    cout << S.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}