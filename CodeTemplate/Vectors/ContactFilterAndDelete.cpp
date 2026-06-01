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

void searchByLastName(const vector<MyContact>& contacts) {
    string input;
    bool found = false;

    cout << "Enter last name to search: ";
    cin >> input;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getLastName() == input) {
            cout << "Contact found:" << endl;
            it->displayContact();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found" << endl;
    }
}

void deleteByLastName(vector<MyContact>& contacts) {
    string deleteName;
    bool deleted = false;

    cout << "Enter last name to delete: ";
    cin >> deleteName;

    for (auto it = contacts.begin(); it != contacts.end(); ) {
        if (it->getLastName() == deleteName) {
            cout << "Deleted:" << endl;
            it->displayContact();

            it = contacts.erase(it);
            deleted = true;
        }
        else {
            ++it;
        }
    }

    if (!deleted) {
        cout << "No matching contact found" << endl;
    }
}

int main() {
    vector<MyContact> contacts;

    contacts.emplace_back("Data", "Here", "555-1111", "adam@email.com");
    contacts.emplace_back("Mary", "Smith", "555-2222", "mary@email.com");
    contacts.emplace_back("John", "Doe", "555-3333", "john@email.com");

    searchByLastName(contacts);
    deleteByLastName(contacts);

    return 0;
}