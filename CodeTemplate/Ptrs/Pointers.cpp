#include <iostream>
using namespace std;

// Gloable Var
int x = 19;
int y = 10;
int num[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

int main() {
	// Pointer to variable
	int* ptr = &x;

	cout << *ptr << endl;  // 10

	// Pointer to array
	int arr[3] = { 10, 20, 30 };
	ptr = arr;

	cout << ptr[1] << endl;  // 20


	// Dynamic integer
	int* ptr2 = new int;
	*ptr2 = 100;

	delete ptr2;

	// Dynamic array
	int* ptr3 = new int[10];

	for (int i = 0; i < 10; i ++) {
		ptr3[i] = num[i];
		cout << " " << ptr3[i] << ", ";
		if (i == 9) {
			cout << "\n";
		}
	}

	delete[] ptr3;

	// Array of pointers
	int a = 10;
	int b = 20;

	int* ptrArr[2];

	ptrArr[0] = &a; // --> a
	ptrArr[1] = &b; // --> b
	ptrArr[0] = ptrArr[1]; // assing --> ptr of --> b

	cout << *ptrArr[0] << endl;
	return 0;
}