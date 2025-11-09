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
    void removeLoop(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) return;
        slow = head;
        if (slow == fast) {
            while (fast->next != slow) fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
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

    h->next->next->next->next->next = h->next; 

    Solution s;
    s.removeLoop(h);
    printList(h);
}
