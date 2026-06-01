#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    // Prefix ++
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix ++
    Counter operator++(int) {
        Counter temp(*this);
        ++value;
        return temp;
    }

    void print() const {
        cout << value << endl;
    }
};

int main() {
    Counter c(10);

    cout << "Original: ";
    c.print();

    cout << "Prefix ++c: ";
    (++c).print();

    cout << "Postfix c++: ";
    (c++).print();

    cout << "After postfix: ";
    c.print();

    return 0;
}