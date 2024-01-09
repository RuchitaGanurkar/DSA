#include<iostream>

#include<stdio.h>

using namespace std;

class Node{
    public:
        int item;
        Node *next; // singly linked list
};


class Stack{

    private:
        Node *top;  // top == start 

    public:
        Stack();
        void push(int);
        void pop();
        int peek();

        bool isEmpty();


        ~Stack();

};

Stack::Stack(){
    top = NULL;
}

void Stack::push(int data){
    // insert ka operation he using linkedlist
    // node banaye, uske item me data, next me top, top me naya node assign kre

    Node *n=new Node;

    n->item=data;
    n->next=top;
    top = n;

}

int Stack::peek(){

    if(top==NULL){
        throw UNDERFLOW;
    }else{
        return top->item;
    }
}

void Stack::pop(){

    Node *r;
    if(top){
        r = top;
        top = top->next;
        delete r;
    }
}

bool Stack::isEmpty(){
    return top==NULL;
}


Stack::~Stack(){

    while(top){
        pop();
    }
}

// reverse stack baki