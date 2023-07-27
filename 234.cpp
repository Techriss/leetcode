#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr->next != nullptr) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr->next = prev;
    return curr;
}

void write(ListNode* head) {
    auto h = head;
    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}


bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    int n = 1;
    for (auto h = head; h->next != nullptr; h = h->next) n++;

    int mid = n/2;
    auto midnode = head;
    for (int i = 0; i < mid; i++) {
        midnode = midnode->next;
    }
    if (n % 2 == 1) midnode = midnode->next;

    midnode = reverse(midnode);

    while (mid --> 0) {
        if (head->val != midnode->val) return false;
        head = head->next;
        midnode = midnode->next;
    }

    return true;
}



int main() {
    ListNode d(1);
    ListNode c(2, &d);
    ListNode b(1, &c);
    ListNode a(1, &b);

    cout << isPalindrome(&a) << endl;
}
