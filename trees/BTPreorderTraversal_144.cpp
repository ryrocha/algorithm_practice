#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<int> vals;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return vals;
        vals.push_back(root->val);
        if(root->left != NULL) preorderTraversal(root->left);
        if(root->right != NULL) preorderTraversal(root->right);
        return vals;
    }
};

int main() {
    return 0;
}