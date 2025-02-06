#include<iostream>
using namespace std;

// Node definition
struct Node{
    int data;                // integer data stored in the node
    Node* next;              // pointer to the next node in the list
    Node(int x){             // constructor to initialize node with data
        data = x;
        next = NULL;         // next is set to NULL initially
    }
};

// Function to delete the head node of the linked list
Node* delHead(Node* head){         // deleting the head O(1)
    if(head == NULL){              // If list is empty (head is NULL)
        return NULL;               // Return NULL since there's nothing to delete
    }else{
        Node* temp = head->next;      // Store the next node after the head
        delete head;                  // Delete the current head to free memory
        return temp;                  // Return the new head (next node)
    }
}

// Function to print the list
void printList(Node* head){         // printing the list O(N)
    Node* temp = head;
    while(temp != NULL){            // Loop through the list until the end
        cout << temp->data << " ";   // Print the data of the current node
        temp = temp->next;           // Move to the next node
    }
    cout << endl;                   // Print a newline at the end of the list
}

int main(){
    // Create a linked list with nodes 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);  // Print the original list

    // Delete the head node and update the head pointer
    head = delHead(head);

    cout << "List after deleting the head: ";
    printList(head);  // Print the list after deleting the head

    while(head != NULL){  
        Node* temp = head;   // Store the current node
        head = head->next;    // Move to the next node
        delete temp;          // Delete the current node to free memory
    }

    return 0;
}



// deleteting the head : O(1)
// Time Complexity is O(1), Constant Time
// because it only invloves a few pointer manipulations and one delete operation
