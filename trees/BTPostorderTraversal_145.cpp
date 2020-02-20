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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return vals;
        if(root->left != NULL) postorderTraversal(root->left);
        if(root->right != NULL) postorderTraversal(root->right);
        vals.push_back(root->val);
        return vals;
    }
};

int main() {
    return 0;
}