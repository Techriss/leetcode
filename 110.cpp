#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool balanced = true;

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    depth(root);
    return balanced;
}

int depth(TreeNode* root) {
    if (!balanced) return -1;
    if (root == nullptr) return 0;

    int l = depth(root->left);
    int r = depth(root->right);

    if (l-r > 1 || l-r > -1) balanced = false;
    return max(l, r) + 1;
}