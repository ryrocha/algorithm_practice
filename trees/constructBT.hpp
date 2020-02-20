// constructed from pre-order and in-order traversal vector
#include <cstddef>
#include <vector>

using namespace std;

class constructBT {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode* buildTree(vector<int> preorder, vector<int> inorder);
    TreeNode* buildNodes(vector<int> preorder, vector<int> inorder, int& root, int left, int right);
    void display(TreeNode* root);
};