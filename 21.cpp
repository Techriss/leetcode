#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode* prehead = new ListNode();
    ListNode* tail = prehead;

    ListNode* l1 = list1;
    ListNode* l2 = list2;

    while (l1 != nullptr && l2 != nullptr) {
        ListNode* newnode = new ListNode();

        if (l1->val < l2->val) {
            newnode->val = l1->val;
            l1 = l1->next;
        }
        else {
            newnode->val = l2->val;
            l2 = l2->next;
        }

        tail->next = newnode;
        tail = tail->next;
    }

    if (l1 == nullptr) {
        tail->next = l2;
    }

    if (l2 == nullptr) {
        tail->next = l1;
    }

    return prehead->next;
}

int main() {
    ListNode la1(1);
    ListNode la2(2);
    ListNode la3(4);
    ListNode lb1(1);
    ListNode lb2(3);
    ListNode lb3(5);

    la2.next = &la3;
    la1.next = &la2;
    lb2.next = &lb3;
    lb1.next = &lb2;

    ListNode x2;

    
    auto h = mergeTwoLists(&la1, &lb1);
    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }
}
