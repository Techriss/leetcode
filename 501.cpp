#include <iostream>
#include <vector>
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

// using dfs & map
vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> m;
    dfs(root, m);
    int max = 0;
    vector<int> v;

    for (auto x : m) {
        if (x.second == max) v.push_back(x.first);
        else if (x.second > max) {
            v.erase(v.begin(), v.end());
            max = x.second;
            v.push_back(x.first);
        }
    }

    return v;
}

// using inorder traversal counting
vector<int> findMode(TreeNode* root) {
    vector<int> v;
    int maxf = 0, currf = 0, prev = INT_MIN;
    inorder(root, v, maxf, currf, prev);
    return v;
}

void dfs(TreeNode* root, unordered_map<int, int> &m) {
    if (root == nullptr) return;
    m[root->val]++;
    dfs(root->left, m);
    dfs(root->right, m);
}

void inorder(TreeNode* root, vector<int> &v, int& max_freq, int& curr_freq, int& prev) {
    if (root == nullptr) return;
    inorder(root->left, v, max_freq, curr_freq, prev);

    int curr = root->val;
    if (curr == prev) curr_freq++;
    else curr_freq = 1;

    if (curr_freq == max_freq) v.push_back(curr);
    else if (curr_freq > max_freq) {
        v.clear();
        v.push_back(curr);
        max_freq = curr_freq;
    }

    prev = curr;
    inorder(root, v, max_freq, curr_freq, prev);
}