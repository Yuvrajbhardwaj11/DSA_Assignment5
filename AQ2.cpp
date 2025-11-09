#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head, *prev = NULL, *nxt = NULL;
        int count = 0;
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head;
            check = check->next;
        }
        while (cur && count < k) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }
        if (nxt) head->next = reverseKGroup(nxt, k);
        return prev;
    }
};

void printList(ListNode* h) {
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
}

int main() {
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* res = s.reverseKGroup(h, 2);
    printList(res);
}
