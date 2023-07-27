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

bool dfs_sum(TreeNode* root, int* sum, const int* targetsum) {
    if (root == nullptr) return false;

    *sum += root->val;

    if (root-> left == nullptr && root->right == nullptr && *sum == *targetsum) return true;
    bool l = dfs_sum(root->left, sum, targetsum);
    bool r = dfs_sum(root->right, sum, targetsum);

    if (l || r) return true;
    *sum -= root->val;
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int* sum = new int(0);
    return dfs_sum(root, sum, &targetSum);
}


int main() {
    TreeNode x4(7);
    TreeNode y4(2);
    TreeNode z4(1);

    TreeNode x3(11, &x4, &y4);
    TreeNode y3(13);
    TreeNode z3(4, nullptr, &z4);

    TreeNode x2(4, &x3, nullptr);
    TreeNode y2(8, &y3, &z3);
    TreeNode root(5, &x2, &y2);

    cout << hasPathSum(&root, 22);
}
