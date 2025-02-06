#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* insertPos(Node *head, int pos, int data){
    Node *temp = new Node(data);           // create new node

    if(pos == 1){                          //inserting at the beginning
        temp->next = head;
        return temp;                       // new head
    }

    Node *curr = head;                            // traverse to the node before
    for(int i=1; i<=pos-2 && curr != NULL; i++){  // insertion point
        curr = curr->next;
    }
    // if position is greater than the number of nodes
    if(curr == nullptr){
        cout<<"Position out of bounds!"<<endl;
        delete temp;    // prevent memory leak
        return head;
    }

    temp->next = curr->next;          // insert new node at the given position
    curr->next = temp;

    return head;
    
}

// function to print linked list
void printList(Node* head){
    while(head != nullptr){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}


int main(){
    Node* head = nullptr;

    head = insertPos(head, 1, 10);
    head = insertPos(head, 2, 20);
    head = insertPos(head, 1, 5); // insert at head
    head = insertPos(head, 3, 15); // insert at position 3

    printList(head);


    return 0;
}

// Time Complexity : O(N)
// Space Complexity: O(1)