#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// O(N) SPACE
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> seen;
    if (headA == nullptr || headB == nullptr) return nullptr;

    while (headA != nullptr) {
        seen.insert(headA);
        headA = headA->next;
    }

    while (headB != nullptr) {
        if (seen.find(headB) != seen.end()) return headB;
        headB = headB->next;
    }

    return nullptr;
}

// O(1) SPACE
ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    int al = 0, bl = 0;

    auto headA2 = headA;
    while (headA2 != nullptr) {
        headA2 = headA2->next;
        al++;
    }

    auto headB2 = headB;
    while (headB2 != nullptr) {
        headB2 = headB2->next;
        bl++;
    }

    ListNode *h1, *h2;
    if (al > bl) {
        h1 = headA;
        while (al != bl) {
            h1 = h1->next;
            al--;
        }
        h2 = headB;
    }
   else {
        h1 = headB;
        while (al != bl) {
            h1 = h1->next;
            bl--;
        }
        h2 = headA;
    }

    while (h1 != nullptr && h2 != nullptr && h1 != h2) {
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1;
}