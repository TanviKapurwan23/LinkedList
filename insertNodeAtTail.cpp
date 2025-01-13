#include <iostream>

// Definition of the singly linked list node
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    // Constructor to initialize a new node
    SinglyLinkedListNode(int nodeData) {
        data = nodeData;
        next = nullptr;
    }
};

// Function to insert a node at the tail of the list
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    // Create a new node with the given data
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the list
    SinglyLinkedListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Update the last node's next pointer to point to the new node
    current->next = newNode;

    // Return the head of the list
    return head;
}

// Utility function to print the linked list
void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Utility function to free the memory allocated for the linked list
void freeLinkedList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    SinglyLinkedListNode* head = nullptr;

    // Insert nodes at the tail
    head = insertNodeAtTail(head, 1);
    head = insertNodeAtTail(head, 2);
    head = insertNodeAtTail(head, 3);
    head = insertNodeAtTail(head, 4);

    // Print the linked list
    printLinkedList(head);

    // Free the allocated memory
    freeLinkedList(head);

    return 0;
}
