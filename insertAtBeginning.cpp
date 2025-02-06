#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* insertAtBeginning(Node* head, int x){    // O(1)
    Node* temp = new Node(x);                  // temp is the new node
    temp->next = head;                         // temp's next is head
    return temp;                               // temp is the new head
}


int main(){
    Node* head = NULL;
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<endl; // 10 20 30

    return 0;
}

// Output: 10 20 30

//  10 -> 20 -> 30 -> NULL

// Time Complexity: O(1)
// Space Complexity: O(1)

// Printed in reverse order because we are inserting at the beginning.

// If we insert at the end, we will get the output in the same order as we inserted.

// If we insert at the beginning, we will get the output in reverse order as we inserted.