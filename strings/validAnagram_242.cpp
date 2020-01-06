#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // map approach
        unordered_map<int, int> smap;
        unordered_map<int, int> tmap;
        bool isAna {true};
        if (s.size() == t.size()) {
            for (int i = 0; i < s.size(); ++i) {
                if (smap.find(s[i]) != smap.end()) {
                    smap.find(s[i])->second += 1;
                } else {
                    smap.insert(make_pair(s[i], 1));
                }

                if (tmap.find(t[i]) != tmap.end()) {
                    tmap.find(t[i])->second += 1; 
                } else {
                    tmap.insert(make_pair(t[i], 1));
                }
            }

            for (int j = 0; j < s.size(); ++j) {
                if (tmap.find(s[j]) != tmap.end()) {
                    if (smap.find(s[j])->second != tmap.find(s[j])->second) {
                        isAna = false;
                        break;
                    } 
                } else {
                    isAna = false;
                    break;
                }
            }
        } else {
            isAna = false;
        }

        return isAna;
    }

    // using sort
    bool isAnaSort(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // fastest approach after seeing solution uses letter subtraction
    // counts letters by using the result of subtraction with 'a' as an index to a vector
    // adds one to the value in that vector at that index when it lands there
    // ex: 'c' - 'a' = 2
};

int main () {
    Solution S;
    cout << S.isAnaSort("anagram", "naagram") << endl;
    return 0;
}