#include <iostream>
#include <memory>

using namespace std;

class Student {
public:
    string name;

    Student(string n) : name(n) { }

};

int main() {

    unique_ptr<Student> s1 =  make_unique<Student>("Bob");

    cout << s1->name << endl;

    unique_ptr<Student> s2 = move(s1);

    if (!s1)
        cout << "s1 is null" << endl;

    cout << s2->name << endl;

    return 0;
}