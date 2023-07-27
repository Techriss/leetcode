#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// *2 + val
int getDecimalValue(ListNode* head) {
    int d = 0;
    while (head) {
        d = (d*2 + (head->val));
        head = head->next;
    }

    return d;
}


// same but bitwise
int getDecimalValue(ListNode* head) {
    int d = 0;
    while (head) {
        d <<= 1;
        d |= head->val;
        head = head->next;
    }

    return d;
}


// recursive
int getDecimalValue(ListNode* head, int res = 0) {
    return head ? getDecimalValue(head->next, res * 2 + head->val) : res;
}