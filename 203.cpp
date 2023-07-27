#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    if (head->val == val) return removeElements(head->next, val);

    auto p = head;
    while (p != nullptr && p->next != nullptr) {
        if (p->next->val == val) p->next = p->next->next;
        else p = p->next;
    }

    return head;
}