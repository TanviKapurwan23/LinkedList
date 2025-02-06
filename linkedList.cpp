#include<iostream>
using namespace std;

struct Node{
    int data;         // data
    Node *next;        // pointer to next node

    Node(int x){       // constructor
        data = x;
        next = NULL;
    }
};

int main(){
    Node *head = new Node(10);  // head node
    head->next = new Node(20);  // second node
    head->next->next = new Node(30);  // third node

    cout<<head->data<<"-->";  // print head node
    cout<<head->next->data<<"-->";  // print second node
    cout<<head->next->next->data<<"-->";  // print third node

    return 0;
}

// shorter implementation 