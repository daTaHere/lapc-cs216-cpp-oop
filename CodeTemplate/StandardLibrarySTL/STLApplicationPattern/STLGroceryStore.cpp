#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {

    // Inventory
    map<string, double> inventory;

    inventory["Milk"] = 3.99;
    inventory["Bread"] = 2.49;
    inventory["Eggs"] = 5.99;

    // Cart
    unordered_map<string, int> cart;

    cart["Milk"] = 2;
    cart["Eggs"] = 1;

    // History
    vector<string> transactions;

    // Customer Queue
    queue<string> customers;

    customers.push("Data");
    customers.push("Mary");

    // Calculate bill
    double total = 0;

    for (auto item : cart) {
        total += inventory[item.first]
            * item.second;
    }

    cout << "Total Bill: $"
        << total
        << endl;

    // Save transaction
    transactions.push_back(
        "Purchase Total = $" +
        to_string(total)
    );

    // Serve customer
    cout << "Serving: "
        << customers.front()
        << endl;

    customers.pop();

    // Display history
    cout << "\nHistory\n";

    for (const auto& t : transactions) {
        cout << t << endl;
    }

    return 0;
}