#include<iostream>

using namespace std;

// Singly Linked List
struct Node {

    int data;
    Node* next;



// Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};
// Doubly Linked List : A doubly linked list is a data structure that consists of a
// set of nodes each of which contains a value and two pointers one pointing to the previous node in the list and one
//pointing to the next node in the list.

int main() {
    Node* node1 = new Node(10);
    cout << "Node data: " << node1->data <<endl;
    cout << "Node next: " << node1->next <<endl;

    return 0;

}
