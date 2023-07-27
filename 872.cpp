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

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    string s1 = "", s2 = "";
    leaforder(root1, s1);
    leaforder(root2, s2);
    return s1 == s2;
}

void leaforder(TreeNode* root, string &s) {
    if (root == nullptr) return;
    leaforder(root->left, s);
    if (root->left == nullptr && root->right == nullptr) s += root->val;
    leaforder(root->right, s);
}