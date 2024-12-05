#include<iostream>
using namespace std;

//#define SIZE 100

//int* arr;
//int front;
//int rear;
//int size;
class Queue{
private:

    int front;
    int rear;
    int size;
    int *arr;


public:

    Queue(int maxSize){
        size = maxSize;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Queue(){

        delete[] arr;
    }


    bool isEmpty(){

        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;

    }

    // Enqueue an element into the queue. means add the element to the list
    void enqueue(int value){
        if (isFull()){ //Check if the queue ids full using the isfull function.
            cout<< "Queue is Full. cannot enqueue "<< value << "."<<endl;
            return;
        }
        if (isEmpty()){ //if the queue was empty before enqueueing also updatethe front pointer
            front = rear = 0;
        }else{
            rear = (rear + 1) % size; // if the not full increment the rear pointer and add the new element to the rear position

        }
        arr[rear] = value;
        cout<<value<< " enqueued into the queue."<<endl;

    }

    // Dequeue an element from the queue. means remove the  element from the list....

    int dequeue(){
        if (isEmpty()){

            cout<< "Queue is empty. cannot dequeue."<< endl;
            return -1;
        }
        int dequededValue = arr[front];
        if (front == rear){

            front = rear = -1;
        }else{
            front = (front + 1) % size;
        }
        return dequededValue;

    }

    int peek(){
        if (isEmpty()){
            cout<<"Queue is empty. Noting to add in it" <<endl;
            return -1;
        }
        return arr[front];

    }

    void display(){

        if (isEmpty()){
            cout<<"queue is empty." <<endl;
            return;
        }
        cout <<"Queue elements: ";
        int i = front;
        do{

            cout<<  arr[i] <<"";
            i = (i+1)%size;
        }while(i != (rear + 1)% size);
        cout<<endl;

    }



};


int main(){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);


    q.display();

    cout<<"Dequeued: "<<q.dequeue() <<endl;
    q.display();

    q.enqueue(60);
    q.display();

    cout<< "Front element: "<<q.peek() <<endl;

    return 0;

}

