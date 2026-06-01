#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    // MAP
    map<string, int> students;

    students["Joe"] = 30;
    students["Mary"] = 19;
    students["Allen"] = 18;

    cout << "MAP:\n";

    for (auto item : students) {
        cout << item.first
            << " : "
            << item.second
            << endl;
    }

    cout << endl;

    // UNORDERED MAP
    unordered_map<string, int> inventory;

    inventory["Apple"] = 3;
    inventory["Orange"] = 5;

    cout << "Apple count: "
        << inventory["Apple"]
        << endl;

    return 0;
}