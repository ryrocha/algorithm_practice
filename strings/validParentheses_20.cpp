#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // first attempt
    bool isValid(string s) {
        string stack;
        int stacki {-1};
        for (int i = 0; i < s.size(); ++i) {
            ++stacki; 
            if (stacki != 0) {
                bool pairp {stack[stacki - 1] == '(' & s[i] == ')'};
                bool pairc {stack[stacki - 1] == '{' & s[i] == '}'};
                bool pairb {stack[stacki - 1] == '[' & s[i] == ']'};
                if (pairp | pairc | pairb) {
                    stack.pop_back();
                    stacki -= 2;
                } else {
                    stack.push_back(s[i]);
                }
            } else {
                stack.push_back(s[i]);
            }
        }
        if (stack == "") return true;
        return false;
    }

    // after seeing solution: c++ has a stack datatype
    // str is a stack with char types
    // same idea as above but comparison becomes: str.top() == '{' && s[i] == '}'
    // use str.pop() to pop if comparison is true
    // above used less memory than the stack method but was slower
};

int main () {
    Solution S;
    cout << S.isValid("[()[]{}]()[()]{}") << endl;
    return 0;
}