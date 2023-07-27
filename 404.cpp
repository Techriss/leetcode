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

int sumOfLeftLeaves(TreeNode* root) {
    int* sum = new int(0);
    lsum_dfs(root, sum);
    return *sum;
}

void lsum_dfs(TreeNode* root, int* sum) {
    if (root == nullptr) return;
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        *sum += root->left->val;
    }
    else {
        lsum_dfs(root->left, sum);
    }
    lsum_dfs(root->right, sum);
}

