#include <cstddef>
#include "constructBT.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    constructBT::TreeNode* invertTree(constructBT::TreeNode* root) {
        if (root == NULL) return root;
        constructBT::TreeNode* invert = new constructBT::TreeNode(root->val);
        return buildInvert(invert, root);
    }

    constructBT::TreeNode* buildInvert(constructBT::TreeNode* invert, constructBT::TreeNode* root) {
        if (root->left != NULL) {
            constructBT::TreeNode* tmp = new constructBT::TreeNode(root->left->val);
            invert->right = tmp;
            buildInvert(invert->right, root->left);
        }
        if (root->right != NULL) {
            constructBT::TreeNode* tmp = new constructBT::TreeNode(root->right->val);
            invert->left = tmp;
            buildInvert(invert->left, root->right);
        }
        return invert;
    }
};

int main() {
    vector<int> preorder {4,2,1,3,7,6,9};
    vector<int> inorder {1,2,3,4,6,7,9};
    constructBT* obj = new constructBT();
    constructBT::TreeNode* root {obj->buildTree(preorder, inorder)};
    
    Solution S;
    constructBT::TreeNode* invert {S.invertTree(root)};
    obj->display(invert);
    cout << endl;
    return 0;
}