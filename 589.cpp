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

vector<int> preorder(Node* root) {
    vector<int> v;
    preorder(root, v);
    return v;
}

void preorder(Node* root, vector<int> &v) {
    if (root == nullptr) return;
    v.push_back(root->val);
    for (auto c : root->children) preorder(c, v);
}