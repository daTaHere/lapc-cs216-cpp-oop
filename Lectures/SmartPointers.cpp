#include <iostream>
#include <vector>
//#include <memory>
//#include <string>

using namespace std;

//==============================================================

class Student {
private:
    string name;
    int age;

public:
    Student(const string& n, int a) : name(n), age(a) {
        cout << "Creating Student: " << name << endl;
    }

    ~Student() {
        cout << "Destroying Student: " << name << endl;
    }

    void display() const {
        cout << name
            << ", Age: " << age << endl;
    }
};
//==================================================================

class Book {
private:
    string title;

public:
    Book(const string& t) : title(t) {
        cout << "Book \"" << title << "\" created." << endl;
    }

    ~Book() {
        cout << "Book \"" << title << "\" destroyed." << endl;
    }

    void display() const {
        cout << "\nTitle: " << title << endl;
    }
};
//==================================================================

class Course {
private:
    string courseName;

public:
    Course(const string& name) : courseName(name) {
        cout << "Course " << courseName << " created." << endl;
    }

    ~Course() {
        cout << "Course " << courseName << " destroyed." << endl;
    }

    void show() {
        cout << "Course: " << courseName << endl;
    }
};

/*==============================================================
                  UNIQUE_PTR EXAMPLES
==============================================================*/

void uniquePtrExamples() {
    cout << "UNIQUE_PTR EXAMPLES" << endl;
    // unique_ptr owns ONE object only
    unique_ptr<Student> s1 = make_unique<Student>("Bob", 19);

    s1->display();

    // Cannot copy unique_ptr
    // unique_ptr<Student> s2 = s1; // ERROR
    // Transfer ownership using move()
    unique_ptr<Student> s2 = move(s1);

    cout << "\nAfter move:" << endl;

    if (s1 == nullptr)
        cout << "s1 is now empty." << endl;

    s2->display();

    /*----------------------------------------------------------
                         unique_ptr with arrays
    ----------------------------------------------------------*/

    cout << "\nDynamic Array Example:" << endl;

    unique_ptr<int[]> arr = make_unique<int[]>(5);

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

/*==============================================================
                        SHARED_PTR EXAMPLES
==============================================================*/

// multiple parts of a program like different objects, containers
// "own" the same data without knowing who will be the last
// one to finish using it
//
// Dangling Pointer Prevention: In manual memory management,
// if one part of your code deletes an object while another still
// has a pointer to it, you get a "dangling pointer"

void sharedPtrExamples() {
    cout << "SHARD_PTR EXAMPLE" << endl;
    shared_ptr<Book> b1 = make_shared<Book>("C++ Programming");
    cout << "Reference count: " << b1.use_count() << endl;
    //Shared ownership
    shared_ptr<Book> b2 = b1;
    cout << "\nReference count after b2: " << b1.use_count() << endl;
    {
        shared_ptr<Book> b3 = b1;
        cout << "Reference count after b3: " << b1.use_count() << endl;
        b3->display();
    }
    // b3 destoryed here
    cout << "Reference count after b3: " << b1.use_count() << endl;
    b2->display();


}

/*==============================================================
                      WEAK_PTR EXAMPLES
==============================================================*/

// provide a non-owning reference to an object managed by
// a shared pointer

// breaking Circular Dependencies:
// If two objects hold shared_ptr to each other
// (e.g., a "Parent" and "Child" node),
// their reference counts will never reach zero,
// causing a permanent memory leak even if they are no longer reachable
// Replacing one of these with a weak_ptr breaks the cycle.

void weakPtrExamples() {

    cout << "WEAK_PTR EXAMPLES" << endl;

    shared_ptr<Course> c1 = make_shared<Course>("CS216");
    weak_ptr<Course> weakCourse = c1;

    cout << "Shared count: " << c1.use_count() << endl;

    // lock() converts weak_ptr to shared_ptr temporarily
    if (shared_ptr<Course> temp = weakCourse.lock()) {
        cout << "\nObject still exists." << endl;
        temp->show();
    }

    // destroy shared_ptr
    c1.reset();

    // check if object still exists
    if (weakCourse.expired()) {
        cout << "\nObject has been destroyed." << endl;
    }
}

/*==============================================================
FUNCTION EXAMPLE
==============================================================*/

unique_ptr<Student> createStudent() {
    unique_ptr<Student> temp = make_unique<Student>("Mike", 25);
    return temp; // ownership transferred
}

/*==============================================================
VECTOR OF SMART POINTERS
==============================================================*/

void vectorExample() {
    cout << "\nVECTOR OF SMART POINTERS" << endl;

    vector<shared_ptr<Student>> classroom;

    classroom.push_back(
        make_shared<Student>("Alice", 21));

    classroom.push_back(
        make_shared<Student>("Tom", 22));

    classroom.push_back(
        make_shared<Student>("Sara", 20));

    for (const auto& s : classroom) {
        s->display();
    }
}


int main() {
    cout << "SMART POINTER DEMO PROGRAM\n" << endl;
    uniquePtrExamples();

    cout << "\n========================" << endl;
    // shared_ptr examples
    sharedPtrExamples();

    cout << "\n========================" << endl;
    // weak_ptr examples
    weakPtrExamples();

    // Returning unique_ptr from function
    cout << "\n========================" << endl;
    cout << "RETURNING UNIQUE_PTR" << endl;

    unique_ptr<Student> student1 = createStudent();
    student1->display();

    // Vector of smart pointers
    vectorExample();
    // Raw pointer problem example
    cout << "RAW POINTER PROBLEM" << endl;

    /*
    Student* ptr = new Student("Jeff", 23);

    // If exception occurs before delete,
    // memory leak may happen

    delete ptr;
    */

    cout << "\nProgram ending..." << endl;
    vectorExample();

	return 0;
}