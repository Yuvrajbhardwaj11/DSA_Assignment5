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
    ListNode* rotateLeft(ListNode* head, int k) {
        if (!head || !head->next || k == 0) 
          return head;
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        k %= n;
        if (k == 0)
          return head;
        ListNode* temp = head;
        for (int i = 1; i < k; i++)
          temp = temp->next;
        ListNode* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        return newHead;
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
    ListNode* res = s.rotateLeft(h, 2);
    printList(res);
}
