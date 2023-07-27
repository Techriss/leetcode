#include <iostream>
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


// either dfs with pointers
bool get_depth(TreeNode* root, int target, int &tdepth, int &tparent, int parent = 0, int depth = 0) {
    if (root == nullptr) return false;
    if (root->val == target) { tdepth = depth; tparent = parent; return true; }
    return get_depth(root->left, target, tdepth, tparent, root->val, depth+1) || get_depth(root->right, target, tdepth, tparent, root->val, depth+1);
}

bool isCousins(TreeNode* root, int x, int y) {
    int d1, d2, p1, p2;
    get_depth(root, x, d1, p1);
    get_depth(root, y, d2, p2);
    return d1 == d2 && p1 != p2;
}




// or bfs
bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*>q;
    q.push(root);

    while (!q.empty()) {
        // for every level
        int n = q.size();
        bool f1 = false, f2 = false;

        // dequeue entire level while enqueing a new one
        while (n --> 0) {
            TreeNode* tmp = q.front();
            q.pop();

            //if values found
            if (tmp->val == x) f1 = true;
            if (tmp->val == y) f2 = true;
            
            //checking if parent is same
            // if anywhere we find matching nodes with same parent, return false instantly
            if (tmp->left && tmp->right) {
                if ((tmp->left->val == x && tmp->right->val == y) || (tmp->left->val == y && tmp->right->val == x))
                    return false;
            }

            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        
        if (f1 && f2) return true;
    }
    
    return false;
}