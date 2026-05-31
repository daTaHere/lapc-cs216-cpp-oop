#include <iostream>

using namespace std;

// prototypes
void f1(int a, int b, int c);
void f2(int a, int b = 5, int c = 10);
//void f3(int a, int b, int c);
int add(int, int);

/*
-- FUNCTION OVERLOADING --
 Function overloading allows multople function with the same name but different parameter lists
 the comiler determines which one to call based on arguments.
*/

//=========================================
// default arguments
void f1(int a, int b, int c = 10) {
	cout << a << " " << b << " " << c << endl;
}

void f2(int a, int b, int c) {
	cout << a << " " << b << " " << c << endl;
}

// ---------  wrong default order  --------------
/* 
void f3(int a, int b=20, int c) {
	cout << a << " " << b << " " << c << endl;
}*/
// ------------------------------------------

// Add two integers
int add(int x, int y) {
	return x + y;
}

// Add three integers
int add(int x, int y, int z) {
	return x + y + z;
}

// Add two doubles
double add(double x, double y) {
	return x + y;
}

// Add in and  doubles
double add(int x, double y) {
	return x + y;
}

//Concatenate two strings
string add(string s1, string s2) {
	return s1 + s2;
}
// Note: You cannot overload by only changing the return type
// e.g, int add(int,int) and doulbe add(int,int) is invalid

// ====================================
// 2. ACCESS MODIFIERS
// Demonstrates private and public members in a class
// ====================================
class ClassA {
	int m1; // private by default
public:
	int m2; // public member
private:
	int m3; // explicityly private (not accessible outside)
};

// ====================================
// 3. GETTERS AND SETTERS
// Encapsulation: keep data private, provide public functions
// to access tand modify its safely
// ====================================

class Point {
private:
	int x;
	int y;
public:
	// Setters (mutators)
	void setX(int n) { x = n; }
	void setY(int y) { this->y = y; } // 'this' resolves name conflict

	// Getters (accessors)
	int getX() { return x; }
	int getY() { return y; }
};

// ====================================
/*      CONSTRUCTORS
 1. A constructor is a special public function with the same name as the class.
 2. It does not return anything (not even void).
 3. It can take arguments to initialize objects with specific values.
 4. You cannot call a constructor directly; it is automatically invoked
    when an object is created.
 5. A constructor with no arguments is called a default constructor.
 6. If you don't define a constructor, the compiler provide a default one.
 7. If you define one or more constructors with arguments, you must explicitly
    define a default constructor if you want one. ( over loading the constructor )
*/

// ====================================
class Class3 {
private:
	int x;
	double y;
	int z;
	string s;
public:
	//1. Default constructor
	Class3() {
		cout << "Inside default constructor\n";
	};

	// 2. Constructor with one argument
	Class3(int v) {
		x = v;
	};
	// 3. Constructor with two arguments (uniform initializations)
	Class3(int v1, double v2) : x{ v1 }, y{ v2 } {};
	// 4. Constructor with three arguments (preferred)
	//Class3(int v1, double v2, int v3) : x(v1), y(v2), z(v3) {};

	// Constructor with default parameters
	Class3(int v1, double v2, int v3 = 30, string v4 = "no") : x(v1), y(v2), z(v3), s(v4) {};

	// Setter and Getter for x 
	void setX(int v) { x = v; }
	int getX() { return x; }

	// Print all memeber variables
	void print() {
		cout << "x = " << x << " y = " << y << "z = " << z << " s = " << s << endl;
	}

};
//========================================
/*
 5. MAIN FUNCTION
 Test function overloading, access modifiers, getters/setters,
 and constructors
*/
//========================================================

int main() {
	f1(1, 2, 3);
	f1(1, 2);
	f2(1, 2, 3);
	f2(1);

	// --------------------------------
	// Function overloading
	// --------------------------------
	int i = 10, j = 20;
	double d1 = 10.0, d2 = 20.1;
	string s1 = "Hello", s2 = " C++ ";

	cout << "add(i, j) = " << add(i, j) << endl;
	cout << "add(i, j, 5) = " << add(i, j, 5) << endl;
	cout << "add(d1, d2) = " << add(d1,d2) << endl;
	cout << "add(i, d1) = " << add(i, d1) << endl;
	cout << "add(s1, s2) = " << add(s1, s2) << endl;

	// --------------------------------
	// Access modifiers
	// --------------------------------

	ClassA objA;
	objA.m2 = 100; // OK: m2 is public
	//objA.m1 = 10; // ERROR: m1 is private
	cout << "Public member m2 = " << objA.m2 << endl;

	// --------------------------------
	// Getters and Setters
	// --------------------------------
	Point p1;
	p1.setX(10);
	p1.setY(20);
	cout << "Point: x = " << p1.getX() << " , y = " << p1.getY() << endl;

	// --------------------------------
	// Getters and Setters
	// --------------------------------
	Class3 o1;  // default constructor
	Class3 o2(5); // single argument
	o2.print();
	o1.setX(19);
	o1.print();

	Class3 o3(10, 15.5, 20, "Yes"); // four arguments
	Class3 o4(10, 15.5, 20); // four arguments

	o3.print();
	o4.print();

	return 0;
}

