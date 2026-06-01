#include <iostream>
using namespace std;

// *****************************    RULE OF THREE  ************************************************
/*
                                                When using  ~new~    !!!!!!
                                                Copy Constructor --> ( Copy data Deep )
                                                Assignment Operator --> (  Assign Data while preventing modication of original object )
                                                Destructor -->  (Prevent Memory Leak)
***********************************************************************************************/

class Patient {
private:
    string name;
    int numTests;
    double* testResults;

public:
    Patient() {
        name = "";
        numTests = 0;
        testResults = nullptr;
    }

    Patient(string n, int tests) {
        name = n;
        numTests = tests;
        testResults = new double[numTests];

        for (int i = 0; i < numTests; i++) {
            testResults[i] = 0.0;
        }
    }

    // 1. Copy constructor
    Patient(const Patient& other) {
        name = other.name;
        numTests = other.numTests;
        testResults = new double[numTests];

        for (int i = 0; i < numTests; i++) {
            testResults[i] = other.testResults[i];
        }
    }

    // 2. Assignment operator
    Patient& operator=(const Patient& other) {
        if (this != &other) {
            delete[] testResults;

            name = other.name;
            numTests = other.numTests;
            testResults = new double[numTests];

            for (int i = 0; i < numTests; i++) {
                testResults[i] = other.testResults[i];
            }
        }

        return *this;
    }

    // 3. Destructor
    ~Patient() {
        delete[] testResults;
    }

    void setTestResult(int index, double value) {
        testResults[index] = value;
    }

    void print() {
        cout << name << ": ";

        for (int i = 0; i < numTests; i++) {
            cout << testResults[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Patient p1("Mary", 3);
    p1.setTestResult(0, 98.5);
    p1.setTestResult(1, 87.2);
    p1.setTestResult(2, 91.0);

    // Copy constructor
    Patient p2 = p1;

    // Assignment operator
    Patient p3;
    p3 = p1;

    p2.setTestResult(1, 50.0);
    p3.setTestResult(2, 70.0);

    cout << "p1: ";
    p1.print();

    cout << "p2: ";
    p2.print();

    cout << "p3: ";
    p3.print();

    return 0;
}