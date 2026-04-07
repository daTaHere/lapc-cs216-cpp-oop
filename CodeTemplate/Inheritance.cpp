/*  ---------  base Class /  Inheritance / virtual function   ---------------
* 
	-***- Design a ~(Base Class)~ for a general account and a derived class with -***-
		 extended behavior.

		* ( Base Class ) with Balance and basic operations
		* ( Derived Class)  that modifies behavior ( e.g, adds interest during deposit )
		* ( Vitual function ) to ensure correct behavior through base pointers.
		* implement a ( Friend function ) that transfers between two objects.
	
    -***---------- Questions --------------***-
		* Why vitual functions necessary?
			- They allow the derived class to override the base functions behavior
			- Without them, the base version would always be used, making the class less flexible

		* Why is the Transfer function better implemented as a friend function
		  rather than a class method?
			- It needed access to both objects' private data.
		    - It allows flexiblity to use the function with simular but seperate classes
*/

#include <iostream>

using namespace std;

class Bank {
// Hide the critical data
private:
	double balance;
public:
	// default constructor
	Bank(const double b) { balance = b; }

	// setter
	virtual void deposit( const double amount) { // override in derive classes.
		balance += amount;
	}
	void withdraw(const double amount) {
		if ( balance > amount ) {
			balance -= amount;
		}
	}
	
	// Getter 
	void displayBalance() const {
		cout << "Balance: $" << balance << endl;
	}

	friend void transfer(Bank& a, Bank& b, const double amount);

};

class Saving : public Bank {

public:
	// default constructor 
	Saving(double b) : Bank(b) {}

	// add 5% intrest
	void deposit(const double amount) {
		Bank :: deposit( amount * 1.05); // Execute base class to access private member.
	}
};

void transfer( Bank& a, Bank& b, const double amount) {
	// use the class function to access private data
	a.withdraw(amount);
	b.deposit(amount);
}


int main() {
	cout << "---- New Bank acct: b1  ------" << endl;
	Bank b1(100.00);
	cout << "b1 -> ";
	b1.displayBalance();
	cout << endl;

	b1.deposit(100.00);
	cout << "-------  b1 after deposit ----------" << endl;
	cout << "b1 -> ";
	b1.displayBalance();
	cout << endl;

	b1.withdraw(50.00);
	cout << "-------  b1 after $50 withdraw ----------" << endl;
	cout << "b1 -> ";
	b1.displayBalance();
	cout << endl;

	Saving s1(100.00);
	cout << "-------  New Saving acct: s1  ----------" << endl;
	cout << "s1 -> ";
	s1.displayBalance();
	cout << endl;

	s1.deposit(100.00);
	cout << "-------  s1  after deposit ----------" << endl;
	cout << "s1 -> ";
	s1.displayBalance();
	cout << endl;

	cout << "------- transfer $5 from s1 to b1 ----------" << endl;
	// We are able to pass a base class and any derive class and it will not error.
	transfer(s1, b1, 5.00);
	cout << "b1 -> ";
	b1.displayBalance();
	cout << "s1 -> ";
	s1.displayBalance();
	cout << endl;

	cout << "------- Base ptr behavior ----------" << endl;
	// pointer of Bank type is still able to call deposit via vitual
	Bank* savePtr = new Saving(100.00);

	savePtr->displayBalance();
	savePtr->deposit(100.00);
	savePtr->displayBalance();
	
	delete	savePtr;

	return 0;
}