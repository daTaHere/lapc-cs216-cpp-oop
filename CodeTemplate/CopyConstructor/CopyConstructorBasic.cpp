#include <iostream>
using namespace std;

class Student {
private:
    int id;
    int age;

public:
    Student() {
        id = 0;
        age = 0;
    }

    Student(int i, int a) {
        id = i;
        age = a;
    }

    // Copy constructor
    Student(const Student& other) {
        id = other.id;
        age = other.age;
    }

    void setAge(int a) {
        age = a;
    }

    void print() {
        cout << "ID: " << id << ", Age: " << age << endl;
    }
};

int main() {
    Student s1(10, 19);

    // Copy constructor is called here
    Student s2 = s1;

    s1.print();
    s2.print();

    cout << endl;

    s2.setAge(21);

    s1.print();
    s2.print();

    return 0;
}