#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool treeCompare(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return treeCompare(s->left, t->left) && treeCompare(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return false;
        if (treeCompare(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main() {
    return 0;
}