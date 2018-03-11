/*
    struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
    };
*/
class Solution {
public:
    bool same(TreeNode *s, TreeNode *t) {
        if (t == NULL)
            return true;
        else if (s == NULL)
            return false;
        else if (s->val == t->val)
            return same(s->left, t->left) && same(s->right, t->right);
        return false;
    }
    bool HasSubtree(TreeNode *s, TreeNode *t) {
        if (t == NULL || s == NULL)
            return false;
        else
            return same(s, t) || HasSubtree(s->left, t) || HasSubtree(s->right, t);
    }
};