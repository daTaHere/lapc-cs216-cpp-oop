#include <iostream>
#include <memory>

using namespace std;

class Course {
public:
    string name;

    Course(string n) : name(n) { }
};

int main() {

    shared_ptr<Course> c1 = make_shared<Course>( "CS216" );

    weak_ptr<Course> weakCourse = c1;

    if ( auto temp = weakCourse.lock() ) {
        cout << temp->name << endl;
    }

    c1.reset();

    if (weakCourse.expired())
        cout << "Destroyed" << endl;

    return 0;
}