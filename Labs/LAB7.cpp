#include <iostream>
#include <vector>

using namespace std;

class MyContact
{


private:
	string firstName;
	string lastName; 
	string phoneNumber;
	string	email;
public:
	MyContact() : firstName(""), lastName(""), phoneNumber(""), email("") {};
	MyContact(string fName, string lName, string pNum, string em ) : firstName(fName), lastName(lName), phoneNumber(pNum), email(em) {};
	
	// setter
	void setFirstName(const string fn) { firstName = fn; };
	void setLastName(const string ln)  { lastName = ln; };
	void setPhoneNumber(const string pn)  { phoneNumber = pn; };
	void setEmail(const string em)  { email = em; };


	// getter 
	string getFirstName() const { return firstName; };
	string getLastName() const { return lastName; };
	string getPhoneNumber() const { return phoneNumber; };
	string getEmail () const { return email; };

	MyContact addContact(string fName, string lName, string pNum, string em) {
		return MyContact(fName, lName, pNum, em);
	};

	void displayContact() const {
		cout << "Frist: " << firstName << "lastName: " << lastName << "phoneNumber: " << phoneNumber << "email: " << email << endl;
	};
	
};
//
//int menu() {
//	int result = 0;
//	cout << "\n===== Contact Menu =====" << endl;
//	cout << "1. Add a new contact" << endl;
//	cout << "2. Display all contacts" << endl;
//	cout << "3. Search by last name" << endl;
//	cout << "4. Delete by last name" << endl;
//	cout << "5. Exit" << endl;
//	cout << "Enter choice: ";
//	cin >> result;
//	return result;
//}


bool isValid(int userInput) {

}

int main() {

	vector<MyContact> v;
	vector<MyContact> contacts;

	int result = 0;
	cout << "\n===== Contact Menu =====" << endl;
	cout << "1. Add a new contact" << endl;
	cout << "2. Display all contacts" << endl;
	cout << "3. Search by last name" << endl;
	cout << "4. Delete by last name" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter choice: ";
	cin >> result;
	

	return 0;
}
