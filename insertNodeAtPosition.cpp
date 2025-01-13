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

// Function to insert a node at a specific position in the list
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    // Create a new node with the given data
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    // If inserting at the head (position 0)
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    // Traverse to the node just before the desired position
    SinglyLinkedListNode* current = llist;
    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    // If the current node is null, the position is out of bounds
    if (current == nullptr) {
        // Handle the error appropriately (here we just return the original list)
        std::cout << "Position is out of bounds" << std::endl;
        delete newNode; // Clean up the newly created node
        return llist;
    }

    // Insert the new node at the desired position
    newNode->next = current->next;
    current->next = newNode;

    return llist;
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

    // Insert nodes at the head to create the initial list
    head = insertNodeAtPosition(head, 1, 0);
    head = insertNodeAtPosition(head, 2, 1);
    head = insertNodeAtPosition(head, 3, 2);
    head = insertNodeAtPosition(head, 4, 3);

    // Insert a node at a specific position
    head = insertNodeAtPosition(head, 5, 2);

    // Print the linked list
    printLinkedList(head);

    // Free the allocated memory
    freeLinkedList(head);

    return 0;
}
