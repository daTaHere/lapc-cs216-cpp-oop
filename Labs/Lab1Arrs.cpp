#include <iostream>
using namespace std;

// <problem 1>
// process uses input, print orginal order, reverse elements in-place, print new order, and clean/release up memory.
void reverseArray(int* arr, int size) {

	// prompt user input
	cout << "Enter a Number: ";

	// assign input values to array by index ASC
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "Original Array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
	cout << endl;

	int* left = arr; // temp var pointing frist memory location of arr
	int* right = arr + size - 1; // temp var pointing to last memory location of arr

	while (left < right) {
		int tmp = *left; // temp var assign current location left 
		*left = *right; // assign left current right memory location
		*right = tmp; // assign right the location in tmp
		++left; // increament left to next memory location
		--right; // decrement right to prev memory location
	}

	// print values to console
	cout << "Reverse Array: " << endl;
	for (int i = 0; i < 8; i++) {
		cout << arr[i];
	}
	cout << endl;
}

// <problem 2>
// swaps reference locations of two pointer vars
void swapValues(int* a, int* b) {
	// print original values to console
	cout << "Original Values: " << *a << " " << *b << endl;

	int tmp = *a; // temporary var 
	*a = *b; // point a to b
	*b = tmp; // point b to a

	// print swap values to console
	cout << "Swapped Values: " << *a << " " << *b << endl;
}


int main() {

	// ------------ Problem 1  ---------------------
	// initilize var const
	int size = 8;
	// allocate dynmaic arry for 8 ints
	int* arr = new int[size]; 

	// call reverseArray
	reverseArray(arr, size);

	// free up memory
	delete[] arr;


	// ---------------  Problem 2  --------------------
	int x, y;

	// prompt user input
	cout << "Enter 2 Integers: ";
	cin >> x >> y;

	// call swapValues
	swapValues(&x, &y);


	//------------------ Problem 3  ----------------------
	int* numbers[5];

	// allocate space for each element and multiply them by 10
	for (int i = 0; i < 5; i++) {
		numbers[i] = new int((i + 1) * 10); // new --> allocate memory on heap assign value +1 * 10
	}
	// print out each element
	for (int i = 0; i < 5; i++) {
		cout << *numbers[i] << " ";
	}
	// delete allocated space for each element
	cout << endl;
	for (int i = 0; i < 5; i++) {
		delete numbers[i];
	}

	return 0;
}
