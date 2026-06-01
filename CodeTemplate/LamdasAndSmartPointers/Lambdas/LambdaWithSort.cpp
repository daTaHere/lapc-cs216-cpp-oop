#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int age;
};

void display(  const vector<Student>& students ) {

        for (const auto& s : students) {

            cout << s.name << " " << s.age << endl;

        }

}

int main() {

    vector<Student> students = { {"Pete",21}, {"Alex",25}, {"Emma",18}, {"Mary",19} };

    sort( students.begin(), students.end(), 
        [](const Student& s1, const Student& s2) {

            return s1.age < s2.age;

        }
    );

    display(students);

    sort( students.begin(), students.end(), 
        [](const Student& s1, const Student& s2) {

            return s1.name < s2.name;

        }
    );

    display(students);

    return 0;
}