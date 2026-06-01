#include <iostream>
#include <cstring>

using namespace std;

// Student type struct --> default public
struct Student {
	int ID;
	double GPA;
	int programs[5];
};

// Node type struct --> default public
struct Node {
	int data;
	Node* next;
};

// insert a value at the end of the linked list || function --> add a Node to the Linked list <setter> ( return >> Node ptr )
Node* insert(Node* head, int value) {

	// declear a pointer var of type "Node" named "newNode".
	// "new" allocates heap memory AND constructs -> (instantiates) a Node object
	// Note: pointer( "newNode" ) is placed in the ---> stack
	// Note: "new" executes during runtime the Node obj is placed in the ---> heap
	// newNode(stack) -- pts to memory location of --> Node Object(heap)
	// Important clean up after <delete> --> c++ == NO BUILT-IN GARBAGE COLLECTION for dynamic memory(heap) allocation !!!!! <MEMORY LEAK>

	Node* newNode = new Node;
	newNode->data = value; // assign the param "value" to newNode's member "data" 
	newNode->next = nullptr; // assign null to newNode's member next (this is our new tail)

	if (head != nullptr) { // null check condition -> gaurd against empty Linked list

		Node* current = head; // temp ptr var assign current Node memory location

		while (current->next != nullptr) { // condiction to find the LAST Node
			current = current->next; // move pointer to next node
		}
		current->next = newNode; // found last Node assign "next" member to point to the addr of our newNode
	}
	else
		head = newNode;// linked list is empty assign newNode to HEAD

	return head; // return the current Node with member next NOW pointing to our newNode


}


// display the linked list || function --> "data" memeber value of the pointer being passed  <getter> ( return >> nothing )
void display(Node* head) {

	Node* current = head; // block scope ptr var
	while (current != nullptr) { // loop till last Node in list
		cout << current->data << " "; // stdout
		current = current->next; // advance ptr to next node if one exist
	}
	cout << endl;
}


// search for a value in the linked list || function --> filter linked list for value <getter> ( return >>  bool )
bool search(Node* head, int value) {
	Node* current = head;// block scope ptr var
	bool found = false; // conditional flag

	while (!found && current != nullptr) { // loop through linked list
		if (current->data == value) {
			found = true; // found value in linked list
		}
		else
			current = current->next; // value not yet found advance ptr
	}
	return found; // return result
}


int main() {
	int i;// local scope var not assigned

	Student st1; // intialize a Student object
	Student students[30]; // initalize an array of Students
	// initialize Student obj members
	st1.ID = 1234;
	st1.GPA = 3.34;
	st1.programs[0] = 100; // assign 100 to frist program of st1
	cout << "ID = " << st1.ID << endl;
	cout << "GPA = " << st1.GPA << endl;

	// assign the 3rd program of all students to 100
	for (int i = 0; i < 30; i++) {
		students[i].programs[2] = 100;
		cout << "prog 3 for 4th st " << students[3].programs[2] << endl;
		// Notice first 3 iteration resolve to arbitrary values. It is not until the 4th interation 
		// that the memory location being pointed to is assigned a value.
	}

	// ========================================

	//Defined the list
	Node* myList = nullptr;

	// call "insert" to build the Linked list
	myList = insert(myList, 1);
	myList = insert(myList, 2);
	myList = insert(myList, 3);
	myList = insert(myList, 4);

	cout << "Printing Linked List: ";
	// call "display" to output each Node "data" memeber value of each Node in our list
	display(myList);

	// call "search" to filter through the link list 
	int aValue = 30;
	if (search(myList, aValue)) {
		cout << aValue << " found in the linked list." << endl;
	}
	else {
		cout << aValue << " not found in the linked list." << endl;
	}

}