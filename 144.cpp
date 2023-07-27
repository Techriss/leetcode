#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == nullptr) return v;

    auto left = preorderTraversal(root->left);
    auto right = preorderTraversal(root->right);

    v.push_back(root->val);
    v.insert(v.end(), left.begin(), left.end());
    v.insert(v.end(), right.begin(), right.end());

    return v;
}

vector<int> preorderTraversal_it(TreeNode* root) {
    vector<int> v;
    if (root == nullptr) return v;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        auto n = s.top();
        s.pop();
        v.push_back(n->val);
        if (n->right != nullptr) s.push(n->right);
        if (n->left != nullptr) s.push(n->left);
    }

    return v;
}