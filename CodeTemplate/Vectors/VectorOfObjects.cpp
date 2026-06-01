#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

int main() {
    vector<Person> students;

    students.push_back(Person("Mary", 19));
    students.emplace_back("Al", 20);
    students.emplace_back("Rose", 21);

    for (const auto& person : students) {
        cout << "Name: " << person.getName()
            << ", Age: " << person.getAge()
            << endl;
    }

    return 0;
}