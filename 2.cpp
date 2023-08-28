#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// o(1) space
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // count the lengths
    int n1 = 0, n2 = 0;
    for (ListNode* node = l1; node != nullptr; node = node->next, ++n1);
    for (ListNode* node = l2; node != nullptr; node = node->next, ++n2);

    ListNode* bigger = n1 >= n2 ? l1 : l2;
    ListNode* smaller = n2 > n1 ? l1 : l2;
    ListNode* prev = nullptr;

    int carry = 0;


    // add all, carry
    while (bigger != nullptr) {
        int v1 = bigger->val;
        int v2 = smaller ? smaller->val : 0;
        int sum = v1 + v2 + carry;


        bigger->val = sum % 10;
        carry = sum / 10;

        prev = bigger;
        bigger = bigger->next;
        smaller = smaller ? smaller->next : smaller;
    }

    if (carry) {
        ListNode* cn = new ListNode(carry);
        prev->next = cn;
    }

    return n1 >= n2 ? l1 : l2;
}



// another solution (extra space)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode newHead(0);
    ListNode *t = &newHead;

    while(c || l1 || l2) {
        c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        t->next = new ListNode(c % 10);
        t = t->next;
        c /= 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return newHead.next;
}


// recursive
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    else if (l1 == nullptr) return l2; 
    else if (l2 == nullptr) return l1; 

    int a = l1->val + l2->val;
    ListNode *p = new ListNode(a % 10);
    p->next = addTwoNumbers(l1->next, l2->next);
    if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
    return p;
}