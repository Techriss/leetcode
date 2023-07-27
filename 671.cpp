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

int findSecondMinimumValue(TreeNode* root) {
    int min = root->val;
    long long min2 = dfs(root, root->val);

    return min == min2 || min2 == LLONG_MAX ? -1 : (int)min2;
}

int64_t dfs(TreeNode* root, int &min) {
    if (root == nullptr) return LLONG_MAX;
    if (root->val != min) return root->val;
    return std::min(dfs(root->left, min), dfs(root->right, min));
}