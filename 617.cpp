#include <iostream>
#include <queue>
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


TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1) return root2;
    if (!root2) return root2;
    root1->val += root2->val;

    if (root2->left) root1->left = mergeTrees(root1->left, root2->left);
    if (root2->right) root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}








TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2) return nullptr;
    int val1 = t1? t1->val:0;
    int val2 = t2? t2->val:0;
    
    TreeNode* t = new TreeNode(val1+val2);
    t->left = mergeTrees(t1?t1->left:nullptr,t2?t2->left:nullptr);
    t->right = mergeTrees(t1?t1->right:nullptr,t2?t2->right:nullptr);
    return t;
}













TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2) return nullptr;
    if(!t1 || !t2) return t1? t1:t2;

    queue<TreeNode*> q1,q2;
    q1.push(t1);
    q2.push(t2);
    
    while(!q1.empty() && !q2.empty()){
        TreeNode* c1(q1.front());
        TreeNode* c2(q2.front());
        q1.pop();
        q2.pop();
        
        c1->val+=c2->val;
        
        if (!c1->left && c2->left) c1->left = c2->left;
        else if (c1->left && c2->left) { q1.push(c1->left); q2.push(c2->left); }
        
        if (!c1->right && c2->right) c1->right = c2->right;
        else if (c1->right && c2->right) { q1.push(c1->right); q2.push(c2->right); }
    }
    return t1;
}




















