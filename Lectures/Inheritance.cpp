# include <iostream>
using namespace std;

// inheritance
// Base class (also called parent so superclass)
class Animal {
private:
	int pv = 13; // private: accessible only inside Animal

protected:
	int pt = 19; // protected: accessible in derived classes

public:
	void speak() {
		cout << "Animal speaks\n";
	}

	void eat() {
		cout << "Animal eats Animal food\n";
	}
};

// Derived class (also called child or subclass)
class Dog: Animal {

	
protected:
	int pt = 19; // protected: accessible in derived classes

public:
	void f() {
		//cout << pv << endl; // Error: cannot access private memeber
		cout << pt << endl; // OK: protected members are accessible
	}

	void bark() {
		cout << "Animal speaks\n";
	}

	void eat() { // function overriding
		cout << "Dogs eats Dog food\n";
	}

	void speak() { 
		cout << "Dogs barks" << endl;

		// Call parents (Animal) version
		Animal::speak(); // Accessing base function Parent function version
	}
};

// ============================================================
// Access control in inheritance

class Base {
public:
	int publicV;    // accessible everywhere

protected:
	int protectedV; // accessible in derived classes too

private:
	int privateV;    // accessible only within Base
};

//---------------------
// Most common inheritance type (public inheritance)
// Maintancins the original access levels of base class members
class DrivedPub : public Base {
	//publicV remains public
	// protectedV remains protected
	// privateV is NOT accessible
};

// Protected inheritance
// Public members of Base become protected in the derived class
//Accessible inside derived classes, but NOT outside through object
class DrivedProt : protected Base {
	//publicV becomes protected
	// protectedV remains protected
	// privateV is NOT accessible
};

// Protected inheritance
// Public members of Base become protected in the derived class
//Accessible inside derived classes, but NOT outside through object
class DrivedPriv : protected Base {
	//publicV becomes private
	// protectedV becomes private
	// privateV is NOT accessible
};

//============================================================
// Constrtuctor and destructors Are inherited behavior-wise
// (Base constructor runs first, destructors runs last)

class BaseClass {
public:
	BaseClass() {
		cout << "in BaseClass constructrs" << endl;
	}
	~BaseClass() {
		cout << "in BaseClass destrctor" << endl;
	}
};

class DerivedClass: public BaseClass {
public:
	DerivedClass() {
		cout << "in DerivedClass constructrs" << endl;
	}
	~DerivedClass() {
		cout << "in DerivedClass destrctor" << endl;
	}
};

/*
* Polymorphism ( menas "many forms")
*
* 1) Function Overloading
* 2) Operator Overloading
* 3) Templates (functions and class templates)
*
* Runtime Polymorphism (Dynamic Polymorphism)
* Achieved using inheritance + vitual functions (functiong overriding)
* The function that gets called depends on the object's type
*
* =============================================================
* Vitual functions
* A function decleared in a base class that is meant to be
* over riddend in derviced classes

*/

class Shape {
public:
	virtual void draw() {
		cout << "Drawing a shape\n";
	}
};
class Circle : public Shape {
public:
	virtual void draw() override { // override impoves readablility and safety
		cout << "Drawing a circle\n";
	}
};
class Rectangle : public Shape {
public:
	virtual void draw() {
		cout << "Drawing a rectangle\n";
	}
};

// -------------------------------------------------------

int main() {
	// Basic inheritance example
	Dog myDog;
	myDog.f();      // Derived class accessing protected member
	myDog.speak();  // Inherited from base class
	myDog.bark();   // Defined in Dog
	myDog.eat();      // Overridden function
	cout << endl;

	// ====================================================================
	// Constructor and destructor order demonstration
	DerivedClass obj;
	cout << endl;

	// ===========   Runtime polymorphism (late binding)   ============================
	Shape* s1 = new Circle();
	Shape* s2 = new Rectangle();

	
	s1->draw(); // Calls Circle:: draw() -> these aer called during runtime
	s2->draw(); // Calls Rectangle:: draw()
	cout << endl;


	delete s1;
	delete s2;

	return 0;
}