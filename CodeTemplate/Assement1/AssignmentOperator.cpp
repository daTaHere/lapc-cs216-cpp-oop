/*

 ---- ***  Expand class to include a properly implemented ~ Assignment Operator ~ . ------
	* Correctly handle ~(self-assignment)~ (LHS & RHS refer to the same object.
	* Properly handle dynamic memory ( no leak not double deletion ).
	* Object must remain valid in all cases
	
 --- *** Question *** ------
	* What can go wrong if ~(self-assignment)~ is not handled.
	  - If self-assignment is not handled, the object may delete its own memory before copying from it.
	  - That can cause data loss, invalid memory access, or undefined behavior.

*/

#include <iostream>

using namespace std;

const char defaultStr[] = "Hello world";

class MyString {

private:
	char* str;

public:

	MyString(const char* input = defaultStr) {

		if (input == nullptr || strlen(input) == 0) {
			input = defaultStr;
		}

		int len = strlen(input) + 1;
		str = new char[len];
		strcpy_s(str, len, input);

	};

	// Copy Constructor
	MyString(const MyString& s) {
		int len = strlen(s.str) + 1;
		str = new char[len];

		strcpy_s(str, len, s.str);
	};

	// Assignment operatot (deep Copy + Safty)
	MyString operator=(const MyString& RHSArray) {
		// Handle self-assignment
		if (this != &RHSArray) {
			// Free old memory
			delete[] str;

			//Allocate new memory
			int len = strlen(RHSArray.str) + 1;
			str = new char[len];

			strcpy_s(str, len, RHSArray.str);

			/* --- Manual Deep Copuy
				for (int i = 0; i < len; i++) {
					str[i] = RHSArray.str[i];
				}
			*/
		}

		return *this;
	}

	// destructors
	~MyString() { delete[] str; };

	void printString() {
		cout << str << endl;
	};
};

int main() {

	MyString s1;
	MyString s2("Test Assignment Operator");
	cout << "s1 ";
	s1.printString();
	cout << "s2 ";
	s2.printString();

	cout << "\n============== Assingment Operator  ==============\n";
	s1 = s2;
	cout << "s1 ";
	s1.printString();
	cout << "s2 ";
	s2.printString();


	s1 = s1;
	cout << "s1 ";
	s1.printString();

}