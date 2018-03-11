#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};
void insert(int v, TreeNode *root) {
    if (v == root->val)
        return;
    if (v < root->val) {
        if (!root->left)
            root->left = new TreeNode(v);
        else
            insert(v, root->left);
    } else {
        if (!root->right)
            root->right = new TreeNode(v);
        else
            insert(v, root->right);
    }
}

void preorderTraversal(TreeNode *root) {
    if (!root)
        return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(TreeNode *root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
void postorderTraversal(TreeNode *root) {
    if (!root)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    int N, val;
    while (cin >> N) {
        N--;
        cin >> val;
        TreeNode root(val);
        while (N--) {
            cin >> val;
            insert(val, &root);
        }
        preorderTraversal(&root);
        cout << endl;
        inorderTraversal(&root);
        cout << endl;
        postorderTraversal(&root);
        cout << endl;
    }
    return 0;
}
