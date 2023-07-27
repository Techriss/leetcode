#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using inorder vector
TreeNode* increasingBST(TreeNode* root) {
    vector<TreeNode*> v;
    inorder(root, v);

    TreeNode* nroot = v[0];
    TreeNode* node = nroot;

    for (int i = 1; i < v.size(); i++) {
        node->right = v[i];
        node = node->right;
    }

    return nroot;
}

void inorder(TreeNode* root, vector<TreeNode*> &v) {
    if (root == nullptr) return;
    inorder(root->left, v);
    root->left = nullptr;
    v.push_back(root);
    inorder(root->right, v);
    root->right = nullptr;
}





// impossible to understand consise recursive code
// but here's an attempt
//
// tail is always the next node
TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
    if (!root) return tail;
    TreeNode* res = increasingBST(root->left, root);               // res is always the leftmost node (the new root) since it was found
    root->left = NULL;
    root->right = increasingBST(root->right, tail);                // tail is the right's parent's parent (the curr's parent) (in other words: right is to its tail the rightmost node to the left), hence the next node it should be in order
                                                                   // so if called on leftmost node (new root) it will assign the parent as its right node (or the curr's right's (which does not exist) parent's parent as one)
    return res;
}