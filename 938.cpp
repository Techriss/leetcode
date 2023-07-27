#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// best inorder
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return 0;
    int sum = 0;
    if (root->val > low) sum += rangeSumBST(root->left, low, high);
    if (root->val >= low && root->val <= high) sum += root->val;
    if (root->val < high) sum += rangeSumBST(root->right, low, high);
    return sum;
}

// not optimized inorder
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return 0;
    return ((root->val >= low && root->val <= high) ? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

// iterative
int rangeSumBST(TreeNode* T, int L, int H) {
    queue<TreeNode*> q;
    q.push(T);
    int sum = 0, v;

    while (size(q)) {
        T = q.front(); q.pop();
        v = T->val;
        if (v >= L && v <= H) sum += v;
        if (v > L && T->left) q.push(T->left);
        if (v < H && T->right) q.push(T->right);
    }
    return sum;
}