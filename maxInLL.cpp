#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* first = nullptr;

void create(int A[], int n) {
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

int Max(Node *p) {
    int max = INT32_MIN;
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int MaxRecursive(Node *p) {
    if (p == nullptr) {
        return INT32_MIN;
    }
    int x = MaxRecursive(p->next);
    return (x > p->data) ? x : p->data;
}

int main() {
    int A[] = {3, 5, 7, 10, 15, 8, 12, 20};
    create(A, 8);
    cout << "Max is " << Max(first) << endl;
    cout << "Max (Recursive) is " << MaxRecursive(first) << endl;
    return 0;
}
