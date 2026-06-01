#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Student {
public:
    string name;
    int age;

    Student( string n, int a) : name(n),age(a) { }
};

int main() {

    vector<shared_ptr<Student>> classroom;

    classroom.push_back( make_shared<Student>( "Alice", 21) );

    classroom.push_back( make_shared<Student>( "Tom", 22) );

    classroom.push_back( make_shared<Student>( "Sara", 20) );

    for (const auto& s : classroom) {
        cout << s->name << " " << s->age << endl;
    }

    return 0;
}