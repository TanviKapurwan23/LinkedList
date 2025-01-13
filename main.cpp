/*
 Problem with Array

 Array is of fixed size

 Difference between Array and Linked list
 we can create an array either in stack or inside heap
 Linked list is created inside heap  // dynamically we allocate the memory

 int A[5]; // stack
 int *p = new int[5];
 
 Variable size data structure
 It is more flexible than an array
 Size can grow and size can be reduced
 Easily insert and remove elements using LL
 We create linked list always inside heap
 
 
 1.What is Linked List?
 Linked list is a collection of nodes where each node contain data and pointer to the next node.
 
 
 Self Referential structure used in LL

 

 In structure everything by default is public
 In class everything by default is private


 2.What is a Node?
 3.Node structure?

 struct Node{
    int data;
    struct Node *next;
 };

 4.Create a Node?

 struct Node *p;
 p = new Node;
 
 5.Access Node?
 p->data = 10;
 p->next = 0;
 */


// Display Linked List

// display(struct Node *p){
//   while(p != NULL)
//   {
//     printf("%d", p->data);
//     p=p->next;
//   }
// }

// display(first);




