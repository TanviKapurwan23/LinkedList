#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {  // Constructor to initialize node with data
        data = x;
        next = NULL;
    }
};

Node *delLast(Node* head){
    // case 1: // if list is empty
    if(head == NULL) return NULL; 

    // case 2: if there's only one node in linked list
    if(head->next == NULL){       
        delete head;
        return NULL;
    }

    // case 3: if there are more than 1 node in the list
    Node *curr = head;
    // traverse the list until the second-to-last node
    while(curr->next->next != NULL){   
        curr = curr->next;
    }

    // now curr point to the seconf-to-last-node
    delete curr->next;
    curr->next = NULL;
    return head;     // return the modified list
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    // Delete the last node
    delLast(head);


    cout << "List after deleting the last node: ";
    printList(head);

    // Clean up remaining nodes
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
