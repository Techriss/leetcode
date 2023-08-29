#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    auto *head2 = head->next;
    ListNode* prev = nullptr;

    while (head && head->next) {
        auto *nextone = head->next->next;
        if (prev) prev->next = head->next;
        head->next->next = head;
        head->next = nextone;
        prev = head;
        head = head->next;
    }

    return head2;
}


ListNode* swapPairs(ListNode* head) {
    ListNode* sentinel = new ListNode(0, head);
    auto *prev = sentinel, *curr = head;

    while (curr && curr->next) {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = curr->next;
    }

    return sentinel->next;
}