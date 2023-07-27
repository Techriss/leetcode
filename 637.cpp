#include <iostream>
#include <vector>
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

vector<double> averageOfLevels(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    vector<double> v;

    q.push({root, 0});
    long long sum = 0, level = 0, count = 0;

    while (!q.empty()) {
        auto x = q.front();
        q.pop();

        if (level == x.second) {
            sum += x.first->val;
            count++;
        }
        else {
            v.push_back((double)sum/count);
            sum = x.first->val;
            count = 1;
        }

        if (x.first->left) q.push({x.first->left, x.second+1});
        if (x.first->right) q.push({x.first->right, x.second+1});
        level = x.second;
    }

    v.push_back((double)sum/count);

    return v;
}