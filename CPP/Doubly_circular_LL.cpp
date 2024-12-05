#include<iostream>

using namespace std;

struct Node {
    int data;       // To store the value or data.
    Node* next;     // Pointer to the next node.
    Node* prev;     // Pointer to the previous node.

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL; // Initialize the next pointer to NULL
        this->prev = NULL; // Initialize the prev pointer to NULL
    }
};

void insertAtEnd(Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (tail == NULL){
        // If the list is empty, initialize it with the new node
        tail = newNode;
        tail->next = tail;// circular link
        tail->prev = tail;
    } else {
        // Add the new node after the tail and update the tail.
        newNode->next = tail->next;//point newnode to head.
        newNode->prev = tail;//point new node to current tail
        tail->next->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }

}

void printCircularList(Node* tail) {
    if (tail == NULL){
        cout << "List is Empty." << endl;
        return;
    }

    Node* temp = tail->next; //start from the head node.
    do{
        cout << temp->data<<" ";
        temp = temp->next;
    }while (temp != tail->next);
    cout << endl;
}


int main(){


 Node* tail = NULL;
 //Node* prev = NULL;

    insertAtEnd(tail, 10);
    insertAtEnd(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 40);


    cout << "Doubly Circular Linked List: ";
    printCircularList(tail);


    return 0;



}

