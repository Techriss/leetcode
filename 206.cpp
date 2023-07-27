#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    auto prev = head;
    auto curr = head->next;
    auto next = head->next->next;

    while (curr != nullptr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next != nullptr) next = next->next;
    }

    head->next = nullptr;

    return prev;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}