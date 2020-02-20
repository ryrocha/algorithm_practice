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
    // messy
    bool same {true};
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool pnull {p == NULL};
        bool qnull {q == NULL};
        if (pnull && qnull) return true;
        if ((!pnull && qnull) | (pnull && !qnull)) return false;
        if (q->val != p->val) same = false;

        bool qleft {q->left != NULL};
        bool pleft {p->left != NULL};
        bool qright {q->right != NULL};
        bool pright {p->right != NULL};
        if ((!qleft && pleft) | (qleft && !pleft) | (!qright && pright) | (qright && !pright)) same = false;
        if (qleft && pleft) {
            isSameTree(p->left, q->left);
        }
        if (qright && pright) {
            isSameTree(p->right, q->right);
        }

        return same;
    }
    // can be cleaned up by just using !p and !q:
    // !p && !q return true
    // !p || !q return false
    // p->val != q->val return false
    // return f(p->left, q->left) && f(p->right, q->right)
};

int main() {
    return 0;
}