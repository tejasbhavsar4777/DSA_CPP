#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Queue{

private:
    Node* front;//pointer to the front node
    Node* rear;// pointer to the rear node.


public:

    //constructor

    Queue(){

        front = nullptr;
        rear = nullptr;
    }

    ~Queue(){
        while(!isEmpty()){

            dequeue();
        }
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int value){
        Node* newNode = new Node(value); //create the new node with the given data.
        if (rear == nullptr){ //check if the queue is empty

            front = rear = newNode; // if it is empty then front and rear pointer to this new node
        }
        else{
            rear -> next = newNode; // if it is not empty then link the rear nodes next pointer to this new node.
            rear = newNode;
        }
        cout<< value <<"enqueued into the queue."<<endl;
    }

    void dequeue(){
        if (isEmpty()){

            cout<<"queue is empty. cannot deqeue." <<endl;
            return -1;
        }

        Node* temp = front;
        int dequeuedValue = front -> data;
        front  = front -> next;

        if (front == nullptr){
            rear = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }


    void peek(){
        if (isEmpty()){

            cout<<"Queue is empty. cannot peek." <<endl;
            return -1;

        }
            return  front->data;

    }

    void display(){
        if(isEmpty()){

            cout<<"Queue is empty." <<endl;
            return;
        }
        cout<<"Queue elements: ";
        Node* temp = front;
        while(temp!=nullptr){
            cout<<temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;

    }
};


int main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout<<"Dequeued: " <<q.dequeue()<<endl;

    q.display();


    return 0;



}
