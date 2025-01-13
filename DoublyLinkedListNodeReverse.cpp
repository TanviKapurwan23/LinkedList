#include <iostream>

// Definition of the doubly linked list node
struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    // Constructor to initialize a new node
    DoublyLinkedListNode(int nodeData) {
        data = nodeData;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to reverse the doubly linked list
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if (llist == nullptr) {
        return nullptr;
    }

    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* temp = nullptr;

    // Traverse the list and swap the next and prev pointers
    while (current != nullptr) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev;
    }

    // Before returning, set llist to the new head of the reversed list
    if (temp != nullptr) {
        llist = temp->prev;
    }

    return llist;
}

// Utility function to print the doubly linked list from head to tail
void printDoublyLinkedList(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Utility function to print the doubly linked list from tail to head
void printDoublyLinkedListReverse(DoublyLinkedListNode* tail) {
    DoublyLinkedListNode* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Utility function to free the memory allocated for the doubly linked list
void freeDoublyLinkedList(DoublyLinkedListNode* head) {
    while (head != nullptr) {
        DoublyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    DoublyLinkedListNode* head = nullptr;
    DoublyLinkedListNode* tail = nullptr;

    // Create a list with 5 nodes: 1 <-> 2 <-> 3 <-> 4 <-> 5
    head = new DoublyLinkedListNode(1);
    head->next = new DoublyLinkedListNode(2);
    head->next->prev = head;
    head->next->next = new DoublyLinkedListNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new DoublyLinkedListNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DoublyLinkedListNode(5);
    head->next->next->next->next->prev = head->next->next->next;
    tail = head->next->next->next->next;

    // Print the original doubly linked list from head to tail
    std::cout << "Original List (head to tail): ";
    printDoublyLinkedList(head);

    // Print the original doubly linked list from tail to head
    std::cout << "Original List (tail to head): ";
    printDoublyLinkedListReverse(tail);

    // Reverse the doubly linked list
    head = reverse(head);

    // Print the reversed doubly linked list from head to tail
    std::cout << "Reversed List (head to tail): ";
    printDoublyLinkedList(head);

    // Print the reversed doubly linked list from tail to head
    tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    std::cout << "Reversed List (tail to head): ";
    printDoublyLinkedListReverse(tail);

    // Free the allocated memory
    freeDoublyLinkedList(head);

    return 0;
}
