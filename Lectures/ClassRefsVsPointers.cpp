#include <iostream>
using namespace std;


//====================  Classes   =======================

class Dog {
	int age;

public:
	Dog(int a) : age(a) {}

	Dog& setAge(int a) { // Return a reference to the same object
		age = a;
		return *this; // return the object
	}

	//Dog setAge2(int a) {
	//	age = a;
	//}
	int getAge() { return age; }
};

class Cat {
	int age;
public:

	Cat(int a) : age(a) {}
	Cat* setAge2(int a) { // Returns a pointer
		age = a;
		return this;
	}
	int getAge() { return age; }

};

// Method chaning: calling multiple methods on the same object in a single 
class M {
private:
	int value;
public:
	M(int v) : value(v) {}
	// Returning *this allows method chaining
	void setValue(int v) {
		value = v;
	}
	void add(int val) {
		value += val;
	}
	void print() {
		cout << "Value: " << value << endl;
		cout << "=============  None reference object ===================\n" << endl;
	}
};

class MC {
private:
	int value;
public:
	MC(int v) : value(v) {}
	// Returning *this allows method chaining
	MC& setValue(int v) {
		value = v;
		return *this; // Returning the current object
	}
	//MC& return the reference to the same object rather than a copy
	MC& add(int val) {
		value += val;
		return *this;
	}
	void print() {
		cout << "Value: " << value << endl;
	}
};

/*
	Const member functions do not modify the object's
	and objects decleared as const can still call these functions
*/

class Rec {
private:
	int width, height;

public:
	Rec(int w, int h): width(w), height(h) {}
	// if we do not define as const then any const object cannot call it.
	int area() const { // Const function (does not modify any member var
		return width * height;
	}
	void setWidth(int w) { // Non-const function --> we need to  mutate
		width = w;
	}
	int geWidth() const { // 
		return width;
	}
};

// ======== mutable member value =============

class L {
private:
	int i = 0;
	mutable int lCount; // Mutabel allows modification in a const object
public:
	L() : lCount(0) {}

	void log() const {
		//i++;
		lCount++;  // Allowed lCount is mutable
		cout << "Log called " << lCount << " times\n";
	}
};

//========================================================

//============= diff kind of variable  =============================
class V {
private:
	int NorVar;               //1) Not mutable (normal variable )
	const int Constval = 10;  //2) Must be initiaized 
	mutable int mutVar = 0;   //3) Mutable variable
	static int statVar;       //4) One shared copy for all objects
	volatile int volVar;      //5) Prevents compler optimizations
public:
	V(int val) : NorVar(val) { statVar++; } // Must be init in construct; 
	void setValue(int v) { NorVar = v; } // Allowed
	void inc() const {
		register int speed = 100; //6) Hit to compiler to store the varibale in a const functions!
	}
	//NorVar++; // Error: Cannot modify a member 
	static int getCount() { return statVar; } //Static function
	int getValue() { return volVar; } // Always reads fresh value from memory
	
};
int V::statVar = 0; // Static variable must be defined outside the class



int main() {
	int a = 10;
	int b = 1;

	int& ref = a; // reference must bind to an object
	int* ptr = &a; // pointer stores address of an object

	cout << "Initial values\n";
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "\nAddresses\n";
	cout << "&a =" << &a << endl;;
	cout << "ptr =" << ptr << endl;
	cout << "&ref =" << &ref << " (same as &a)\n" << endl;

	//========================================================
	// Modify using reference
	ref = 13; // change directly
	cout << "\nAfter ref = 13\n";
	cout << "a = " << a << endl;

	// Modify using reference
	*ptr = 19; // change directly
	cout << "\nAfter ref = 19\n";
	cout << "a = " << a << endl;

	//========================================================
	// Pointer can point to antoher object
	ptr = &b;
	*ptr = 50;

	cout << "\nPointer can reassigned to b)\n";
	cout << "b = " << b << endl;

	//========================================================
	ref = b; // copies values of b into a

	cout << "\nref = b (reference does NOT rebind)\n";
	cout << "a = " << a << endl;

	cout << "\nref = 100\n";
	cout << "a = " << a << endl;

	//========================================================

	Dog myDog(10);
	Cat myCat(9);

	Dog& dogRef = myDog;  // dogRef is reference to myDog
	Cat* catPtr = &myCat; // catPtr is a pointer to myCat

	dogRef.setAge(11); //Modify myDog directly
	catPtr->setAge2(15); // modify myCat using pointer
	cout << endl;
	cout << "dog'age = " << dogRef.getAge() << endl;
	cout << "Cats' age = " << catPtr->getAge() << endl;
	myDog.setAge(2);
	cout << "dog'age = " << myDog.getAge() << endl;
	/*
	  A refernece is simply another name for and exisiting varibale,
	  a point is a varibale that stores an address
	  ==========================================================
	*/

	// Method chain: calling multiple methods on the same object in a single statement
	M o(10);
	o.setValue(20);
	o.add(8);
	o.print();

	//========================================================
	MC obj(10);
	// Method chaining: calling multiple memtods in a single statement
	obj.setValue(20).add(5).print();

	// testing const
	Rec r(1,2);
	cout << "Area: " << r.area() << endl; // Allowed
	cout << "Width: " << r.geWidth() << endl;

	const Rec r1(10, 5); // A const object
	cout << "Area: " << r.area() << endl; // Allowed
	cout << "Width: " << r.geWidth() << endl;

	//r1.setWidth(15); // Error: cannot mutate const object
	// 
	//===========  test mutable ======================

	const L logger; // Declaring a const object

	logger.log(); // Allow (modifies mutable member)
	logger.log(); // Allow Again

	//logger.setLogCounter(5); // ERROR: Cannot call non-const functions on an const object

	return 0;

}
