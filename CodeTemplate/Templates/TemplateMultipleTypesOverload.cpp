#include <iostream>
using namespace std;

template <typename T1, typename T2>
void show(T1 x, T2 y) {
    cout << "x: " << x << ", y: " << y << endl;
}

template <typename T>
void show(T x) {
    cout << "x only: " << x << endl;
}

int main() {
    show(10, 3.14);
    show("Data");

    return 0;
}