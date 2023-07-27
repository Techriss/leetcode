#include <iostream>
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


int get_depths(TreeNode* root, unordered_map<TreeNode*, int> &d) {
    if (root == nullptr) return d[root];
    if (root->left == nullptr && root->right == nullptr) return d[root];

    if (root->left != nullptr) d[root->left] = d[root] + 1;
    if (root->right != nullptr) d[root->right] = d[root] + 1;

    return max(get_depths(root->left, d), get_depths(root->right, d));
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    unordered_map<TreeNode*, int> d {{root, 1}};
    return get_depths(root, d);
}

int main() {
    TreeNode x3(15);
    TreeNode y3(7);
    TreeNode x2(9);
    TreeNode y2(20, &x3, &y3);
    TreeNode root(3, &x2, &y2);

    cout << maxDepth(&root) << endl;
}