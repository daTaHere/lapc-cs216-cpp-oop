#include <iostream>
using namespace std;

int main() {

    int x = 3;
    int y = 10;

    auto multiply = [x, y]() {  return x * y; };

    cout << multiply() << endl;

    int count = 0;

    auto increment = [&count]() {
        count++;
        cout << count << endl;
        };

    increment();
    increment();
    increment();

    int num = 5;

    auto changeValue = [num]() mutable {
            num += 10;
            cout << "Inside: " << num << endl; 
        };

    changeValue();

    cout << "Outside: " << num << endl;

    return 0;
}