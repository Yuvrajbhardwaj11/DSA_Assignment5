#include <iostream.h>
using namespace std;

struct Node {
    int coeff, pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(NULL) {}
};

Node* addPolynomial(Node* h1, Node* h2) {
    Node* d = new Node(0, 0);
    Node* t = d;
    while (h1 && h2) {
        if (h1->pow > h2->pow) {
            t->next = new Node(h1->coeff, h1->pow);
            h1 = h1->next;
        } else if (h1->pow < h2->pow) {
            t->next = new Node(h2->coeff, h2->pow);
            h2 = h2->next;
        } else {
            t->next = new Node(h1->coeff + h2->coeff, h1->pow);
            h1 = h1->next;
            h2 = h2->next;
        }
        t = t->next;
    }
    while (h1) {
        t->next = new Node(h1->coeff, h1->pow);
        h1 = h1->next;
        t = t->next;
    }
    while (h2) {
        t->next = new Node(h2->coeff, h2->pow);
        h2 = h2->next;
        t = t->next;
    }
    return d->next;
}

void printList(Node* h) {
    while (h) {
        cout << "[" << h->coeff << "," << h->pow << "] ";
        h = h->next;
    }
    cout << endl;
}

int main() {
    Node* h1 = new Node(5, 2);
    h1->next = new Node(4, 1);
    h1->next->next = new Node(2, 0);

    Node* h2 = new Node(5, 1);
    h2->next = new Node(5, 0);

    Node* res = addPolynomial(h1, h2);
    printList(res);
}
