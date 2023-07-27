#include <vector>
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


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == nullptr) return v;

    auto left = inorderTraversal(root->left);
    v.insert(v.end(), left.begin(), left.end());

    v.push_back(root->val);

    auto right = inorderTraversal(root->right);
    v.insert(v.end(), right.begin(), right.end());
    return v;
}
