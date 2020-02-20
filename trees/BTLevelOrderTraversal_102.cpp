#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<vector<int>> vals;
    int level {0};
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return vals;
        if(level >= vals.size()) vals.push_back(*(new vector<int>()));
        vals[level].push_back(root->val);
        if(root->left != NULL) {
            ++level;
            levelOrder(root->left);
        }
        if(root->right != NULL) {
            ++level;
            levelOrder(root->right);
        }
        --level;
        return vals;
    }
};

int main() {
    return 0;
}