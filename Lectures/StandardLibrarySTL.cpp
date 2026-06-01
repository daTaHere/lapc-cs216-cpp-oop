#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <array>
using namespace std;

int main() {

	// VECTOR
	// Category: Sequence container
	// Fast: random access (O(1))
	// Slow: insert/delete in middle
	//==========================================
	vector<int> v = { 1,2,3 };
	v.push_back(4);

	cout << "Vector v at zero is: " << v.at(0) << endl;

	//==========================================
	// LIST (Doubly Linked List)
	// Fast insert/delete anywhere
	// Slow random access
	//==========================================

	list<int> l = { 1,2,3 };
	l.push_back(4);
	cout << "List front: " << v.front() << endl;
	cout << "List back: " << v.back() << endl;

	//==========================================
	// DEQUE (Double-ended queue)
	// Fast insert/delete at both ends
	// Supports random access
	//==========================================

	deque<int> d = { 1, 2, 3 };
	d.push_back(0);
	cout << "Deque[0]: " << d[0] << endl;

	//==========================================
	// Array (Fixed size)
	// Fast access, cannot resize
	//==========================================

	array<int, 3> ar = { 1, 2, 3 };
	d.push_back(0);
	cout << "Array[1]: " << ar[1] << endl;

	//==========================================
	// FORWARD_LIST (singly linked list)
	// Only forward traversal
	//==========================================

	forward_list<int> fl = { 1, 2, 3 };
	fl.push_front(0);
	cout << "Forward list front: " << fl.front() << endl;

	//==========================================
	// SET (Sorted unique element)
	// No duplicated, sorted
	//==========================================

	set<int> s =  { 3, 1, 2 };
	s.insert(4);

	cout << "Set: ";

	for (int x : s) cout << x << " ";
	cout << endl;

	//==========================================
	// MAP (Key-value, sorted by key)
	// Unique keys
	//==========================================

	map<int, string> m;
	m[1] = "one";
	m[3] = "three";
	m[2] = "two";
	cout << "Map[1]: " << m[1] << endl;
	for (auto x : m) cout << x.first << x.second << " ";


	//==========================================
	// UNORDERED_SET (Hash table)
	// Fast lookup, no order
	//==========================================

	unordered_set<int> us = { 3, 1, 2 };
	us.insert(4);

	cout << "Unordered set: ";

	for (int x : us) cout << x << " ";
	cout << endl;

	//==========================================
	// UNORDERED_MAP (Hash map)
	// Fast key lookup, no order
	//==========================================

	unordered_map<string, int> um;
	um["apple"] = 3;
	cout << "Apple count: " << um["apple"] << endl;

	//==========================================
	// STACK (LIFO - Last In First Out)
	//==========================================

	stack<int> st;
	st.push(1);
	st.push(2);
	cout << "Stack top: " << st.top() << endl;

	//==========================================
	// QUEUE (FIFO - Frist In First Out)
	//==========================================

	queue<int> q;
	q.push(1);
	q.push(2);
	cout << "Queue front: " << q.front() << endl;

	//==========================================
	// PRIORITY QUEUE (Heap)
	// Largest element on top by default
	//==========================================

	priority_queue<int> pq;
	pq.push(2);
	pq.push(1);
	cout << "Priority queue top: " << pq.top() << endl;

	//==========================================
	// PRIORITY QUEUE (Heap)
	// Largest element on top by default
	//==========================================

	list<string> myList = { "a", "b", "c", "c" , "c" };
	cout << "\nList contents:\n";
	for (auto n : myList) cout << n << endl;
	myList.push_front("z");
	cout << "\nAfter push_front:\n";
	for (auto n : myList) cout << n << endl;
	cout << "Front : " << myList.front() <<endl;
	cout << "Back : " << myList.back() << endl; 
	cout << "Size : " << myList.size() << endl;
	myList.pop_front();
	myList.pop_back();
	myList.remove("c");
	cout << "\nAfter modification:\n";
	for (auto n : myList) cout << n << endl;

	//Iterator travels
	cout << "\nInterator traversal:\n";
	for (auto it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << endl;
	}

	//==========================================
	// PAIR (Two values)
	//==========================================

	pair<int, int> myPair = make_pair(10, 20);
	myPair.second = 30;

	cout << "Pair: (" << myPair.first << ", " << myPair.second << ")\n";

	//==========================================
	map<string, int> myMap;

	myMap.insert(make_pair("Joe", 30));
	myMap.emplace("Allen", 18);
	myMap.emplace("Mary", 19);
	myMap.emplace("Bob", 18);

	myMap.erase("Mary");
	myMap.emplace("Mary", 100);

	cout << "\nMap values:\n";
	cout << "Allen: " << myMap.at("Allen") << endl;
	cout << "Mary: " << myMap.at("Mary") << endl;

	cout << "Count Allen: " << myMap.count("Allen") << endl;

	//==========================================
	// SET EXTENDED OPERATIONS

	set<int> mySet;
	mySet.insert(100);
	mySet.insert(300);
	mySet.insert(200);
	mySet.insert(200); // dups ignored
	mySet.insert(150);

	cout << "\nSet elements:\n";
	for (auto item : mySet) cout << item << endl;

	cout << "Count 100: " << mySet.count(100) << endl;
	cout << "Count 700: " << mySet.count(700) << endl;
	mySet.erase(150);

	cout << "\nAfter erase:\n";

	for (auto item : mySet) cout << item << endl;


	//==========================================
	// QUEUE EXTENDED OPERATIONS

	queue<string> myQue;
	
	myQue.push("a");
	myQue.push("b");
	myQue.push("c");

	cout << "\nQueue front: " << myQue.front() << endl;
	cout << "Queue back: " << myQue.back() << endl;
	cout << "Queue size: " << myQue.size() << endl;

	myQue.pop();

	cout << "After pop front: " << myQue.front() << endl;

	return 0;
}
