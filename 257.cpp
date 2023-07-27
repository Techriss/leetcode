#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    if (root == nullptr) return paths;
    dfs_paths(root, paths, "");
    return paths;
}

void dfs_paths(TreeNode* root, vector<string> &paths, string curr_substr) {
    if (root->left == nullptr && root->right == nullptr) paths.push_back(curr_substr + to_string(root->val)); 
    else {
        if (root->left != nullptr) dfs_paths(root->left, paths, curr_substr + to_string(root->val) + "->");
        if (root->right != nullptr) dfs_paths(root->right, paths, curr_substr + to_string(root->val) + "->");
    }
}