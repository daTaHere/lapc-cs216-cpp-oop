

#include <iostream>
#include <functional>    // function, bind
#include <algorithm>     // sort
#include <vector>
#include <numeric>       // accumulate
#include <memory>

using namespace std;

struct Student {

    string name;
    int age;

    void display() const {
        cout << name
            << ", Age: " << age << endl;
    }
};


void callBackFunction(const string& message, const function<void(string)>& callback) {
    callback(message);
}


void menu() {
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Sort By Age" << endl;
    cout << "4. Sort By Name" << endl;
    cout << "5. Find Student Older Than 21" << endl;
    cout << "6. Lambda Callback Demo" << endl;
    cout << "7. unique_ptr Demo" << endl;
    cout << "8. shared_ptr Demo" << endl;
    cout << "9. Exit" << endl;
}


unique_ptr<Student> addStudent(string name, int age) {
    unique_ptr<Student> temp = make_unique<Student>(name, age);
    return temp;
}

void displayStudents(const vector<shared_ptr<Student>>& students) {

    for (const auto& s : students) {

        cout << s->name
            << " - "
            << s->age
            << " years old" << endl;
    }

    cout << endl;
}
void sortbyname(vector<shared_ptr<Student>>& students) {
    sort(students.begin(), students.end(),
        [](const shared_ptr<Student>& s1, const shared_ptr<Student>& s2) {
            return s1->name < s2->name;
        }
    );
}
void sortbyage(vector<shared_ptr<Student>>& students) {
    sort(students.begin(), students.end(),
        [](const shared_ptr<Student>& s1, const shared_ptr<Student>& s2) {
            return s1->age < s2->age;
        }
    );
}

void find21(vector<shared_ptr<Student>>& students) {
    for_each(students.begin(), students.end(),
        [](shared_ptr<Student> n) {
            if (n->age > 21) {
                cout << n->name << " " << n->age << endl;
            }
        }
    );
}

void uniquePtrDemo() {
    cout << "\nunique_ptr demo" << endl;

    unique_ptr<Student> Demo = make_unique<Student>("TEST", 23);
    cout << "\nBefore move:" << endl;
    cout << Demo->name << endl;

    // move ownership
    unique_ptr<Student> Demo2 = move(Demo);
    cout << "Ownership moved to another unique_ptr" << endl;
    cout << "\nAfter move:" << endl;

    if (!Demo) {
        cout << "The original student is now null." << endl;
    }

    cout << "The replacement student now owns: "
        << Demo2->name << endl;

}


void sharedPtrdemo() {
    cout << "Shared_ptr + weak_ptr demo" << endl;

    shared_ptr<Student> sharedStud = make_shared<Student>("Data", 28);

    shared_ptr<Student> studD2 = sharedStud;

    cout << " Shared_ptr demo: " << endl;
    cout << "Use Count: " << sharedStud.use_count() << endl;

    weak_ptr<Student> weakStud = sharedStud;

    if (!weakStud.expired()) {
        shared_ptr<Student> temp = weakStud.lock();
        cout << "weak_ptr accessed: " << temp->name << endl;
    }

}


int main() {

    vector<shared_ptr<Student>> students;
    int option;
    string name;
    int age;

    do {
        menu();
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter students name: " << endl;
            cin >> name;
            cout << "Enter students age: " << endl;
            cin >> age;
            students.push_back(addStudent(name, age));
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            sortbyage(students);

            break;
        case 4:
            sortbyname(students);
            break;
        case 5:
            find21(students);
            break;
        case 6:
        {

            auto myCallback = [](string msg) {
                cout << "Callback executed! Message received: " << msg << "\n";
                };
            callBackFunction("Hello from the College System!", myCallback);
        }

        break;
        case 7:
            uniquePtrDemo();

            break;
        case 8:
            sharedPtrdemo();
            break;

        case 9:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid Choice --> Please try again." << endl;
        }
    } while (option != 9);

}