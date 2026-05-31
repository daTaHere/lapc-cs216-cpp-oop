/*
	Template:
		Class that stores a dynamically allocated character string.

	Class must include:
		* a constructor that a safely initializes the object even if input is invalid
		* destructor
		* a COPY CONSTRUCTOR
		* Function to display stored string
		* Proper initialization must guarantee that the object is alwasy in a vaild state

	Questions:
		* What happens in memory if a shallow copy is used
			Both objects point to the same memory location.
			If one object deletes it, the other is left with a dangling pointer.
		* Why leaving a pointer unintialized is dangerous
			It may contain a garbage address.
			Using it can cause crashes or undefined behavior.

*/
#include <iostream>

using namespace std;

const char defaultStr[] = "Hello world";

class MyString {

private:
	char* str;

public:

	MyString( const char* input = defaultStr ) {
		if ( input == nullptr || strlen(input) == 0 ) {
			input = defaultStr;
		}

		int len = strlen(input) + 1;
		
		/*  ------  Manual string count  ------ *
			int len = 0;
			while ( input[len] != '\0' ) {
				len++;
			}
			len++;
		*/

		str = new char[len];

		/*  ------  Manual copy  ------ *
			for (int i = 0; i <= len; i++) {
				str[i] = input[i];
			}
		*/

		strcpy_s( str, len, input);

	};

	// Copy Constructor
	MyString( const MyString& s ) {

		/*  ------  Manual string count  ------ *
			int len = 0;
			while ( s.str[len] != '\0' ) {
				len++;
			}
			len++;
		*/

		int len = strlen(s.str) + 1;
		str = new char[len];

		strcpy_s(str, len, s.str);

		/*  ------  Manual copy  ------ *
			for (int i = 0; i <= len; i++) {
				str[i] = s.str[i];
			}
		*/
	};

	// destructors
	~MyString() { delete[] str; };

	void printString() {
		cout << str << endl;
	};
};

int main() {

	MyString s1;
	s1.printString();

	cout << "\n==============  With input ==============\n";

	MyString s2("Test input");
	s2.printString();

	cout << "\n==============  With empty string ==============\n";

	MyString s3("");
	s3.printString();

	cout << "\n==============  With empty string ==============\n";

	MyString s5("Test Copy Constructor");

	cout << "s5: ";
	s5.printString();

	MyString s8 = s5;

	cout << "s8 copy: ";
	s8.printString();

}