#include<iostream>

struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode* next;

    //Constructor to initialize a new node

    SinglyLinkedListNode(int nodeData){
        data = nodeData;
        next = nullptr;
    }
};


// function to insert a node at the head of the list

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data){

    // create a new node 
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    // set the next pointer to the new node to the current head
    newNode ->next = llist;
    

    // UPDATE THE HEAD TO BE THE NEW NODE
    return newNode;
}


// Function to print linked list

void printLinkedList(SinglyLinkedListNode* head){
    SinglyLinkedListNode* current = head;
    while(current != nullptr){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<std::endl;
}

// function to free the memory allocated for the linked list

void freeLinkedList(SinglyLinkedListNode* head){
    while(head != nullptr){
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    SinglyLinkedListNode* head = nullptr;

    head = insertNodeAtHead(head, 1);
    head = insertNodeAtHead(head, 2);
    head = insertNodeAtHead(head, 3);
    head = insertNodeAtHead(head, 4);
    head = insertNodeAtHead(head, 5);

    printLinkedList(head);

    freeLinkedList(head);

    return 0;
}