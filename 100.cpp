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


int main() {
    TreeNode n2(1);
    TreeNode n1(1, &n2, nullptr);

    TreeNode n4(1);
    TreeNode n3(1, &n4, nullptr);

    cout << isSameTree(&n1, &n3) << endl;
}