#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

void insertAtBeginning(Node*& head, int v) {
    Node* n = new Node(v);
    n->next = head;
    head = n;
}

void insertAtEnd(Node*& head, int v) {
    Node* n = new Node(v);
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void insertBefore(Node*& head, int key, int v) {
    if (!head) return;
    if (head->data == key) { insertAtBeginning(head, v); return; }
    Node* t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (t->next) {
        Node* n = new Node(v);
        n->next = t->next;
        t->next = n;
    }
}

void insertAfter(Node*& head, int key, int v) {
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (t) {
        Node* n = new Node(v);
        n->next = t->next;
        t->next = n;
    }
}

void deleteFromBeginning(Node*& head) {
    if (!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteFromEnd(Node*& head) {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* t = head;
    while (t->next->next) t = t->next;
    delete t->next;
    t->next = NULL;
}

void deleteSpecific(Node*& head, int key) {
    if (!head) return;
    if (head->data == key) { deleteFromBeginning(head); return; }
    Node* t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (t->next) {
        Node* d = t->next;
        t->next = t->next->next;
        delete d;
    }
}

void search(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) { cout << pos << endl; return; }
        head = head->next;
        pos++;
    }
    cout << -1 << endl;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int c, v, k;
    do {
        cin >> c;
        switch (c) {
            case 1: cin >> v; insertAtBeginning(head, v); break;
            case 2: cin >> v; insertAtEnd(head, v); break;
            case 3: cin >> k >> v; insertBefore(head, k, v); break;
            case 4: cin >> k >> v; insertAfter(head, k, v); break;
            case 5: deleteFromBeginning(head); break;
            case 6: deleteFromEnd(head); break;
            case 7: cin >> k; deleteSpecific(head, k); break;
            case 8: cin >> k; search(head, k); break;
            case 9: display(head); break;
        }
    } while (c != 0);
}
