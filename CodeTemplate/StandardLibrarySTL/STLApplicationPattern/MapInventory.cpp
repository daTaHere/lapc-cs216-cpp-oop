#include <iostream>
#include <map>

using namespace std;

int main() {

    map<string, double> inventory;

    inventory["Milk"] = 3.99;
    inventory["Bread"] = 2.49;
    inventory["Eggs"] = 5.99;

    cout << "Inventory\n";
    cout << "================\n";

    for (auto item : inventory) {
        cout << item.first
            << " : $"
            << item.second
            << endl;
    }

    cout << "\nPrice of Milk: $"
        << inventory.at("Milk")
        << endl;

    return 0;
}