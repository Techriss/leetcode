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

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = new TreeNode();
    int l = 0, r = nums.size() - 1;
    helper_convert(nums, l, r, root);
}

void helper_convert(vector<int>& nums, int l, int r, TreeNode* root) {
    if (l > r) return;

    int mid = (l+r)/2;
    root->val = nums[mid];

    if (l == r) return;

    TreeNode* n1 = new TreeNode();
    TreeNode* n2 = new TreeNode();
    root->left = n1;
    root->right = n2;

    if (l > mid-1) root->left = nullptr;
    if (mid+1 > r) root->right = nullptr;

    helper_convert(nums, l, mid-1, root->left);
    helper_convert(nums, mid+1, r, root->right);
}

