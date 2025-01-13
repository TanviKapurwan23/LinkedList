#include<iostream>
#include<stdlib.h>
using namespace std;



int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

int Rcount(struct Node *p){
    if(p!=NULL){
        return Rcount(p->next) + 1;  
    } else{
        return 0;
    }
}

int sum(struct Node *p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p){
    if(p==NULL)
    return 0;
    else
     return RSum(p->next)+p->data;
}

int main(){
    int A[] = {3,5,7,10,15};
    create(A,5);
    printf("Length is %d \n \n ", count(first));
    printf("Sum is %d \n \n", sum(first));


    return 0 ;
}