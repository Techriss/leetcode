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

int sumRootToLeaf(TreeNode* root, int prev = 0) {
    if (root == nullptr) return 0;
    int curr = (prev*2) + root->val;
    if (root->left == nullptr && root->right == nullptr) return curr;
    else return sumRootToLeaf(root->left, curr) + sumRootToLeaf(root->right, curr);
}