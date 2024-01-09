#include <iostream>

#include <stdio.h>

using namespace std;

class Node{
    int item;
    Node *next;

};
class SLL{

    private:
        Node *start;
    
    
    public:

        SLL();

        void insertAtStart(int); // sirf data btaye
        void insertAtLast(int); // sift data btaye
        void insertAfter(Node *, int); // node ke baad insert kre
        
        
        Node* search(int);  // data search kre



        void deleteFirst();
        void deleteLast();
        void deleteAt(int);

};

// constructor

SLL:: SLL(){
    start = NULL;
}

void SLL :: insertAtStart(int data){

   // naya node insert krne ke liye pehle node bnana pdega
   // uske baad use store krna pdega bz pointer he

   Node *n = new Node();

   // ya toh list empty hogi

   n->item = data;
   n->next = start;

   start = n;

}


void SLL :: insertAtLast(int data){

    Node *n = new Node();

    n->item = data;
    n->next = NULL; // bz last me judega


    Node *t = new Node();

    // jode

    if(start == NULL){
        start = n;
    }else{ // agr list empty na ho, then jab tak next me empty nahin
    // milta tab tak traverse kro, jab null mile 
         t = start;

         while(t -> next != NULL){
            t = t->next;
            
            t => next = n;
         }
    }

}


void SLL :: insertAfter(Node *t, int data){

Node *n;
if(t != NULL){

    n = new Node();
    n => item = data;
    t -> next = temp -> next;
    t -> next = n;
}
}


void SLL :: deleteFirst(){
Node *r 
    if(start != NULL){
        r=start;

        start = start -> next;

        delete r;
    }
}


void SLL :: deleteLast(){
    Node *t;

    if(start != NULL){
        if(start -> next == NULL){
            delete start;
            start = NULL;
        }

        else{
            t = start;

            while (r -> next -> next != NULL){
                        r = r->next;
            }
            delete r -> next;

            r -> next = NULL;
        }
    }

}


void SLL :: deleteAt(int data){

    Node *r, *t;

    if(start){
     r = start;
     t = NULL;

     while(r){
        if(r -> item == data){
            break;
        }
        t = r;
        r = r -> next;
     }

     if(r){
        if(r == NULL){
            start = r -> next;
            delete r;
        }
        else{
            t -> next = r -> next;
            delete r;
        }
     }
    }
}

SLL::~SLL(){
    while(start){
        deleteFirst();
    }
}
Node* SLL::search(int data){

    Node *t = start;

    while(t){

        if(t -> item == data){
            return t;
        }

        t = t -> next;

        
    }

    return NULL;
}