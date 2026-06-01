#include <iostream>
using namespace std;

class GradeBook {
private:
    int studentCount;
    int* grades;

public:
    GradeBook() {
        studentCount = 0;
        grades = nullptr;
    }

    GradeBook(int count) {
        studentCount = count;
        grades = new int[studentCount];

        for (int i = 0; i < studentCount; i++) {
            grades[i] = 0;
        }
    }

    // Copy constructor
    GradeBook(const GradeBook& other) {
        studentCount = other.studentCount;
        grades = new int[studentCount];

        for (int i = 0; i < studentCount; i++) {
            grades[i] = other.grades[i];
        }
    }

    // Assignment operator
    GradeBook& operator=(const GradeBook& other) {
        if (this != &other) {
            delete[] grades;

            studentCount = other.studentCount;
            grades = new int[studentCount];

            for (int i = 0; i < studentCount; i++) {
                grades[i] = other.grades[i];
            }
        }

        return *this;
    }

    ~GradeBook() {
        delete[] grades;
    }

    void setAllGrades(int value) {
        for (int i = 0; i < studentCount; i++) {
            grades[i] = value;
        }
    }

    void setGrade(int index, int value) {
        grades[index] = value;
    }

    void printGrades() {
        for (int i = 0; i < studentCount; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    GradeBook g1(5);
    g1.setAllGrades(80);

    GradeBook g2;

    // Assignment operator is called here
    g2 = g1;

    g2.setGrade(0, 100);

    cout << "g1: ";
    g1.printGrades();

    cout << "g2: ";
    g2.printGrades();

    return 0;
}