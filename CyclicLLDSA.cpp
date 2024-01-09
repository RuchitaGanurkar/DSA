#include<stdio.h>

#include<iostrream>

using namespace std;

class Node{

    public:
        Node *next;
        int item;

};

class CLL{

    public:
        CLL();

        void insertStart(int);

        void insertLast(int);

        void insertNode(Node*, int);

        void deleteStart();

        void deleteLast();

        void deleteNode(int); 

        Node *search(int);


    private:
        Node *last;
};


CLL::CLL(){
    last=NULL;
}

void CLL::insertStart(int data){

    Node *n = new Node();
    n -> item = data;
    
    if(last == NULL){
        n -> next = n;

        last = n;
        // self loop 
    }
    else{
        // more than 1 nodes hai

        n -> next = last -> next;
        last -> next = n;
    }
}

void CLL::insertLast(int data){

    Node *n = new Node();

    n -> item = data;

    if(last == NULL){

        n -> next = n;
        last = n;

    }else{

        n -> next = last-> next;
        last -> next = n;
        last = n;
    }
}


void CLL::insertNode(Node *t, int data){

    if(t){
        Node *n = new Node();
        n -> item = data;
        n -> next = t -> next;

        t -> next = n;

        if(t == last){
            last = n;
        }
    }
}

void CLL::deleteStart(){

    if(last){

        if(last->next == last){
            // self loop
            delete last;
            last = NULL;
        }else{
            Node *t;
            n = last->next;
            // traverse
            last -> next = last -> next ->next;
            // ek chhod kr

            delete t;
        }
    }
}

void CLL::deleteLast(){

            Node *t;

            if(last){

                if(last->next == last){
                    delete last;
                    last = NULL;
                }

                else{

                    t = last -> next;

                    while(t -> next != last){
                        t = t->next;
                    }

                    t -> next = last -> next;
                    delete last;

                    last = t;
                }
            }
}

void CLL::deleteNode(int data){

    Node *t, *r;

    if(last){
        if(last->next == last){
            if(last -> item == data){
                delete last;
                last = NULL;
            }
        }else{
            t = last;

            do{
                if(t -> next -> item == data){
                    r = t->next;

                    t -> next = r -> next;

                    if(r == last){
                        last = t;
                    }

                    delete r;
                    break;
                }

                t = t-> next;
            }while(t != last);
        }
    }
}


CLL::~CLL(){
    while(last){
        deleteStart();
    }
}


Node  *CLL::search(int data){

    Node *t;

    if(last == NULL){
        return nullptr;
    }

    t = last->next;

    do{

        if(t -> item == data){
            return t;
        }

        t = t-> next;
    }while(t != last -> next);

    return nullptr;
}

