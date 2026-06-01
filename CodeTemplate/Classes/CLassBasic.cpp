#include <iostream>
#include <string>
using namespace std;

// *****************************    Basic class    ************************************************
/*
                                private/public members
                                default constructor
                                class methods
                                static member and static method (shared across all objects)
***********************************************************************************************/


class Customer {
private:
    int id;
    string fName;
    string lName;
    string email;
    double bal;

    static int rating;

public:
    // Default constructor
    Customer() 
        : id(0), fName(""), lName(""), email(""), bal(0.0) {}

    // Setter
    void addCustomer(int id, string fn, string ln, string em, double b) {
        id = id;
        fName = fn;
        lName = ln;
        email = em;
        bal = b;
    }

    // Getter
    int getCustomerId() const {
        return id;
    }

    // Display method
    void displayCustomer() const {
        cout << "Customer ID: " << id << endl;
        cout << "Name: " << fName << " " << lName << endl;
        cout << "Email: " << email << endl;
        cout << "Balance: $" << bal << endl;
    }

    // Static method
    static void displayRating() {
        cout << "Customer Rating: " << rating << endl;
    }
};

// Static member initialized outside class
int Customer::rating = 5;

int main() {
    Customer c;

    c.addCustomer(1, "John", "Doe", "johnD@cpp.com", 200.28);

    cout << "Customer ID: " << c.getCustomerId() << endl;

    c.displayCustomer();

    Customer::displayRating();

    return 0;
}