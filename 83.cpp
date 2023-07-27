#include <iostream>
using namespace std;

struct ListNode {     
    int val;
    ListNode *next;     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    auto h = head;
    while (h != nullptr && h->next != nullptr) {
        while (h->next != nullptr && h->val == h->next->val) {
            h->next = h->next->next;
        }
        h = h->next;
    }

    return head;
}