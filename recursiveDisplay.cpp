#include<iostream>
using namespace std;
   
struct Node{                 // Node structure
    int data;                // Data part
    Node * next;             // Pointer to next node
    Node(int x){             // Constructor
        data = x;
        next = NULL;
    }
};

void rPrint(Node * head){              // Recursive function to display linked list
    if(head == NULL){                 // Base case if head is NULL
        return;
    }
    cout<<head->data<<" ";            // Print data of current node
    rPrint(head->next);               // Call the function for next node
}

int main(){
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    rPrint(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) for recursive stack 
// n is the number of nodes in the linked list
//  Iterative approach is better than recursive approach for displaying linked list

// Output: 10 20 30 40

// Note: Recursive approach is not recommended for displaying linked list
// as it uses extra space for recursive stack.