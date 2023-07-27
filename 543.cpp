#include <iostream>
#include <unordered_map>
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

// keep map of max depth for each node, get max l+r
int diameterOfBinaryTree(TreeNode* root) {
    unordered_map<TreeNode*, int> m;
    maxd(root, m);
    int maxv = INT_MIN;
    maxdfs(root, maxv, m);
    maxv = max(maxv, m[root]);
    return maxv;
}

int maxd(TreeNode* root, unordered_map<TreeNode*, int> &m) {
    if (root == nullptr) return 0;
    m[root] = max(maxd(root->left, m), maxd(root->right, m)) + 1;
    return m[root];
}

void maxdfs(TreeNode* root, int &maxv, unordered_map<TreeNode*, int> &m) {
    if (root == nullptr) return;
    if (root->left != nullptr && root->right != nullptr) {
        maxv = max(maxv, m[root->left]+m[root->right]);
    }

    maxdfs(root->left, maxv, m);
    maxdfs(root->right, maxv, m);
}





// solve returns max depth, maxi stores max diameter (max l+r depths)
int maxi = 0;
int solve(TreeNode* &root){
    if (root == NULL) return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    maxi = max(maxi, (left + right));
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    solve(root);
    return maxi;
}

