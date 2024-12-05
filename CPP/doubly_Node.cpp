#include <iostream>
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

void forwardTraversal(Node* head) {
    // Start traversal from the head

}
// traversing the linked list
void print(Node* head){
    Node* temp = head;

    while (temp != NULL){
        cout << temp -> data<<" ";
        temp = temp -> next;
    }
    cout << endl;
}
// length of the linked list
int get_length(Node* head){
    int len = 0;
    Node * temp = head;

    while (temp != NULL){
        //cout << temp -> data;
        len++;
        temp = temp -> next;
    }
    return len;

}

//Insertion at the head  the linkded list
void insertionAtHead(Node* &head, Node* &tail, int data){

    if (head == NULL){
        Node* temp = new Node(data);
        head = temp;


    }else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }


}
void insertionAttail(Node* &tail, Node* &head, int data){

    Node* temp = new Node(data);

    if (tail == nullptr){
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;

    tail = temp;

}
void printtail(Node* tail){
    Node* temp = tail;
    while (temp != nullptr){

        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;

}

void deleteNode(int position, Node* &head){
    //deleting first or start node
    if (position == 1){
        Node* temp = head;
        temp -> next->prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;

    }
    else
    {
        //deleting any middle node or last node.
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr -> next;
            cnt++;

        }
            curr -> prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;

            delete curr;


    }

}


void insertAtPosition(Node* &head,int position, int data) {
     if (position == 1) {
        insertionAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    if (position == 1) {
        insertionAtHead(head, data);
        return;
    }

    Node* nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}


int main() {
    // Create a new node with data = 10
    Node* node1 = new Node(10);
    Node* head = node1;
    //print(head);
    // Print the data of the node
    insertionAtHead(head, 14);
    insertionAtHead(head, 15);
    insertionAtHead(head, 16);
    insertionAtHead(head, 17);
    //insertionAttail(tail, 18);
    print(head );


    Node* tail = nullptr;
    insertionAttail(tail,18);
    insertionAttail(tail,17);
    insertionAttail(tail,16);
    insertionAttail(tail,15);
    insertionAttail(tail,14);
    printtail(tail);


    //print(head);
    insertAtPosition(head,2,19);
    print(head);
    insertAtPosition(tail, 4, 1002);
    print(head);


    cout << "Node data: " << node1->data << endl;

    deleteNode(1, head);
    print(head);

    // Since next and prev are NULL, explicitly show their values
    //cout << "Node next: " << node1->next << endl; // Should print 0 (NULL)
    //cout << "Node prev: " << node1->prev << endl; // Should print 0 (NULL)
    cout << "Length of the LL: "<< get_length(head) << endl;
    cout << "Length of the LL: "<< get_length(tail) << endl;

    return 0;
}
