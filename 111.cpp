#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    unordered_map<TreeNode*, int> m {{root, 1}};
    q.push(root);

    int level = 1;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        if (m[node] > level) level++;

        if (node->left == nullptr && node->right == nullptr) return level;

        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);

        m[node->left] = level+1;
        m[node->right] = level+1;
    }
}

