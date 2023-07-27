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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == nullptr) return v;

    auto left = postorderTraversal(root->left);
    auto right = postorderTraversal(root->right);

    v.insert(v.end(), left.begin(), left.end());
    v.insert(v.end(), right.begin(), right.end());
    v.push_back(root->val);

    return v;
}

vector<int> postorderTraversal_it(TreeNode* root) {
    vector<int> v;
    if (root == nullptr) return v;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        auto n = s.top();
        s.pop();
        v.push_back(n->val);
        if (n->left != nullptr) s.push(n->left);
        if (n->right != nullptr) s.push(n->right);
    }

    vector<int> v2;
    for (int i = v.size()-1; i >= 0; i--) v2.push_back(v[i]);
    return v2;
}