#include <iostream>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    mySwap(x, y);

    cout << x << " " << y << endl;

    string a = "Hello";
    string b = "World";

    mySwap(a, b);

    cout << a << " " << b << endl;

    return 0;
}