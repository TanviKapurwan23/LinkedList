#include<iostream>
using namespace std;

struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode* next;
};


// Function to find the length of linked list

int getLength(SinglyLinkedListNode* head){
    int length = 0;
    while(head != nullptr){
        length++;
        head = head->next;
    } 
    return length;
}


int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2){
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    if(length1 > length2){
        
    }

}