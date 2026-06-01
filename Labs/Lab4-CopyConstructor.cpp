#include <iostream>
using namespace std;
// PART 1: BadArray
// Fix a Broken Class
class BadArray {
private:
	int size;
	int* data;
public:
	BadArray(int s) {
		size = s;
		data = new int[size];
	}


	// ********************************************************************************************************
	//  Copy constructor  <--- Need to copy the object or else it points to the same memory space
	BadArray(const BadArray& bArr) {
		size = bArr.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = bArr.data[i];
		}
	}

	~BadArray() { // < clean up garbage 
		delete[] data;
	}

	// ********************************************************************************************************

	void setAll(int value);
	void print();
};

void BadArray::setAll(int value) {
	for (int i = 0; i < size; i++)
		data[i] = value;
}
void BadArray::print() {
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}


//----------------------------------------
// PART 2: GradeBook
//
//Create Class GradeBook
//Implement:
// Constructor:Allocate array
// Copy constructor :Deep copy
// Destructor :Free memory
// Assignment operator :
//Handle :
//Self - assignment
//Memory cleanup
class GradeBook {
private:
	int studentCount;
	int* grades;
public:
	// constructors
	GradeBook(int stdCnt) {
		studentCount = stdCnt;
		grades = new int[stdCnt];
	}
	// copy constructor 
	GradeBook(const GradeBook& gBook) {
		studentCount = gBook.studentCount;
		grades = new int[studentCount];
		for (int i = 0; i < studentCount; i++) { // <--- Set grades for new GradeBook object
			grades[i] = gBook.grades[i];
		}
	}
	// destructor
	~GradeBook() {
		delete[] grades; // <-- clean up
	}

	// operator=
	GradeBook& operator=(const GradeBook& RHSArray) { // <=== = Overload '="
		if (this != &RHSArray) { // < --------------- conditional check not the same object "&RHSArray [memory location]"
			studentCount = RHSArray.studentCount;
			grades = new int[studentCount];

			for (int i = 0; i < studentCount; i++) {
				grades[i] = RHSArray.grades[i];
			}
		}
		return *this; // <---- return updated object
	}

	// =========================
	void setAllGrades(int value);
	void setGrade(int index, int value);
	void printGrades();
};

void GradeBook::setAllGrades(int value) {
	for (int i = 0; i < studentCount; i++) // ==> Assign all test the same Value
		grades[i] = value;
}

void GradeBook::setGrade(int index, int value) {
	grades[index] = value; // === Modify one test grade
}

void GradeBook::printGrades() {
	for (int i = 0; i < studentCount; i++) // =====> cout Elements of grades Array
		cout << grades[i] << " ";
	cout << endl;
}

//=============================================
// PART 3: Patient (Real-Life Example)
//A hospital stores patient test results dynamically.
//Each patient has multiple test results ? must use dynamic memory.
//------------------------------------
//Constructor
//Initialize name
//Allocate dynamic array
//Copy Constructor
//Deep copy test results
//Destructor
//Free memory
//Operator =
//Handle:
//Self - assignment
//Delete old memory
//Deep copy
class Patient {
private:
	string name;
	int numTests;
	double* testResults;
public:
	// ============== CONSTRUCTORS  =================
	// Default
	Patient() {
		name = "";
		numTests = 0;
		testResults = nullptr;
	};
	// params 
	Patient(string n, int t) {
		name = n;
		numTests = t;
		testResults = new double[numTests];
	};
	// Copy constructor ===> DEEP COPY
	Patient(const Patient& p) {
		name = p.name;
		numTests = p.numTests;

		testResults = new double[numTests];
		for (int i = 0; i < numTests; i++) {
			testResults[i] = p.testResults[i];
		}
	}
	// Destructor 
	~Patient() {
		delete[] testResults; //<---- Clean up
	}
	// operator=
	Patient& operator=(const Patient& RHSArray) { // <==== Overload '="
		if (this != &RHSArray) {  // < --------------- conditional check not the same object "&RHSArray [memory location]"
			name = RHSArray.name;
			numTests = RHSArray.numTests;

			testResults = new double[numTests];
			for (int i = 0; i < numTests; i++) {
				testResults[i] = RHSArray.testResults[i];
			}
		}
		return *this;
	}

	void setTestResult(int index, double value);
	void print();
};

void Patient::setTestResult(int index, double value) {
	testResults[index] = value;
}

void Patient::print() {
	cout << name << ": ";
	for (int i = 0; i < numTests; i++) {
		cout << testResults[i] << " ";
	}
	cout << endl;
}

//================================================
int main() {
	// PART 1: BadArray
	//Create two objects and print both array and understand the issue
	BadArray a1(5);
	a1.setAll(10);
	BadArray a2 = a1;
	a2.setAll(20);

	cout << " =====   a1  ===========" << endl;
	a1.print();
	cout << " =====   a2  ===========" << endl;
	a2.print();

	//---------------------------------------------------------
	// PART 2: GradeBook
	GradeBook g1(5);
	g1.setAllGrades(80);
	GradeBook g2 = g1;
	g2.setGrade(0, 100);
	cout << " =====   g1  ===========" << endl;
	g1.printGrades();
	cout << " =====   g2  ===========" << endl;
	g2.printGrades();
	//-------------------------------------------
	// PART 3: Patient (Real-Life Example)
	//test case
	Patient p1("Mary", 3);
	p1.setTestResult(0, 98.5);
	p1.setTestResult(1, 87.2);
	p1.setTestResult(2, 91.0);
	Patient p2 = p1;
	p2.setTestResult(1, 50.0);
	cout << " =====   p1  ===========" << endl;
	p1.print();
	cout << " =====   p1  ===========" << endl;
	p2.print();
}