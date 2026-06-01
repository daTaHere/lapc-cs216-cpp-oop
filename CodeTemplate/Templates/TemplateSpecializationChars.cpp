#include <iostream>
using namespace std;

template <typename T>
class Test {
private:
    T element;

public:
    Test(T e) : element(e) {}

    void addOne() {
        element++;
    }

    void display() const {
        cout << "element = " << element << endl;
    }
};

// Specialized version for char
template <>
class Test<char> {
private:
    char element;

public:
    Test(char e) : element(e) {}

    void addOne() {
        element = element + 1;
    }

    void display() const {
        cout << "char element = " << element << endl;
    }
};

int main() {
    Test<int> a(10);
    Test<double> b(10.5);
    Test<char> c('A');

    a.addOne();
    b.addOne();
    c.addOne();

    a.display();
    b.display();
    c.display();

    return 0;
}