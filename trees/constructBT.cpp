// constructed from pre-order and in-order traversal vector
#include <cstddef>
#include <vector>
#include <iostream>
#include "constructBT.hpp"

using namespace std;

constructBT::TreeNode* constructBT::buildTree(vector<int> preorder, vector<int> inorder) {
    int root {0};
    return constructBT::buildNodes(preorder, inorder, root, 0, inorder.size()-1);
}

constructBT::TreeNode* constructBT::buildNodes(vector<int> preorder, vector<int> inorder, int& root, int left, int right) {
    if (left > right) return NULL;
    int i {left};
    while (inorder[i] != preorder[root]) ++i;
    
    ++root;
    TreeNode* node = new TreeNode(inorder[i]);
    node->left = buildNodes(preorder, inorder, root, left, i-1);
    node->right = buildNodes(preorder, inorder, root, i+1, right);
    return node;
}

void constructBT::display(constructBT::TreeNode* root) {
    // displays preorder traversal
    cout << root->val << " ";
    if (root->left != NULL) display(root->left);
    if (root->right != NULL) display(root->right);
}