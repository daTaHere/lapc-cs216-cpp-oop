#include <iostream>
#include <vector>
using namespace std;

class MyContact {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string email;

public:
    MyContact(string fn = "", string ln = "", string pn = "", string em = "")
        : firstName(fn), lastName(ln), phoneNumber(pn), email(em) {
    }

    string getLastName() const {
        return lastName;
    }

    void displayContact() const {
        cout << firstName << " " << lastName << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

void displayMenu() {
    cout << "\n===== Contact Menu =====" << endl;
    cout << "1. Add a new contact" << endl;
    cout << "2. Display all contacts" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
}

MyContact addContact() {
    string fn, ln, ph, em;

    cout << "Enter First Name: ";
    cin >> fn;

    cout << "Enter Last Name: ";
    cin >> ln;

    cout << "Enter Phone Number: ";
    cin >> ph;

    cout << "Enter Email: ";
    cin >> em;

    return MyContact(fn, ln, ph, em);
}

void displayAllContacts(const vector<MyContact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts" << endl;
        return;
    }

    for (const auto& contact : contacts) {
        contact.displayContact();
        cout << endl;
    }
}

int main() {
    vector<MyContact> contacts;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            contacts.push_back(addContact());
            break;

        case 2:
            displayAllContacts(contacts);
            break;
        }

    } while (choice != 3);

    return 0;
}