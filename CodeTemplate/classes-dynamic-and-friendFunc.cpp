/*
 --- Design a Class that dynamically MANGAGES an array if intergers usings POINTERS
 Your class must have:
	 * a constructor
	 * a destructor
	 * 2 functions that set values and print the array
	 * a function to find the maxiumum value
	 * a FRIEND Function that swap the interanl data of 2 Objects without copying elements.
	 ( KEYWORD 2 Different OBJECTS)

	 Questions:
	 - Why swapping pointers is more efficient than copying Elements
	 ** It's more efficient because 
	 * 1 - We need only to update the pointer to the memory location of the arrays 1st elements.
	 This is much quicker than iterating through the array.
	 * 2 - We dont need to use extra memory for each element unlike when we copy each element and assign them mannually.
	 This is essitial for large arrays of over hundreds of thousands of records.

	 - How poor return structure can lead to logical errors
	 * Poor return structure makes it hard to debug where a problem occured, continue search or sort operations
	 even after output was found, return unexpected data causing errors.

*/
#include <iostream>

using namespace std;

class intArray {
private:
	int size;
	int* numArray;
public:
	intArray(int s){
		size = s;
		// Allocate memory dynamically
		numArray = new int[size] {};
	}
	~intArray() { delete[] numArray; };

	// Setter require user mannaul position and value input
	void setArray(int const idx, int const val) {
		if (idx < 0 || idx >= size) {
			cout << "Idx Position Value out of bounds!!!!\n" << endl;
			return;
		}
		numArray[idx] = val;
	}

	// Getter
	void printArray() const {
		cout << " :";
		for (int i = 0; i < size; i++) {
			cout << " " << *(numArray + i);
		}
		cout << endl;
	}

	void getMax() {
		int maxVal = *numArray;
		for (int i = 1; i < size; i++) {
			if (numArray[i] > maxVal) {
				maxVal = numArray[i];
			}
		}
		cout << "Max Value: " << maxVal << endl;
	}

	// Friend function.... Allow access to private memebers
	friend void swapArray(intArray& a, intArray& b);
};

// definded outside class but has access to memory if ref to objects are pass as arguments
void swapArray(intArray& a, intArray& b) {
	int* temp = a.numArray;
	a.numArray = b.numArray;
	b.numArray = temp;

	int s = a.size;
	a.size = b.size;
	b.size = s;
}


int main() {

	intArray a1(3);

	a1.setArray(0,2);
	a1.setArray(1, 5);
	a1.setArray(2, 8);

	cout << "a1";
	a1.printArray();
	a1.getMax();

	cout << "==============================================\n" << endl;

	intArray a2(5);

	a2.setArray(0, 28);
	a2.setArray(1, 25);
	a2.setArray(2, 2852);
	a2.setArray(3, 82);
	a2.setArray(4, 85);


	cout << "a2";
	a2.printArray();
	a2.getMax();
	cout << "==============================================\n" << endl;


	cout << "=================== BEFORE swap =====================\n" << endl;
	cout << "a1";
	a1.printArray();
	cout << "a2";
	a2.printArray();

	swapArray(a1, a2);
	cout << "=================== AFTER swap =====================\n" << endl;
	cout << "a1";
	a1.printArray();
	cout << "a2";
	a2.printArray();

	cout << "a1 ";
	a1.getMax();

	cout << "a2 ";
	a2.getMax();

	return 0;
}
