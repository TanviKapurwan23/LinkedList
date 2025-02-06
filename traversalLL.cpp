#include<iostream>
using namespace std;

struct Node{
    int data;                     // Data
    Node * next;                  // Pointer to next node
    Node(int x){                  // Constructor
        data = x;
        next = NULL;
    }
};

void printList(Node * head){     // Function to print the linked list
    Node * curr = head;          // Pointer to the head node
    while(curr != NULL){         // Traverse the linked list
        cout<<curr->data<<" ";   // Print the data of the current node
        curr = curr->next;       // Move to the next node
    }
}

void printList2(Node *head){
    while(head != NULL){         // Traverse the linked list
        cout<<head->data<<" ";   // Print the data of the current node
        head = head->next;       // Move to the next node
    }
}

int main(){
    Node * head = new Node(10);      // Create the head node
    printList2(head);                 // Print the linked list
    cout<<endl;
    printList2(head);
    return 0;
}