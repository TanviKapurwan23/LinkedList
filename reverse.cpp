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

// Function to reverse the linked list
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next = nullptr;

    while (current != nullptr) {
        // Save the next node
        next = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    // prev will be the new head of the reversed list
    return prev;
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

    // Create a list with 4 nodes
    head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(3);
    head->next->next->next = new SinglyLinkedListNode(4);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverse(head);

    // Print the reversed linked list
    std::cout << "Reversed List: ";
    printLinkedList(head);

    // Free the allocated memory
    freeLinkedList(head);

    return 0;
}
