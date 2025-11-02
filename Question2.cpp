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

void countAndDelete(Node*& head, int key) {
    int c = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        c++;
    }
    Node* t = head;
    while (t && t->next) {
        if (t->next->data == key) {
            Node* d = t->next;
            t->next = t->next->next;
            delete d;
            c++;
        } else t = t->next;
    }
    cout << "Count: " << c << endl;
    t = head;
    while (t) {
        cout << t->data;
        if (t->next) cout << "->";
        t = t->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, v, key;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> v; insert(head, v); }
    cin >> key;
    countAndDelete(head, key);
}
