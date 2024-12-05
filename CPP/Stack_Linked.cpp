#include<bits/stdc++.h>
using namespace std;

//class representing a node in the linked list

class Node{

public:
    int data;
    Node* next;
    Node(int new_data){
        this->data = new_data;
        this->next = nullptr;
    }
};


class Stack{

    Node* head;


public:
    Stack(){this->head = nullptr;}

    bool isEmpty(){
        return head == nullptr;
    }

    void push(int new_data){
        Node* new_node = new Node(new_data);

        if(!new_node){
            cout<<"Stack overflow";
        }

        new_node->next = head;

        head = new_node;

    }

    void pop(){
        if (this->isEmpty()){
            cout<<"Stack underflow"<< endl;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int peek(){
        if(!isEmpty())
            return head->data;
        else{

            cout<<"stack isempty";
            return INT_MIN;
        }
    }

};





int main(){
    Stack st;


    st.push(11);
    st.push(54);
    st.push(16);
    st.push(59);
    st.push(17);
    st.push(88);

    cout<<"Top element is" << st.peek()<<endl;

    cout<<"Removing the elements..."<<endl;

    st.pop();
    st.pop();

    cout<<"Peek element"<<st.peek()<< endl;


    return 0;





}
