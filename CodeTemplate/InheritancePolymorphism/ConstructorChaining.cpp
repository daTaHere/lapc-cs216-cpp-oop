#include <iostream>
using namespace std;

// Parent class
class Parent {
public:
    Parent(int x) {
        cout << "Parent constructor called with x = " << x << endl;
    }

    ~Parent() {
        cout << "Parent destructor called" << endl;
    }
};

// Child class
class Child : public Parent {
public:
    Child(int x, int y) : Parent(x) {
        cout << "Child constructor called with y = " << y << endl;
    }

    ~Child() {
        cout << "Child destructor called" << endl;
    }
};

int main() {
    Child obj(10, 20);

    return 0;
}