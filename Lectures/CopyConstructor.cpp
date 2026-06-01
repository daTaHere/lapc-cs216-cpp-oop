#include <iostream>

using namespace std;

class Student {
private:
	int id;
	int age;
public:
	// Default constructor
	Student() { id = 0; age = 0; }
	// parametrized constructor
	Student(int i, int a) { id = i; age = a; }
	// Getters
	// Copy constructor --copies from s
	Student(const Student& s) {
		id = s.id;
		age = s.age;
	}
	int getID() const { return id; }
	int getAge() const { return age; }
	// Setter
	void setAge(int a) { age = a; }
	// Member function
	void print();
	// Friend function
	friend void printFriend(Student s);
};

void Student::print() {
	cout << "st_id = " << id << " st_age = " << age << endl;
}

void printFriend(Student s) {
	cout << s.id << " " << s.age << endl;
}

//==============================================================
// INT ARRAY CLASS (Dynamic Memory Example)
class intArray {
private:
	int size;
	int* arrayPtr;
public:
	// Defaul tconstructor
	intArray() {
		size = 0;
		arrayPtr = NULL;
	}
	// Paramaterized constructor
	intArray(int s, int v) {
		size = s;
		arrayPtr = new int[size];
		setValue(v);
	}

	// Copy constructor (Deep Copy)
	intArray(const intArray& oldArray);

	// Destructor (VERY IMPORTANT)
	~intArray() {
		delete[] arrayPtr;
	}
	// Member functions
	void printArray();
	void setValue(int v);

	// overload = opertor
	intArray operator=(const intArray& RHSArray);

};

void intArray::printArray() {
	for (int i = 0; i < size; i++) {
		cout << arrayPtr[i] << " ";
	}
	cout << endl;
};
void intArray::setValue(int v) {
	for (int i = 0; i < size; i++) {
		arrayPtr[i] = v;
	}
};



// copy constructor implementation (overload the constructor)
intArray::intArray(const intArray& oldArray) {
	size = oldArray.size;
	arrayPtr = new int[size];

	for (int i = 0; i < size; i++) {
		arrayPtr[i] = oldArray.arrayPtr[i];
	}
}

// Assignment operator (Deep Copy + Safety)
intArray intArray::operator=(const intArray& RHSArray) {
	// Handle self-assignment
	if (this != &RHSArray) {
		// Allocate new memory
		size = RHSArray.size;
		arrayPtr = new int[size];
		for (int i = 0; i < size; i++) {
			arrayPtr[i] = RHSArray.arrayPtr[i];
		}
	}
	return *this;
}

/*======================================================\
Rule of 3
If a class uses new, it must have :
// Copy constructor
// Assignment operator
// Destructor

*/



int main() {
	//=================== Student======================
	Student s1(10, 19); // Normal constructor is called here
	Student s2 = s1; // Copy constructor is called here

	cout << "s1.id = " << s1.getID() << ", s1.age = " << s1.getAge() << endl;
	cout << "s2.id = " << s2.getID() << ", s2.age = " << s2.getAge() << endl;

	cout << "=======================\n" << endl;

	s2.setAge(21);

	cout << "s1.id = " << s1.getID() << ", s1.age = " << s1.getAge() << endl;
	cout << "s2.id = " << s2.getID() << ", s2.age = " << s2.getAge() << endl;



	// Assinment op
	Student s3;
	s3 = s1;

	cout << " =======================\n" << endl;

	cout << "s1.id = " << s1.getID() << ", s1.age = " << s1.getAge() << endl;
	cout << "s3.id = " << s3.getID() << ", s3.age = " << s3.getAge() << endl;

	cout << " =======================\n" << endl;

	s3.setAge(23);
	cout << "s1.id = " << s1.getID() << ", s1.age = " << s1.getAge() << endl;
	cout << "s3.id = " << s3.getID() << ", s3.age = " << s3.getAge() << endl;

	cout << " =======================\n" << endl;

	//===================== intArray  ============================

	intArray a1(5, 19);
	intArray a2 = a1;
	a1.printArray();
	a2.printArray();
	cout << "====================" << endl;
	a2.setValue(21);
	a1.printArray();
	a2.printArray();
	cout << "====================" << endl;
	intArray a3;
	a3 = a1;
	a1.printArray();
	a3.printArray();
	cout << "====================" << endl;
	a3.setValue(13);
	a1.printArray();
	a3.printArray();



	return 0;
}