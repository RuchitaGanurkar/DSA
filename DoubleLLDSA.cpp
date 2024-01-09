#include<stdio.h>

#include<iostream>>

using namespsce std;

struct Node{
    Node *prev;
    Node *next;
    int item;
};

class DLL{

    private:
        Node *start;

    public:
        DLL();

        void insertAtStart(int); // data lega

        void insertAtLast(int); // data lega

        Node* search(int); // data jo find krna he woh lega, return node krega pura

        void insertAfter(Node*, int); // kis node ke baad lega, kaunsa data lega

        void deleteFirst();

        void deleteLate();

        void deleteNode();






};

DLL::DLL(){

    start = NULL;

}

void DLL::insertAtStart(int data){

 // pehle node bnaye then usko add kre pointers manipulate krke

 Node *n = new Node();

 // node me upr wali sari chize bnegi, prev-next-item

 // so bnaye hue node ke item me data, prev me null, next me start dale

    n -> prev = NULL;
    n -> item = data;
    n -> next = start;

    // abb add kre list me

    if(start != NULL){
        start -> prev = n;
    }
    start = n;

}


void DLL::insertAtLast(int data){

    Node *t; // for traversing

    Node *n = new Node(); // creating new node

    n -> item = data;

    n -> next = NULL; // item me data rkhe, last ka node he isiliye next me null hoga

    if(start == NULL){ // jab ek bhi node na ho
            n -> prev = NULL;
            start = n;
    }else{ // iska mtlab nodes he bahoot sare
        t = start; // temp me start rkhe

        // traversing ka code yaad rkhe

        while(t -> next != NULL){ // jab tak traverse wale ke next me null na aye, tab tak woh end me nahin pahocha

            t = t->next;

        }

        t -> next = n;
        n-> prev = t;
    }
}


void DLL::insertAfter(Node *t, int data){
        Node *n = new Node();

        if(t != NULL){
            n -> item = data;
            n -> prev = t;

            n->next = t -> next;

            if(t ->next ){
                t -> next -> prev = n;
            }
            t -> next = n;
        }
}
Node* DLL::search(int data){

    Node *t; // temp bnaye, usme start rkhe, jab tak temp null nahi hota tab tak tem ke item ko data se comp kre
    // nahi toh t me uska next rkhte jaye 

    while(t){

        if(t -> item == data){
            return t;
        }
        t = t->next;
    }

    return NULL;
}

void DLL::deleteFirst(){
    if(start){
        if(start -> next){ // jab tak start me null nahi he mtlab ek node toh he, isisliye start ke next ko dekhe agr usme bhi null nahin aata tab tak traverse kre and jab null
        // aaye toh yeh code traverse kre
        start = start -> next;
        delete start -> prev;
        start -> prev = NULL;

        }else{ // sirf start he
            delete start;
            start = NULL;
        }
    }
}


void DLL::deleteLate(){
    Node *t;
    if(start){
        if(start -> next == NULL){
            delete start;
            start = NULL;
        }

        else{
            t = start;
            while(t -> next -> next != NULL){ // 2nd last tak jana pdega
             // uske next ke next me mtlab last wale node ke null hoga toh usse delete kre
                t = t -> next;
            }

            delete t -> next;
            t->next = NULL;
        }

        
    }
}

void DLL::deleteNode(int data){
    Node *t;

    if(start){
        t = start;

        while(t){

            if(t -> item == data){

                if(t == start){
                    deleteFirst();
                }else{
                    if(t -> next){
                        t -> next->prev = t -> next;
                    }
                    t -> prev -> next = t-> next;
                    delete t;
                }
            }

            t = t-> next;
        }
    }
}


DLL::~DLL(){
    while(start){
        deleteFirst();
    }
}


