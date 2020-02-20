#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int max_level {1};
    int level {1};
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left != NULL) {
            ++level;
            maxDepth(root->left);
        }
        if (root->right != NULL) {
            ++level;
            maxDepth(root->right);
        }
        if (level > max_level) max_level = level;
        --level;
        return max_level;
    }
};

int main() {
    return 0;
}