#include <iostream>
#include <vector>

using namespace std;
// Prototypes
void displayMenu();
int validatedInput();

class MyContact
{
private:
	string firstName;
	string lastName;
	string phoneNumber;
	string	email;
public:
	MyContact() : firstName(""), lastName(""), phoneNumber(""), email("") {};
	MyContact(string fName, string lName, string pNum, string em) : firstName(fName), lastName(lName), phoneNumber(pNum), email(em) {};

	// setter
	void setFirstName(const string fn) { firstName = fn; };
	void setLastName(const string ln) { lastName = ln; };
	void setPhoneNumber(const string pn) { phoneNumber = pn; };
	void setEmail(const string em) { email = em; };
	// getter 
	string getFirstName() const { return firstName; };
	string getLastName() const { return lastName; };
	string getPhoneNumber() const { return phoneNumber; };
	string getEmail() const { return email; };

	void displayContact() const {
		cout << firstName << " "
			<< lastName << endl << "   Phone: "
			<< phoneNumber << endl
			<< "   Email: " << email << endl;
	};
};
// Class prototypes
MyContact addContact();
void displayAllContacts(const vector<MyContact>& contactList);
void getUserRequest(const int choice, vector<MyContact>& contactList);
void getContactByLastName(const vector<MyContact>& contactList);
void deleteByLastName(vector<MyContact>& contactList);

// Helper Functions
int validatedInput() {
	bool isValid = false;
	int userInput = 0;
	// Ensure user input is valid
	while (!isValid) {
		displayMenu();
		cin >> userInput;
		if (userInput > 0 && userInput <= 5) { isValid = true; }
		if (!isValid) { cout << "Input not valid try again!\n" << endl; }
	}
	return userInput;
}
void displayMenu() {
	// Main Menu display
	cout << "\n===== Contact Menu =====" << endl;
	cout << "1. Add a new contact" << endl;
	cout << "2. Display all contacts" << endl;
	cout << "3. Search by last name" << endl;
	cout << "4. Delete by last name" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter choice: ";
}
void getUserRequest(const int choice, vector<MyContact>& contactList) {
	switch (choice) {
	case 1:
		cout << "\nAdd contact\n";
		cout << "======================\n";
		contactList.push_back(addContact());
		break;
	case 2:
		cout << "\nDisplay contacts\n";
		cout << "======================\n";
		displayAllContacts(contactList);
		cout << endl;
		break;
	case 3: // Search for a contact by last name and display their details
		cout << "Search\n";
		cout << "======================\n";
		getContactByLastName(contactList);
		break;
	case 4:   //Delete a contact by last name
		cout << "Delete\n";
		cout << "======================\n";
		deleteByLastName(contactList);
		break;
	}
}

// Menu Functions
MyContact addContact() {
	string fn, ln, ph, em;
	cout << "Enter First Name : ";
	cin >> fn;
	cout << "Enter Last Name : ";
	cin >> ln;
	cout << "Enter Phone Number : ";
	cin >> ph;
	cout << "Enter Email : ";
	cin >> em;

	return MyContact(fn, ln, ph, em);
}
void displayAllContacts(const vector<MyContact>& contactList) {
	if (contactList.size() == 0) {
		cout << "No contacts\n";
		return;
	}
	int idx = 1;
	for (const auto& c : contactList) {
		cout << idx++ << ") ";
		c.displayContact();
	}

}
void getContactByLastName(const vector<MyContact>& contactList) {
	string input;
	bool found = false;
	cout << "Enter last name to search: ";
	cin >> input;
	cout << endl;
	for (auto it = contactList.begin(); it != contactList.end();) {
		if (it->getLastName() == input) {
			cout << "Contact found: " << endl;
			cout << "   ";
			it->displayContact();
			found = true;
			break;
		}
		else {
			++it;
		}
	}
	if (found != true) {
		cout << "Contact not found";
	}
}
void deleteByLastName(vector<MyContact>& contactList) {
	string deleteName;
	cout << "Enter Last Name to delete: ";
	cin >> deleteName;

	bool deleted = false;
	// Handled with vector.begin() and vector.end() instead of foreach [as asked]
	for (auto it = contactList.begin(); it != contactList.end(); ) {
		if (it->getLastName() == deleteName) {
			// Shallow copy created before erasing [as asked]
			MyContact temp = *it;

			// Delete by index/iterator
			it = contactList.erase(it);

			// Output deleted contact info
			cout << "Successfully deleted:\n";
			temp.displayContact();
			deleted = true;
		}
		else {
			++it;
		}
	}

	if (!deleted) cout << "No matching contact found to delete.\n";
}

int main() {

	vector<MyContact> v;
	vector<MyContact> contacts;
	int userInput = 0;

	do {
		userInput = validatedInput();
		getUserRequest(userInput, contacts);
	} while (userInput != 5);

	return 0;
}