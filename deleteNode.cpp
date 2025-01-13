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

// Function to delete a node at a specific position in the list
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    // If the list is empty, return null
    if (llist == nullptr) {
        return nullptr;
    }

    // If deleting the head node (position 0)
    if (position == 0) {
        SinglyLinkedListNode* temp = llist;
        llist = llist->next;
        delete temp;
        return llist;
    }

    // Traverse to the node just before the desired position
    SinglyLinkedListNode* current = llist;
    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    // If the current node or the next node is null, the position is out of bounds
    if (current == nullptr || current->next == nullptr) {
        std::cout << "Position is out of bounds" << std::endl;
        return llist;
    }

    // Delete the node at the desired position
    SinglyLinkedListNode* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;

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

    // Create a list with 4 nodes
    head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(3);
    head->next->next->next = new SinglyLinkedListNode(4);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Delete node at position 2
    head = deleteNode(head, 2);

    // Print the modified linked list
    std::cout << "List after deleting node at position 2: ";
    printLinkedList(head);

    // Free the allocated memory
    freeLinkedList(head);

    return 0;
}
