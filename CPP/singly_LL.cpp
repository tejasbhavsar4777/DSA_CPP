#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;

        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data: " << value << endl;
    }
};

// Insert at the head of the list
void InsertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert at the tail of the list
void InsertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Insert at a specific position in the list
void InsertAtPosition(Node*& head, int position, int d) {
    // If inserting at the head
    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the (position-1)-th node
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // If position is invalid
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Insert the new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Print the list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete a node at a specific position
void deleteNode(int position, Node*& head) {
    if (position == 1) {
        // Handle deletion of the first node
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

// Traversal of a Linked List refers to the process of visiting and accessing
//each node in a linked list sequentially, starting from the head and continuing
//until the end of the list.

    // Traverse to the target position
    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    // If position is invalid
    if (curr == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Delete the target node
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main() {
    // Create a new node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // Print initial list
    print(head);

    // Insert at the head
    InsertAtHead(head, 12);
    print(head);

    // Insert at the tail
    InsertAtTail(tail, 15);
    print(head); // Print the full list, not just the tail

    // Insert at a specific position
    InsertAtPosition(head, 1, 23);
    print(head);

    // Delete a node at a specific position
    deleteNode(4, head);
    print(head);

    return 0;
}
