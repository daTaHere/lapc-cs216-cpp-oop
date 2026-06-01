#include <iostream>
using namespace std;

int main() {

    auto sayHi = []() {
        cout << "Hello from lambda!" << endl;
        };

    sayHi();

    auto add = [](int a, int b) {
        return a + b;
        };

    cout << "10 + 20 = " << add(10, 20) << endl;
    return 0;

}