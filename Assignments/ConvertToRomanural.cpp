#include <iostream>
#include <string>

using namespace std;

class romanType {
private:
    string romanNum;
    int decNum;
    // Helper map char -> value 
    int MapChar(char c) {
        if (c == 'M') return 1000;
        if (c == 'D') return 500;
        if (c == 'C') return 100;
        if (c == 'L') return 50;
        if (c == 'X') return 10;
        if (c == 'V') return 5;
        if (c == 'I') return 1;
        return 0; // gaurd--> dont count invalid input
    }
    // Helper covert Roman to Dec
    int ConvertToDec(const string& r) {
        int total = 0;
        int prev = 0;

        for (size_t i = 0; i < r.length(); i++) {
            int curr = MapChar(r[i]);
            if (prev >= curr) {
                total += curr;
            }
            else {
                //  Adjust runing total  IX = 9 --> (10 - 1)  
                total += curr - (2 * prev);
            }
            // Track previouse values
            prev = curr;
        }
        return total;
    }

public:
    // Constructors
    romanType() : romanNum(""), decNum(0) {}
    romanType(const string& r) : romanNum(r), decNum(ConvertToDec(r)) {}

    // getters 
    void displayRoman() const {
        cout << "Roman: " << romanNum << endl;
    }

    // Friend function
    friend void displayDecimal(const romanType& num);
};

// Defined functon 
void displayDecimal(const romanType& num) {
    cout << "Decimal: " << num.decNum << endl;
}

int main() {
    string test1 = "MCXIV";
    string test2 = "CCCLIX";
    string test3 = "MDCLXVI";

    romanType roman1(test1);
    romanType roman2(test2);
    romanType roman3(test3);

    cout << "-----------    Test 1: MCXIV       ---------------" << endl;
    roman1.displayRoman();
    displayDecimal(roman1);


    cout << "\n-----------    Test 2: CCCLIX       ---------------" << endl;
    roman2.displayRoman();
    displayDecimal(roman2);

    cout << "\n-----------    Test 3: MDCLXVI       ---------------" << endl;
    roman3.displayRoman();
    displayDecimal(roman3);

    return 0;
}