#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int maxd = 0;
    maxdfs(root, maxd);
    return maxd + 1;
}

int maxdfs(Node* root, int &maxd) {
    if (root == nullptr || root->children.empty()) return 0;
    int mx = 0;
    for (auto c : root->children) {
        mx = max(mx, maxdfs(c, maxd)+1);
    }

    maxd = max(maxd, mx);
    return mx;
}