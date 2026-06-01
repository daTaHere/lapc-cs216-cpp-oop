#include <iostream>
using namespace std;

template <typename T>
T Max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << Max(10, 20) << endl;
    cout << Max(4.5, 9.2) << endl;
    cout << Max('A', 'Z') << endl;

    return 0;
}