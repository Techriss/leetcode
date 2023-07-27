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

// for every node find .... (slow)
int minDiffInBST(TreeNode* root) {
    int minv = INT_MAX;

    mindfs(root, minv);

    return minv;
}

void mindfs(TreeNode* root, int& minv) {
    if (root == nullptr) return;

    TreeNode* rightmostleft = root->left;
    while (rightmostleft != nullptr && rightmostleft->right != nullptr) rightmostleft = rightmostleft->right;

    TreeNode* leftmostright = root->right;
    while (leftmostright != nullptr && leftmostright->left != nullptr) leftmostright = leftmostright->left;

    if (rightmostleft == nullptr && leftmostright == nullptr) return;
    else if (rightmostleft == nullptr) minv = min(minv, leftmostright->val - root->val);
    else if (leftmostright == nullptr) minv = min(minv, root->val - rightmostleft->val);
    else minv = min(minv, min(root->val - rightmostleft->val, leftmostright->val - root->val));
    
    mindfs(root->left, minv);
    mindfs(root->right, minv);
}



// or again - inorder traversal
int minv = INT_MAX;
int pre = -1;             // quite an assumption, if the root's val were to be -1 it would make errors, should add special flag for the first node

int minDiffInBST(TreeNode* root) {
    if (root == nullptr) return;
    minDiffInBST(root->left);
    if (pre >= 0) minv = min(minv, root->val - pre);
    pre = root->val;
    minDiffInBST(root->right); 
    return minv;
}