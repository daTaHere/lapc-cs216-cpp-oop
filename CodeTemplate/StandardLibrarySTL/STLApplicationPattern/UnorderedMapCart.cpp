#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<string, int> cart;

    cart["Milk"] = 2;
    cart["Bread"] = 1;

    cart["Milk"] += 1;

    cout << "Shopping Cart\n";
    cout << "================\n";

    for (auto item : cart) {
        cout << item.first
            << " x "
            << item.second
            << endl;
    }

    cart.erase("Bread");

    cout << "\nAfter erase:\n";

    for (auto item : cart) {
        cout << item.first
            << " x "
            << item.second
            << endl;
    }

    return 0;
}