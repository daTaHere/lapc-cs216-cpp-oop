#include <iostream>
#include <string>
using namespace std;

// *****************************    Class extras  ************************************************
/*
                                Friend Function
                                Object dataTypes --> Array of Objects , Object Pointer
                                Runtime ( Heap Allocation) --> Dynamic Object, Dynamic Arr
                                Destructor --> Need to release memory ** no garbage collection for dangling memory
***********************************************************************************************/

class Customer {
private:
    int id;
    string fName;
    string lName;
    double bal;

public:
    Customer()
        : id(0), fName(""), lName(""), bal(0.0) {
    }

    Customer(int id, string fn, string ln, double b)
        : id(id), fName(fn), lName(ln), bal(b) {
    }

    // Clean up
    ~Customer() {
        cout << "Destroying Customer: " << fName << endl;
    }

    void displayCustomer() const {
        cout << id << " "
            << fName << " "
            << lName << " "
            << bal << endl;
    }

    // Friend function takes Ref to Object
    friend void checkBalance(const Customer& c);
};

// Friend function can access private members --> defined outside class allow access to class private fields by  dot notation
void checkBalance(const Customer& c) {
    if (c.bal > 100) {
        cout << c.fName << " has balance over 100" << endl;
    }
}

int main() {

    // Object pointer
    Customer c1(1, "John", "Doe", 200.25);
    Customer* ptr = &c1;
    // Access fields and method via Arrow -> notation
    ptr->displayCustomer();

    // Dynamic object   ( key *** new *** --> runtime addes to heap )
    Customer* dynCustomer = new Customer(2, "Jane", "Doe", 300.50);
    dynCustomer->displayCustomer();

    checkBalance(*dynCustomer);

    delete dynCustomer;

    // Array of objects
    Customer customers[2] = {
        Customer(3, "Billy", "Sue", 50.00),
        Customer(4, "Sara", "Lee", 150.75)
    };

    for (int i = 0; i < 2; i++) {
        customers[i].displayCustomer();
        checkBalance(customers[i]);
    }

    // Dynamic array of objects
    Customer* customerPtr = new Customer[2]{
        Customer(5, "Mike", "Smith", 90.00),
        Customer(6, "Anna", "Brown", 500.00)
    };

    for (int i = 0; i < 2; i++) {
        customerPtr[i].displayCustomer();
        checkBalance(customerPtr[i]);
    }

    delete[] customerPtr;

    return 0;
}