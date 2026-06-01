#include <iostream>
using namespace std;

// Base class / parent class
class Animal {
private:
    int privateValue = 13;

protected:
    int protectedValue = 19;

public:
    Animal() {
        cout << "Animal constructor called\n";
    }

    ~Animal() {
        cout << "Animal destructor called\n";
    }

    void speak() {
        cout << "Animal speaks\n";
    }

    void eat() {
        cout << "Animal eats animal food\n";
    }
};

// Derived class / child class
class Dog : public Animal {
public:
    Dog() {
        cout << "Dog constructor called\n";
    }

    ~Dog() {
        cout << "Dog destructor called\n";
    }

    void showProtectedValue() {
        // privateValue is NOT accessible here
        cout << "Protected value: " << protectedValue << endl;
    }

    void bark() {
        cout << "Dog barks\n";
    }

    // Function overriding
    void eat() {
        cout << "Dog eats dog food\n";
    }

    void speak() {
        cout << "Dog speaks\n";

        // Call base class version
        Animal::speak();
    }
};

int main() {
    Dog myDog;

    cout << endl;

    myDog.showProtectedValue();
    myDog.speak();
    myDog.bark();
    myDog.eat();

    cout << endl;

    return 0;
}