#include <iostream>
using namespace std;

// First parent class
class Student {
public:
    void study() {
        cout << "Student is studying" << endl;
    }
};

// Second parent class
class Child {
public:
    void play() {
        cout << "Child is playing" << endl;
    }
};

// Derived class inheriting from two parent classes
class Preteen : public Student, public Child {
public:
    void action() {
        study();
        play();
    }
};

int main() {
    Preteen person;

    person.study();
    person.play();
    person.action();

    return 0;
}