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


bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    if (!isSameTree(p->left, q->left)) return false;
    if (p->val != q->val) return false;
    if (!isSameTree(p->right, q->right)) return false;

    return true;
}

void invert(TreeNode* root) {
    if (root == nullptr) return;

    auto tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invert(root->left);
    invert(root->right);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    invert(root->right);
    return isSameTree(root->left, root->right);
}

int main() {

    TreeNode n3(3);
    TreeNode n2(2, );
    TreeNode n1(1, &n2, &n2);

    cout << isSymmetric(&n1) << endl;
}