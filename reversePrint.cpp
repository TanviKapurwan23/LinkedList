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

// Function to print the linked list in reverse order using recursion
void reversePrint(SinglyLinkedListNode* llist) {
    // Base case: if the list is empty, return
    if (llist == nullptr) {
        return;
    }

    // Recursively call reversePrint on the next node
    reversePrint(llist->next);

    // Print the current node's data
    std::cout << llist->data << " ";
}

// Utility function to print the linked list (normal order)
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

    // Print the linked list in reverse order
    std::cout << "Reversed List: ";
    reversePrint(head);
    std::cout << std::endl;

    // Free the allocated memory
    freeLinkedList(head);

    return 0;
}
