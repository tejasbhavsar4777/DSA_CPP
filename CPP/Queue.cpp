//#include<bits/bits/stdc++.h>
#include<iostream>
#include<queue>


using namespace std;

//FIFO


int main(){

    queue<int> q;

    q.push(11);
    cout<<"front of q is: "<<q.front()<<endl;
    q.push(15);
    cout<<"front of q is: "<<q.front()<<endl;
    q.push(13);
    cout<<"front of q is: "<<q.front()<<endl;

    cout<<"Size of queue: "<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();

    cout<<"Size of queue: "<<q.size()<<endl;
    //cout<<"Peek element: "<<q.peek()<<endl;

    if (q.empty()){
        cout<<"Queue is empty..."<<endl;

    }
    else{

        cout<<"Queue is not empty..."<<endl;
    }

    return 0;



}
