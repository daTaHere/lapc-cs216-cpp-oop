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
	int* nums;

public:
	intArray(int s) {
		size = s;
		nums = new int[size]{};
	}

	~intArray() { delete[] nums; };

	// Getter
	void setIntArray( const int idx, const int value) {
		if (idx < 0 || idx >= size) {
			cout << "Position value is out of bounds!!!\n" << endl;
			return;
		}
		nums[idx] = value;
	}

	// Setter
	void printArray() const {
		cout << " :";
		for (int i = 0; i < size; i++) {
			cout << " " << *(nums + i);
		}
		cout << endl;
	}

	int getMax() const {

		int* maxValue = nums;
		for (int i = 1; i < size; i++) {
			if ( *maxValue < nums[i] ) {
				maxValue = &nums[i];
			}
		}
		return *maxValue;
	};

	friend void swapArray( intArray& a, intArray& b );

};

void swapArray( intArray& a, intArray& b ) {
	int* temp = a.nums;
	a.nums = b.nums;
	b.nums = temp;

	int t = a.size;
	a.size = b.size;
	b.size = t;
};

int main() {

	intArray a1(3);
	a1.setIntArray(0,8);
	a1.setIntArray(1, 2);
	a1.setIntArray(2, 5);

	cout << "a1";
	a1.printArray();


	intArray a2(5);
	a2.setIntArray(0, 28);
	a2.setIntArray(1, 12);
	a2.setIntArray(2, 85);
	a2.setIntArray(3, 200);
	a2.setIntArray(4, 82);

	cout << "a2";
	a2.printArray();
	cout << "a1 Max Value: " << a1.getMax() << endl;
	cout << "a2 Max Value: " << a2.getMax() << endl;

	cout << "\n==============  swap  ================\n" << endl;

	swapArray(a1, a2);

	cout << "a1";
	a1.printArray();

	cout << "a2";
	a2.printArray();
	cout << "a1 Max Value: " << a1.getMax() << endl;
	cout << "a2 Max Value: " << a2.getMax() << endl;

}