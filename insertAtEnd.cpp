#include<iostream>
using namespace std;

// structure definition for a Node in the linked list
struct Node{            
    int data;                    // data stored in the node
    Node *next;                  //pointer to the next in the linked list
    Node(int x){                 // constructor
        data = x;
        next = NULL;
    }
};

// function to insert a node at the end of the linked list
Node *insertEnd(Node *head, int x){
   Node *temp = new Node(x);       // creating a new node with the given value
   if(head == NULL){               // if list is empty, new node becomes the head
    return temp;
   }
   Node *curr = head;             // start from the head of linked list
   while(curr->next != NULL){     // traverse to the last node
    curr = curr->next;
   }
   curr->next = temp;              // link the last node to the new node

   return head;                    // return the head of the updated linked list
}

// function to print linked list
void printList(Node *head){         
    Node *curr = head;            // start from the end
    while(curr != NULL){          // Traverse the linked list until the end
        cout<<curr->data<<"->";   // print the data of the current node
        curr = curr->next;        // move to current node
    }
    cout<<"NULL"<<endl;           // indicate end of linked list
}     

int main(){
   Node *head = NULL;         // Initializing an empty linked list
   // Inserting elements at the end of the linked list
   head = insertEnd(head, 10);  
   head = insertEnd(head, 20);
   head = insertEnd(head, 30); 
   //calling the function to print the linked list
   printList(head);
   return 0;
}

/*
Best Case (Empty List):
If head == NULL, we directly return the new node.
Time Complexity = O(1) (Constant time)

Worst Case (Non-Empty List):

We traverse the entire linked list to find the last node.
Since there are N nodes, the loop runs O(N) times.
Time Complexity = O(N) (Linear time)

Overall Complexity for Multiple Insertions:
If we insert M elements into the linked list using this function, the total time complexity becomes:

O(1) + O(2) + O(3) + ... + O(M) = O(M²)
O(M²) is inefficient for large inputs.

*/