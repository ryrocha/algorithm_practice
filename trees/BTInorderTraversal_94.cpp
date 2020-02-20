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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return vals;
        if(root->left != NULL) inorderTraversal(root->left);
        vals.push_back(root->val);
        if(root->right != NULL) inorderTraversal(root->right);
        return vals;
    }
};

int main() {
    return 0;
}