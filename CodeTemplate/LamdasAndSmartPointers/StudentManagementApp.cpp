#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

struct Student {

    string name;
    int age;

    Student( string n, int a ) : name(n), age(a) { }

};

void displayStudents( const vector< shared_ptr<Student>> &students) {

    for (const auto& s  : students) {
        cout <<  s->name << " " <<  s->age  <<  endl;
    }

}

int main() {

    vector< shared_ptr<Student> > students;

    students.push_back( make_shared<Student>( "Mary", 19) );

    students.push_back( make_shared<Student>( "Data", 28) );

    students.push_back( make_shared<Student>( "Tom", 22 ) );

    sort( students.begin(), students.end(),
        []( const auto& a, const auto& b ) {
            return a->age < b->age;
        }
    );

    displayStudents(students);

    cout << "\nOlder than 21\n";

    for_each( students.begin(), students.end(),
        [](const auto& s) {
            if (s->age > 21) {
                cout << s->name << " " << s->age << endl;
            }
        }
    );

    return 0;
}