#include <iostream>
#include <string>
using namespace std;

//--------- define class -----------------
class Customer {

private:
	int customerId;
	string firstName;
	string lastName;
	string email;
	double balance;
	static int rating;

public:
	// default Constructor
	Customer() {} 
	// parameterized Constructor
	Customer(int id, string fName, string lName, string em)
		: customerId(id), firstName(fName), lastName(lName), email(em) {}
	// member initialize Custructor
	Customer( int id, string fName, string lName, string em = "www.cppopp@cs216.com", double b = 0.0) 
		: customerId(id), firstName(fName), lastName(lName), email(em), balance(b) {}

	// define static function
	static void displayRating() {
		cout << "Customer Rating: " << rating << endl;
	}

	// Setter (mutators)
	void addCustomer(int id, string fName, string lName, string em, double b) {
		customerId = id;
		firstName = fName;
		lastName = lName;
		email = em;
		balance = b;
	}
	// Getters (assessors) - marked const since they do not modify object
	int getCustomerId() const {
		return customerId;
	}

	// class method to print members
	void displayCustomer() const {
		cout << "Customer ID: " << customerId << " Name: " << firstName << " " << lastName << " email : " << email << " balanace : $" << balance << endl;
	}

	// friend function signature
	friend void getCustJohn(const Customer& c);
};
// init static member
int Customer::rating = 5;

// check customers for first name John
void getCustJohn(const Customer& c) {
	if (c.firstName == "John") {
		cout << "John is a customer." << endl;
	}
	else
	{
		cout << "No John here." << endl;
	}

}


int main() {
	// init Customer
	Customer c;

	// hydrate object
	c.addCustomer(1, "John", "Doe", "johnD@c++.com", 200.28);

	// Pointer to customer object
	Customer* custPtr = &c;

	// execute getter method
	int custId = c.getCustomerId();
	// excute display method
	c.displayCustomer();
	
	// Create array of customer objects
	Customer customers[2]{
		{2, "Jane", "Doe", "janeD@c++.com", 228.82 }, 
		{1, "Billy", "Sue", "billyS@c++.com", 700.22 }
	};

	// display members of customer array
	for (int i = 0; i < 2; i++) {
		customers[i].displayCustomer();
	}

	// filter customer's for first name John
	for (int i = 0; i < 2; i++) {
		getCustJohn(customers[i]);
	}

	// filter object verify John is found
	getCustJohn(c);

	// execute static method
	Customer::displayRating();

	return 0;
}