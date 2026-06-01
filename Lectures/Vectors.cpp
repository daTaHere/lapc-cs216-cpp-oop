#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

//------------------------------------------
//Simple class to demo vector obj 

class Person {

private:
	string name;
	int age;

public:
	Person(const string& name, int age) : name(name), age(age) {};
	string getName() const { return name; }
	int getAge() const { return age; }

};

// Fill vect with user input
void getVector(vector<int>& v) {
	for (auto& elem : v) {
		cout << "Eneter value for vector: ";
		cin >> elem;
	}
}

// Print using range-base for loop (best for beginners)
void printVector(const vector<int>& v) {
	for (int i : v)
		cout << i << " ";
	cout << endl;
}

// Print using index at at()
void printVector1(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
}

// Print using const_iterator (safe traversal)
//void printVector2(const vector<int>& v) {
//	vector<int>::const_iterator it = v.begin();
//	vector<int>::const_iterator end = v.end();
//
//	while (it != end)
//		cout << *it++ << " ";
//	cout << endl;
//}





int main() {
	// Vector = dynamic array (resizabe, contiguos memeory)  ---> FILA (First in last out)
	vector<int> v1(10);     // 10 elements init to 0
	vector<int> v2(10, 19);  // 10 elements init to 19 
	vector<int> v3 = { 25,10,35,20 };
	vector<int> v4(3);
	vector<int> v5 = { 1,2,3,4,5 };
	vector<int> v6 = { 3,4,5 };
	vector<int> v;


	// reserve = allocate memory but DO NOT create elements
	v.reserve(20);

	v.push_back(10);
	cout << "element 0 of v = " << v.at(0) << endl;

	v.push_back(20);
	v.push_back(30);

	cout << "size = " << v.size() << endl;

	printVector(v);
	printVector1(v);
	//printVector2(v);

	cout << "\n===================== RESIZE ==========================" << endl;
	v.resize(10);
	v.at(1) = 11; // safer than v[1]
	printVector(v);

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	cout << "front = " << v.front() << endl;
	cout << "back = " << v.back() << endl;

	cout << "\n=======  push_back --> append 6 to list ==========================" << endl;
	printVector(v);
	v.push_back(6);
	printVector(v);
	cout << "last element = " << v.back() << endl;

	v.pop_back(); // remove last element

	printVector(v);
	cout << "After pop_back\n";
	cout << "======================\n" << endl;
	//==============================================================
	cout << "v: ";
	printVector(v);
	vector<int> w = v;   // copy vector 

	cout << "w: ";
	printVector(w);

	if (v == w)
		cout << "v is equalt to w\n";

	w.push_back(13);

	if (v == w)
		cout << "v is equalt to w\n";
	else
		cout << "v is NOT equal to w\n";

	// ======== SORTING 

	printVector(v3);

	cout << "Sorting ascending\n";
	sort(v3.begin(), v3.end());
	printVector(v3);

	cout << "Sorting descending\n";
	sort(v3.begin(), v3.end(), greater<int>());
	printVector(v3);

	//==============================================================
	// INSERT

	cout << "====================================================\n";

	printVector(v);

	v.insert(v.begin(), 7); // insert at beginning 
	printVector(v);

	v.insert(v.begin() + 2, 7); // insert at index 2 --> (first + offset)
	printVector(v);


	// ITERATORS
	// ===================================================
	// begin() -> frist element
	// end() -> one past last element

	v.resize(10);

	for (int i = 0; i < v.size(); i++) {
		v.at(i) = 10 * (i + 1);
	}

	printVector(v);

	// modify elements using iterator 
	vector<int>::iterator it1 = v.begin();
	vector<int>::iterator it2 = v.end();

	while (it1 != it2) {
		*it1 *= 2; // double each value
		++it1;
	}

	printVector(v);

	// AUTO KEYWORD
	//========================================================================

	auto j = 19;        //int
	auto name = "Bob";  // const char*
	auto n = { 1,2,3 }; // init list

	vector<int> nums = { 1,2,3,4,5 };

	for (auto n : nums) {
		// n is int (copy)
	}

	// INSERT RETURNS ITERTOR KEYWORD
   //========================================================================

	auto it = v.insert(v.begin() + 5, 19);
	cout << "*it = 19" << *it << endl;
	printVector(v);
	cout << "Print using iterator\n";
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// ERASE===============================
	cout << "Erase element at idx 2\n";
	it = v.begin() + 2;
	v.erase(it);
	printVector(v);
	it = v.begin() + 3;
	v.insert(it, 100);
	printVector(v);
	//erase range [ start, stop ]
	vector<int>::iterator start = v.begin() + 1;
	vector<int>::iterator stop = v.begin() + 3;

	v.erase(start, stop);
	printVector(v);

	// clear items
	v.clear();

	cout << "After clear:\n";
	printVector(v);

	// VECTOR OF OBJECTS
	//===============================================================
	vector<Person> students;

	students.push_back(Person("Mary", 19)); // copy
	students.emplace_back("Al", 20);
	students.emplace_back("Rose", 21);

	// better: use const reference to avoid copying

	for (const auto& person : students) {
		cout << "Name: " << person.getName()
			<< ", Age: " << person.getAge() << endl;
	}

	return 0;
}