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

// serialization
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    string tree, subtree;
    postorder(root, tree);
    postorder(subRoot, subtree);

    return tree.find(subtree) != string::npos;
}

void postorder(TreeNode* root, string &res) {
    if (root == nullptr) { res += "N"; return; }
    postorder(root->left, res);
    postorder(root->right, res);
    res += to_string(root->val);
}

void preorder(TreeNode* root, string &res) {
    if (root == nullptr) { res += "N"; return; }
    res += "#";
    res += to_string(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}





// recursive
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root || !subRoot)
        return false;
    
    if (isSameTree(root, subRoot))
        return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}




// recursive but only for same depth
vector<TreeNode*> nodes;

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;

    getDepth(s, getDepth(t, -1));

    for (TreeNode* n : nodes)
        if (identical(n, t))
            return true;

    return false;
}

int getDepth(TreeNode* r, int d) {
    if (!r)
        return -1;

    int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

    // Check if depth equals required value
    // Require depth is -1 for tree t (only return the depth, no push)
    if (depth == d)
        nodes.push_back(r);

    return depth;
}

bool identical(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b || a->val != b->val) return false;

    return identical(a->left, b->left) && identical(a->right, b->right);
}