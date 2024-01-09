#include<isodtream>

#include<stdio.h>

using namespace std;

class Stack{
    private:
        int capacity;
        int top;
        int *ptr;


    public:
        Stack(int);

        void push(int); // data // insert kre
        int peek(); // data dekhe and btaye
        void pop(); // delete kre

        bool isEmpty();
        bool isFull();
        int size();

        ~Stack();

};


Stack::Stack(int cap){

    capacity = cap;
    top = -1;
    ptr = new int[cap];

}


void Stack::push(int data){
    if(capacity - 1 == top){
            throw OVERFLOW;
    }else{
        top++;
        ptr[top] = data;
    }
}

int Stack:: peek(){
if(top == -1){
    throw UNDERFLOW;
}else{
    return ptr[top];
}
return 0;
}

void Stack::pop(){

    if(top == -1){
        throw UNDERFLOW;
    }else{
        top--;
    }
}

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}


bool Stack::isFull(){

    if(capacity-1 == top){
        return true;
    }

    return false;
}


int Stack::size(){
    return top+1;
}


Stack::~Stack(){
    delete ptr[];

}

// reverse, min valude baki