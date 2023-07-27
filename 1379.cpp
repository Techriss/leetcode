#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (original == nullptr) return nullptr;
    if (original == target) return cloned;

    auto l = getTargetCopy(original->left, cloned->left, target);
    if (l != nullptr) return l;
    auto r = getTargetCopy(original->right, cloned->right, target);
    return r;
}