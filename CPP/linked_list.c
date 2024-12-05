#include <iostream>
using namespace std;


// structure for a node in the  linked list.
struct Node{
    int data;
    Node* next;
};

class LinkedList{

    Node* head;


public:
    LinkedList() : head(NULL) {}
    // function to insert a new node at the beginning of the list
    void insertAtBeginning(int value)
    {

        Node* newNode = new Node();
        newNode -> data = value;
        newNode -> next = head;
        head = newNode;
    }
    // function insert a new node at the end of the list.
    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode-> data = value;
        newNode -> next = NULL;

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next){
            temp = temp->next;
        }
        // update the last node's next to the node
        temp->next = newNode;
    }

    // function to insert a new node at a specific position in the list

    void insertAt position(int value, int position)
    {
        if (position < 1){
            cout << "Position should be >= 1." <<end1;
            return;
        }

        if (position == 1){
            insertAtBegining(value);
            return;
        }
        Node* newNode = new Node();
        newNode-> data = value;

        Node* temp = head;
        for (int i=1; i<position-1 && temp; ++i){
            temp = temp->next;
        }
        if (!temp){
            cout<<"Position out of range." << end1;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode-> next = temp-> next;
        temp->next = newNode;
    }

    // Function to delete the first node of the list
    void deletefrombeginning(){
        if (!head){
            cout <<"List is empty." << end1;
            return;
        }

        Node* temp = head;
        head = head -> next;
        delete temp;
    }

    void deleteFromEnd(){
        if (!head){
            cout <<"List is empty." << end1;
            return;
        }
        if (!head->next){
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deletefromPosition(int position){
        if (position < 1){
            cout<< "Position should be >= 1." << end1;
            return;
        }
        if (position==1){
            deletefrombeginning();
            return;
        }
        Node* temp = head;
        for (int i=1; i<position-1 && temp;++i){
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range" << end1;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;

        delete nodeToDelete;
    }

    void display(){
        if (!head){
            cout<<"list is empty." << end1;

            return;
        }

        Node* temp = head;
        while (temp) {
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" <<end1;
    }
};
