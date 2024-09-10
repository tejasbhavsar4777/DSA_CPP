#include<iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const
    {
        cout << "Animal speaks." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override
    {
        cout << "Dog barks." << endl;
    }
};

class cat: public Animal {
public:
    void speak() const override
    {
        cout << "cat meows. " << endl;
    }

};

int main()
{
    Animal* animalptr = new Dog();

    Dog* dogptr = dynamic_cast <Dog*>(animalptr);

    if (dogptr){
        dogptr -> speak();
    }

    cat* catptr = dynamic_cast<cat*>(animalptr);
    if (catptr){
        catptr->speak();
    }
    else{
        cout << "Failed to cast to Dog: " << endl;

    }
    delete animalptr;
    return 0;
}
