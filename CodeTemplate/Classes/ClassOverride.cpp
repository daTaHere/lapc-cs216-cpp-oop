#include <iostream>
#include <string>
using namespace std;

// *****************************    Custom Class    ************************************************
/*
                                Default Constructor
                                Constructor overloads ( - Overloading  *Same function name -->  Different parameter list )
                                Parameterized Constructors
                                Full Constructor (Initializer List)
***********************************************************************************************/
class Customer {
private:
    int id;
    string fName;
    string lName;
    string email;
    double bal;

public:
    // Default constructor
    Customer() 
        : id(0), fName(""), lName(""), email(""), bal(0.0) { }

    // Parameterized constructor
    Customer(int id, string fn) 
        : id(id), fName(fn),  lName(""), email(""), bal(0.0) { }

    // Initializer list constructor
    Customer(int id, string fn, string ln, string em, double b)
        : id(id), fName(fn), lName(ln), email(em), bal(b) { }

    void displayCustomer() const {
        cout << id << " "
            << fName << " "
            << lName << " "
            << email << " "
            << bal << endl;
    }
};

int main() {
    Customer c1;
    Customer c2(1, "John");
    Customer c3(2, "Jane", "Doe", "janeD@cpp.com", 250.75);

    c1.displayCustomer();
    c2.displayCustomer();
    c3.displayCustomer();

    return 0;
}