#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// idea: we can simply get the length (1st pass), and search for length-n (2nd pass) 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    for (auto *node = head; node != nullptr; ++len, node = node->next);

    int tbr = len - n;
    if (tbr == 0) return head->next;
    auto *node = head;
    for (int i = 0; i < tbr-1; i++) node = node->next;

    node->next = node->next->next;
    return head;
}


// but how to do it in 1 pass?
// we can use memory (O(len)) to store every node and easily access the (len-n)th one
// we can use memory (O(n+1)) to store last n nodes, overwriting circularly oldest nodes with the newest
// or use fast and slow



// with sentinel
ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto *new_head = new ListNode(0, head);
    auto *fast = new_head, *slow = new_head;

    // first, we make space between fast and slow equal to n
    while (n --> 0) fast = fast->next;

    // then, we move them both simultaneously, so that fast is at the end, and the space between is preserved,
    // so slow is nth from the end
    while (fast->next) fast = fast->next, slow = slow->next;

    slow = slow->next;
    return new_head->next;
}

// without sentinel
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    while (n --> 0) fast = fast->next;

    // if after going n times forward, we reached the end, nth is the first node
    if (!fast) return head->next;

    while (fast->next) fast = fast->next, slow = slow->next;
    slow->next = slow->next->next;
    return head;
}

/*
    n = 2

        1, 2, 3, 4, 5, 6
    ^^

        1, 2, 3, 4, 5, 6
    ^      ^

        1, 2, 3, 4, 5, 6
                ^     ^

*/