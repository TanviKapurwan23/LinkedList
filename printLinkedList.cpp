#include<iostream>
using namespace std;

struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode* next;
};


// function to print elements of linked list

void printLinkedlist(SinglyLinkedListNode* head){
    SinglyLinkedListNode* current = head;
    while(current != nullptr){
        cout<<current->data<<endl;
        current = current->next;
    }
    cout<<endl;
}

// to create a new node

SinglyLinkedListNode* createNode(int data){
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}


// append node at the end of linked list

void appendNode(SinglyLinkedListNode*& head, int data){
    SinglyLinkedListNode* newNode = createNode(data);
    if(head == nullptr){
        head = newNode;
    } else{
        SinglyLinkedListNode* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
}

int main(){
   SinglyLinkedListNode* head = nullptr;

   appendNode(head, 1);
   appendNode(head, 2);
   appendNode(head, 3);
   appendNode(head, 4);
   appendNode(head, 5);

   cout<<"Linked List";
   printLinkedlist(head);


   return 0;
}