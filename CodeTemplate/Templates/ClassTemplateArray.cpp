#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* ptr;
    int size;

public:
    Array(T arr[], int s) {
        size = s;
        ptr = new T[size];

        for (int i = 0; i < size; i++) {
            ptr[i] = arr[i];
        }
    }

    ~Array() {
        delete[] ptr;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int nums[] = { 1, 2, 3 };
    Array<int> intArray(nums, 3);
    intArray.print();

    char letters[] = { 'a', 'b', 'c' };
    Array<char> charArray(letters, 3);
    charArray.print();

    return 0;
}