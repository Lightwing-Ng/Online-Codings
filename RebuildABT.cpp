
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (!pre.size())
            return nullptr;
        else if (pre.size() == 1) {
            TreeNode *node = new TreeNode(pre.back());
            node->left = nullptr;
            node->right = nullptr;
            return node;
        } else {
            TreeNode *node = new TreeNode(pre.at(0));
            vector<int>::iterator it = vin.begin();
            while (it != vin.end() && *it != pre.at(0))
                ++it;
            int dis = it - vin.begin();
            vector<int> pre1(pre.begin() + 1, pre.begin() + dis + 1);
            vector<int> pre2(pre.begin() + dis + 1, pre.end());
            vector<int> vin1(vin.begin(), it);
            vector<int> vin2(it + 1, vin.end());
            node->left = reConstructBinaryTree(pre1, vin1);
            node->right = reConstructBinaryTree(pre2, vin2);
            return node;
        }
    }
};