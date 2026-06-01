#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<string> customers;

    customers.push("Data");
    customers.push("Mary");
    customers.push("John");

    cout << "Next Customer: "
        << customers.front()
        << endl;

    customers.pop();

    cout << "After Serving One Customer\n";

    cout << "Next Customer: "
        << customers.front()
        << endl;

    cout << "Queue Size: "
        << customers.size()
        << endl;

    return 0;
}