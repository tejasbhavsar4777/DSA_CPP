// A Circular linked list is a type Linked List where
//the last node points back to the first node forming a
//Circular structure. Circular linked lists can be either singly or doubly
//linked.

// Singly circular linked list.
#include <iostream>

using namespace std;


struct Node {
    int data;       // To store the value
    Node* next;     // Pointer to the next node

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if (this->next != NULL){
            delete next;
            next = NULL;
        }
        cout <<" Memory is free for node with data " << value << endl;
    }
};

void insertNode(Node*&tail, int data){
    //assuming that the element is present in the last

    if (tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr = curr -> next;
        }

        Node* temp = new Node(data);
        temp -> next = curr ->next;
        curr -> next = temp;


    }

}




// Insert a node at the end of the circular linked list.
void insertAtEnd(Node* & tail, int data) {
    Node* newNode = new Node(data);
    if (tail == NULL){
        // If the list is empty, initialize it with the new node
        tail = newNode;
        tail->next = tail;// circular link
    } else {
        // Add the new node after the tail and update the tail.
        newNode->next = tail->next;
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

    insertAtEnd(tail, 10);
    insertAtEnd(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 40);


    cout << "Circular Linked List: ";
    printCircularList(tail);

    return 0;
}
