#include <iostream>
using namespace std;

class IntArray {
private:
    int size;
    int* data;

public:
    IntArray(int s, int value) {
        size = s;
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }

    // Copy constructor - deep copy
    IntArray(const IntArray& other) {
        size = other.size;
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~IntArray() {
        delete[] data;
    }

    void setAll(int value) {
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    IntArray a1(5, 10);

    // Copy constructor is called here
    IntArray a2 = a1;

    a2.setAll(20);

    cout << "a1: ";
    a1.print();

    cout << "a2: ";
    a2.print();

    return 0;
}