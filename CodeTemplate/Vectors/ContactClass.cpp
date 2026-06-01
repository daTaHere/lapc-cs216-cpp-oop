#include <iostream>
using namespace std;

class MyContact {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string email;

public:
    MyContact()
        : firstName(""), lastName(""), phoneNumber(""), email("") {
    }

    MyContact(string fn, string ln, string pn, string em)
        : firstName(fn), lastName(ln), phoneNumber(pn), email(em) {
    }

    // Setters 
    void setFirstName(string fn) {
        firstName = fn;
    }

    void setLastName(string ln) {
        lastName = ln;
    }

    void setPhoneNumber(string pn) {
        phoneNumber = pn;
    }

    void setEmail(string em) {
        email = em;
    }

    // Getters
    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    string getEmail() const {
        return email;
    }

    void displayContact() const {
        cout << firstName << " " << lastName << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

int main() {
    MyContact c("Data", "Here", "285-5825", "test@email.com");

    c.displayContact();

    return 0;
}