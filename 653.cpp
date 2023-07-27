#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// look for answer in all nodes
TreeNode* r;
bool find(int val) {
    cout << "looking for: " << val << endl;
    TreeNode* node = r;

    while (node != nullptr) {
        cout << "value: " << node->val << endl;
        if (node->val == val) return true;
        if (node->val < val) node = node->right;
        else node = node->left;
    }

    return false;
}
bool dfs(TreeNode* root, int &k) {
    if (root == nullptr) return false;
    return (((k-(root->val)) != (k/2) && find(k-(root->val))) || dfs(root->left, k) || dfs(root->right, k));
}

bool findTarget(TreeNode* root, int k) {
    r = root;
    return dfs(root, k);
}








// look by inorder traversal (sorted) using two pointers method
bool findTarget(TreeNode* root, int k) {
    vector<int> v;
    inorder(root, v);
    return findsum(v, k);
}

void inorder(TreeNode* root, vector<int> &v) {
    if (root == nullptr) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

bool findsum(vector<int> &v, int &k) {
    for (int i = 0, j = v.size()-1; i < j; ) {
        int sum = v[i] + v[j];
        if (sum == k) return true;
        if (sum > k) j--;
        else i++;
    }

    return false;
}


int main() {
    TreeNode b1(1);
    TreeNode b2(3);
    TreeNode a(2, &b1, &b2);
    cout << findTarget(&a, 4);
}







