#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

void insert(Node*& head, int v) {
    Node* n = new Node(v);
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) cout << slow->data << endl;
}

int main() {
    Node* head = NULL;
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> v; insert(head, v); }
    findMiddle(head);
}
