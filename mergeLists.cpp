#include<iostream>
using namespace std;

struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2){
    // if either list is empty, return the other list
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    SinglyLinkedListNode* mergedHead = nullptr;

    if(head1->data <= head2->data){
        mergedHead = head1;
        head1 = head1->next;
    } else{
        mergedHead = head2;
        head2 = head2->next;
    }

    SinglyLinkedListNode* current = mergedHead;

    while(head1!= nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            current->next = head1;
            head1 = head1->next;
        } else{
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // if one list is exhausted, append the other list
    if(head1 != nullptr){
        current->next = head1;
    } else{
        current->next = head2;
    }
    return mergedHead;
}


SinglyLinkedListNode* createNode(int data){
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

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

void printLinkedList(SinglyLinkedListNode* head){
    SinglyLinkedListNode* current = head;
    while(current != nullptr){
        cout<< current->data<<endl;
        current = current->next;
    }
    cout<<endl;
}

int main(){
   SinglyLinkedListNode* list1 = nullptr;
   SinglyLinkedListNode* list2  = nullptr;

   appendNode(list1, 1);
   appendNode(list1, 3);
   appendNode(list1, 5);

   appendNode(list2, 2);
   appendNode(list2, 4);
   appendNode(list2, 6);

   SinglyLinkedListNode* mergedList = mergeLists(list1, list2);

   cout<<"Merger Linked list"<<endl;
   printLinkedList(mergedList);

   return 0;

}