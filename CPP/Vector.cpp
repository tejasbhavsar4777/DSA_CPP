#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> v;

    vector<int> a(5,0);

    vector<int> last(a);
        cout << "print a"<<endl;
    for (int i:last){
        cout <<i<<" ";
    }

    cout <<"Capacity->" <<v.capacity()<<endl;

    v.push_back(1);
    cout <<"Capacity->" <<v.capacity()<<endl;

    v.push_back(2);
    cout <<"Capacity->" <<v.capacity()<<endl;

    v.push_back(3);
    cout <<"capacity->" <<v.capacity()<<endl;

    cout <<"Size->" <<v.size()<<endl;

    cout <<v.at(2)<<endl;

    cout<<"First elemts"<<v.front()<<endl;
    cout<<"Last Elemets"<<v.back()<<endl;


    cout<<"before pop"<<endl;
    for (int i:v){
        cout<<endl;
    }
    v.pop_back();

    cout<<"After pop"<<endl;

    for (int i:v){
        cout <<i<<"";
    }

    cout <<"Before size"<<v.size()<<endl;

    v.clear();

    cout <<"after clear size "<<v.size()<<endl;






}
