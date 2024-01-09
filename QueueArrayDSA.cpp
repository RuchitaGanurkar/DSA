#include<isotream>

#include<stdio.h>

using namespace std;
class Queue{
    private:
        int capacity;
        int front, rear;
        int *ptr;

        // rear se insert, front se delete
    public:
        Queue(int);

        void enqueue(int); //insert into queue, takes data

        void dequeue(); // delete into queue

        bool isFull();
        bool isEmpty();

        int getFront();
        int getRear();
        int size();

        ~Queue();

};

Queue::Queue(int cap){
    capacity=cap;
    front=rear=-1;
    ptr=new int[cap];
}
bool Queue::isFull(){
    if(front==0 && rear==capacity-1 || rear==front-1){
        return true;
    }
    return false;
}

bool Queue::isEmpty(){
    return front==-1;
}
void Queue::enqueue(int data){

    if(isFull()){
        throw OVERFLOW;
    }

    if(isEmpty()){ 
        rear=front=0;
    }else if(rear==capacity-1){ // agr kuchh element he but not filled, then also rear = 0
        rear=0;
    }else{
        rear++;
        
    }

    ptr[rear] = data;

}
    
void Queue::dequeue(){
    // delete

    if(isEmpty){
        throw EMPTY;
    }
    if(front==rear){

        front=rear=-1;

    }else if(front==capacity-1){
        front=0;
    }else{
        front++;
    }
}


int Queue::getFront(){

    if(isEmpty()){
        throw EMPTY;
    }
    return ptr[front];
}

int Queue::getRear(){
   if(isEmpty){
    throw EMPTY;
   }
   
   return ptr[rear];
}


Queue::~Queue(){

    delete ptr[];

}

int Queue::size(){

    if(front>rear){
        return capacity-(front-rear)+1;
    }else{
        return rear-front+1;
    }
}