#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string tree2str(TreeNode* root) {
    string s;
    preorder(root, s, false);
    return s;
}

void preorder(TreeNode* root, string &s, bool include) {
    if (include) s += "(";
    if (root == nullptr) {
        if (include) s += ")";
        return;
    }
    s += to_string(root->val);

    preorder(root->left, s, root->left || root->right);
    preorder(root->right, s, root->right);
    
    if (include) s += ")";
}