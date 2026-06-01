#include <iostream>
#include <vector>

using namespace std;


//  TEMPLATES C++
/*=======================================================
	Templates allows us to wrte GENERIC code.
	One function/class can work with many data types.

	Benefits:
	1. Avoid duplicate code
	2. Resuable code
	3. Easier maintenace

	Examples:
	Max for int
	Max for double
	Max for char
	Instead of wrting 3 functions, write ONE template.

==========================================================*/

// Normal function (works ONY with int)
int MaxInt(int x, int y) {
	int res;
	if (x > y)
		res = x;
	else
		res = y;
	// turnary = res = (x>y) ? x : y;
	return res;
}

/*==============================
* FUNCTION TEMPLATE (Generic Function)*

	typename and class mean the same thing here

	Mordern sytle <typename T>

	Old style:
	template <class T>
*/

template<typename T>
T Max(T x, T y) {
	T res;
	if (x > y)
		res = x;
	else
		res = y;
	// turnary = res = (x>y) ? x : y;
	return res;
}

//===========================================================
// Another Generic Function Exam
// Swap two varibarles 

template <typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}


/*=========================
* Template with two types
*/
template<class T1, class T2>
void fun(T1 x, T2 y) {
	cout << "x is : " << x
		<< "   y is : " << y << endl;
}

//OVERLOAD TEMPLATE FUNCT
/*
* Same function name
* Diff params list
*/
template<class T>
void fun(T x) {
	cout << "x only is : " << x << endl;
}

//=========================================
// Generic class template
// Example: Dynamic Array class

template <typename T>
class Array {
private:
	T* ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
};
// Constructor of Template Class
template <typename T>
Array<T>::Array(T a[], int s) {
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = a[i];
}

/*
* Member Function of Template Class
*/
template <typename T>
void Array<T>::print() {
	for (int i = 0; i < size; i++)
		cout << *(ptr + i) << " ";
	//cout << *ptr->(i+1) << " ";
	cout << endl;
}

//==============================================================
// TEMPLATE SPECIALIZATION
// We can customize template behavior for a specific type.
// Generic version works for all types.
//==============================================================

template <class T>
class Test {
	T element;

public:
	Test(T e) {
		element = e;
	}

	void addOne() {
		element++;
	}

	void display() {
		cout << "element = " << element << endl;
	}
};
//==============================================================
// SPECIALIZATION VERSION for char
// This version runs ONLY when T = char
//==============================================================

template <>
class Test<char> {
	char element;

public:
	Test(char e) {
		element = e;
	}

	void addOne() {
		// move to next ASCII character
		// a -> b -> c .....
		element = (char)((int)element++);
	}

	void display() {
		cout << "element = " << element << endl;
	}
};


//=============================================================
// IMPORTANT:
// Inside templates, when using a DEPENDENT TYPE,
// the compiler needs the keyword "typename".
// Without typename:
// T::value_type x;   // ERROR
// With typename:
// typename T::value_type x;   // CORRECT
//=============================================================
template <class T>
void fooFun() {
	// Compiler does not know if value_type is a variable or type
	// T::value_type x;   // ERROR
	typename T::value_type x;
	// Example:
	// if T = vector<int>
	// then T::value_type = int
}


int main() {
	// FUNCT TEMPLATE EXAM
	int i = 10, j = 20, int1;
	long p = 10, q = 5, r;
	double d = 3.14;

	// Normal function
	int1 = MaxInt(i, j);

	// compliter automatically detects type
	int1 = Max(i, j);
	// explicit type
	r = Max <long>(p, q);
	cout << "max int = " << int1 << endl;
	cout << "max long = " << r << endl;
	cout << "============================================\n";

	// SWAP EXAM
	cout << "Before swap;\n";
	cout << "i = " << i
		<< "    j = " << j << endl;

	mySwap<int>(i, j);
	cout << "After swap;\n";
	cout << "i = " << i
		<< "    j = " << j << endl;


	cout << "Before swap;\n";
	cout << "p = " << p
		<< "    q = " << q << endl;

	mySwap<long>(p, q);
	cout << "After swap;\n";
	cout << "p = " << p
		<< "    q = " << q << endl;
	cout << "=============================\n";

	// Templaet function over loading 
	fun<int, double>(i, d);
	//// overloaded version
	fun<int>(i);
	fun<double>(d);


	// Generic class exam
	int arr[5] = { 1,2,3,4,5 };
	Array<int> a(arr, 5);
	a.print();

	char archar[3] = { 'a', 'b', 'c' };
	Array<char> ach(archar, 3);
	ach.print();
	// additional example
	double darr[4] = { 1.1, 2.2, 3.3, 4.4 };
	Array<double> ad(darr, 4);
	ad.print();
	cout << "=============================\n";

	//=============================================================
	// TEMPLATE SPECIALIZATION EXAMPLES
	//=============================================================

	Test<int> t(10);
	Test<double> tt(10.5);
	Test<char> ttt('A');

	t.addOne();
	t.display();

	tt.addOne();
	tt.display();

	ttt.addOne();
	ttt.display();

	//=============================================================
	// EXTRA EXAMPLES
	//=============================================================

	cout << "\nExtra Examples\n";

	cout << "Max of doubles = "
		<< Max(4.5, 9.2) << endl;

	cout << "Max of chars = "
		<< Max('A', 'Z') << endl;

	return 0;

}