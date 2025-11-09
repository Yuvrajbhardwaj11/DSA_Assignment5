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
    ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
        ListNode *p = a, *q = b;
        while (p != q) {
          if (p) p = p->next;
          else p = b;
          if (q) q = q->next;
          else q = a;






        }
        return p;
    }
};

int main() {
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);

    a1->next = a2;
    a2->next = c1;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    c1->next = c2;
    c2->next = c3;

    Solution s;
    ListNode* res = s.getIntersectionNode(a1, b1);

    if (res) cout << res->val;
    else cout << "null";
}
