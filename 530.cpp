#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getMinimumDifference(TreeNode* root) {
    int64_t minv = INT_MAX, prev = INT_MIN;

    inorder(root, minv, prev);

    return minv;
}

void inorder(TreeNode* root, int64_t &minv, int64_t &prev) {
    if (root == nullptr) return;
    inorder(root->left, minv, prev);

    minv = min(minv, abs(prev-(root->val)));
    prev = root->val;

    inorder(root->right, minv, prev);
}

