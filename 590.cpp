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

vector<int> postorder(Node* root) {
    vector<int> v;
    postorder(root, v);
    return v;
}

void postorder(Node* root, vector<int> &v) {
    if (root == nullptr) return;
    for (auto c : root->children) postorder(c, v);
    v.push_back(root->val);
}


// iterative with queue ...