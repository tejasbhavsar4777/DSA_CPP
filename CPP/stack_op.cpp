#include <iostream>
using namespace std;

class Stack {
    // Properties
public:
    int *arr;
    int top;
    int size;

    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push method
    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack is Overflow" << endl;
        }
    }

    // Pop method
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack is Underflow" << endl;
        }
    }

    // Peek method
    int peek() {
        if (top >= 0 && top < size)
            return arr[top];
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack st(5);

    st.push(22);
    st.push(23);
    st.push(44);
    st.push(88);
    st.push(33);

    //st.pop();

    if (st.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    cout << "Top element: " << st.peek() << endl;

    st.pop();

    cout <<st.peek() <<endl;

    st.pop();

    cout <<st.peek() <<endl;

    st.pop();

    cout <<st.peek() <<endl;

    if(st.isEmpty()){
        cout <<"Stack is empty mere dost"<<endl;

    }
    else{
        cout<<"satck is not empty mere dost"<<endl;
    }


    return 0;
}
