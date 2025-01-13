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

// Function to get the value of the node at a specific position from the tail
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* main_ptr = llist;
    SinglyLinkedListNode* ref_ptr = llist;

    // Move ref_ptr ahead by positionFromTail nodes
    for (int i = 0; i <= positionFromTail; ++i) {
        if (ref_ptr == nullptr) {
            return -1; // If positionFromTail is greater than the length of the list
        }
        ref_ptr = ref_ptr->next;
    }

    // Move both pointers until ref_ptr reaches the end of the list
    while (ref_ptr != nullptr) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    // main_ptr now points to the node at the required position from the tail
    return main_ptr->data;
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

    // Create a list with 5 nodes: 1 -> 2 -> 3 -> 4 -> 5
    head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(3);
    head->next->next->next = new SinglyLinkedListNode(4);
    head->next->next->next->next = new SinglyLinkedListNode(5);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Get the value of the node 2 positions from the tail (should return 3)
    int value = getNode(head, 2);
    std::cout << "Value at 2 positions from the tail: " << value << std::endl;

    // Free the allocated memory
    freeLinkedList(head);

    return 0;
}
