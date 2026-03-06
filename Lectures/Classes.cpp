#include <iostream>
#include <string>
using namespace std;

// ===============   1. STATIC MEMBERS    ====================
/*
  Static members belong to the class itself rather than any specific object.
  Static variables are shared among all instances of the clas.
  Static methods can be called without creating an instance.
*/
// ============================================================

class S {
private:
	static int count; // Static member variables (shared across all objects)
public:
	S() { count++; }; // Increment count whenever a new object is created

	static int getCount() {
		return count;
	}
};

// Initialize static variable outside the Class
int S::count = 0;

// ===============   2. STATIC MEMBERS    ====================
//	Friend functions can access privite members.
// ============================================================
class Car {
private:
	string make;
	string model;
	int year = 0;
	double price = 0;
public:
	// Constructor
	Car() {} // default constructor
	Car(string mk, string md, int y, double p) : make(mk), model(md), year(y), price(p) {}

	// Destructor
	~Car() {
		cout << "In destructor for " << make << " " << model << endl;
	}

	// Setter (mutators)
	void setYear(int y) { year = y; }
	// Getters (assessors) - marked const since they do not modify object
	int getYear() const { return year; }
	// Memeber function
	void displayCar() const {
		cout << make << " " << model << " " << year << " " << price;
	}
	// Friend function
	friend void dispNewCars(const Car& c);
	friend void dispNewCars2(const Car& c);
};

// Friend function: access private members directly
void dispNewCars(const Car& c) {
	if (c.year >= 2000)
		cout << c.make << " " << c.model << " " << c.year << " " << c.price << endl;
}

// Friend function: access via public member function
void dispNewCars2(const Car& c) {
	if (c.year >= 2000)
		c.displayCar(), cout << endl;
}

/*
  3. MAIN FUNCTION
  Demo: static members, construtors, destrucotrs, friends functions
  pointers, dynamic memory, pointers to objects, dynamic arrays of objects
*/
int main() {
	// ==========  Static member demo  ===============

	S s1, s2, c3; // Create 3 objects
	cout << "Total objects created: " << S::getCount() << endl;
	cout << "Total objects created: " << s1.getCount() << endl;

	// ========= Car class: constructors, setters, getters  ============
	Car aCar;
	aCar.setYear(2000);
	cout << "aCar year = " << aCar.getYear() << endl;

	Car myCar("VW", "ID4", 2021, 10000);
	myCar.displayCar();
	cout << endl;

	// ========= Friend functions  ===================
	Car cars[2] = { {"MB", "E350", 1996, 5000}, {"BMW", "328d", 2014, 7000} };
	cout << "\nAll cars: " << endl;
	for (int i = 0; i < 2; i++) {
		cars[i].displayCar();
		cout << endl;
	}

	cout << "\nNew cars (year >=2000) via friend function:" << endl;
	for (int i = 0; i < 2; i++) {
		dispNewCars(cars[i]);
	}

	cout << "\nNew cars via friend function using member display:" << endl;
	for (int i = 0; i < 2; i++) {
		dispNewCars2(cars[i]);
	}

	int n1 = 10;
	int* ptr1 = &n1;

	// Pointers to objects
	Car* carP1 = &myCar; // pointer to existing object
	cout << "carP1 year = " << carP1->getYear() << endl;
	// Dynamic creation of an object
	Car* carP2 = new Car("MB", "E350", 1990, 500);
	cout << "Dynamic car year = " << carP2->getYear() << endl;
	// Dynamic array of objects
	Car* carsP = new Car[2]{ {"BMW","328",2000,300}, {"MB","E350",2001,200} };
	cout << "Printing dynamic array of cars: " << endl;
	for (int i = 0; i < 2; i++) {
		cout << carsP[i].getYear() << " ";
	}
	cout << endl;
	// Clean up dynamic memory
	delete carP2;
	delete[] carsP;
	return 0;
}