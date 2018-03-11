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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> ret;
        if (root == NULL)
            return ret;
        queue<TreeNode> q;
        q.push(*root);
        while (!q.empty()) {
            ret.push_back(q.front().val);
            if (q.front().left != NULL)
                q.push(*(q.front().left));
            if (q.front().right != NULL)
                q.push(*(q.front().right));
            q.pop();
        }
        return ret;
    }
};