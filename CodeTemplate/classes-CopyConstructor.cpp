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

const char defaultStr[12] = "Hello World";

class MyString {

private:
	char* str;
public:
	// default intialization
	MyString(const char* s = defaultStr) {
		// gaurd against nullptr or empty strings
		if (s == nullptr || strlen(s) <= 0) {
			s = defaultStr;
		}

		// built-in length
		int len = strlen(s);

		// manual length
		//int len = 0;
		//while (s[len] != '\0') {
		//	len++;
		//}

		str = new char[len + 1];

		for (int i = 0; i <= len; i++) {
			str[i] = s[i];
		}
	}

	// deep copy constructor
	MyString(const MyString& s) {
		int len = strlen(s.str);

		str = new char[len + 1];

		for (int i = 0; i <= len; i++) {
			str[i] = s.str[i];
		}


		// Built-in copy
		//strcpy_s(str, len + 1, s.str);

	}
	~MyString() { delete[] str; }

	void printStr() {
		cout << "Str: " << str << endl;
	}
};






//class MyString {
//private:
//	char* str;
//
//public:
//
//	MyString(const char* s = nullptr) {
//		
//		if (s == nullptr) {
//			s = "Hello World";
//		}
//
//		int len = 0;
//		while ( s[len] != '\0') {
//			len++;
//		}
//
//		str = new char[len + 1];
//
//		for (int i = 0; i <= len; i++) {
//			str[i] = s[i];
//		}
//	}
//
//	MyString(const MyString& s) {
//		int len = 0;
//		while (s.str[len] != '\0') {
//			len++;
//		}
//
//		str = new char[len + 1];
//
//		for (int i = 0; i <= len; i++) {
//			str[i] = s.str[i];
//		}
//	}
//
//	~MyString() {
//		delete[] str;
//	}
//
//	void printStr() {
//		cout << "str: " << str << endl;
//	}
//
//};


int main() {

	MyString str1("Test It");
	MyString str2;
	MyString str3(nullptr);
	MyString str5("Test Copy");
	MyString str6(str5);

	str1.printStr();
	str2.printStr();
	str3.printStr();
	str6.printStr();

	return 0;
}