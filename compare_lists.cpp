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

// Function to compare two singly linked lists for equality
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // Traverse both lists simultaneously
    while (head1 != nullptr && head2 != nullptr) {
        // If data of current nodes is not equal, lists are not equal
        if (head1->data != head2->data) {
            return false;
        }

        // Move to the next nodes in both lists
        head1 = head1->next;
        head2 = head2->next;
    }

    // If one list has ended but the other hasn't, they are not equal
    if (head1 != nullptr || head2 != nullptr) {
        return false;
    }

    // Both lists have ended and all nodes had equal data
    return true;
}

// Utility function to create a singly linked list from an array
SinglyLinkedListNode* createLinkedListFromArray(int arr[], int size) {
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;

    for (int i = 0; i < size; ++i) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// Utility function to free the memory allocated for the singly linked list
void freeLinkedList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create two lists for testing
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 4};
    SinglyLinkedListNode* head1 = createLinkedListFromArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
    SinglyLinkedListNode* head2 = createLinkedListFromArray(arr2, sizeof(arr2) / sizeof(arr2[0]));

    // Compare the lists and print the result
    bool isEqual = compare_lists(head1, head2);
    std::cout << "Lists are " << (isEqual ? "equal" : "not equal") << std::endl;

    // Free the allocated memory
    freeLinkedList(head1);
    freeLinkedList(head2);

    return 0;
}
