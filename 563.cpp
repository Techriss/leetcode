#include <iostream>
#include <unordered_map>
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


int dfssum(TreeNode* root, unordered_map<TreeNode*, int> &sum) {
    if (root == nullptr) return sum[root] = 0;
    if (root->left == nullptr && root->right == nullptr) return (sum[root] = root->val);
    return sum[root] = dfssum(root->left, sum) + dfssum(root->right, sum) + root->val;
}

int dfstilt2(TreeNode* root, unordered_map<TreeNode*, int> &sum) {
    if (root == nullptr) return 0;

    return abs(sum[root->left] - sum[root->right]) + dfstilt2(root->left, sum) + dfstilt2(root->right, sum);
}

int findTilt(TreeNode* root) {
    unordered_map<TreeNode*, int> sum;
    dfssum(root, sum);
    return dfstilt2(root, sum);
}




// all in one
int tiltSum = 0;
int findTilt(TreeNode* root) {
    DFS(root);
    return tiltSum;
}
int DFS(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftSum = DFS(root->left);
    int rightSum = DFS(root->right);

    tiltSum += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
}











int main() {
    TreeNode n6(7);
    TreeNode n5(5);
    TreeNode n4(3);
    TreeNode n3(9, nullptr, &n6);
    TreeNode n2(2, &n4, &n5);
    TreeNode n1(4, &n2, &n3);

    int res = 0;
    cout << findTilt(&n1);
}
