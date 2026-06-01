#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<string> transactions;

    transactions.push_back(
        "Milk x2 = $7.98"
    );

    transactions.push_back(
        "Bread x1 = $2.49"
    );

    transactions.push_back(
        "Eggs x1 = $5.99"
    );

    cout << "Transaction History\n";
    cout << "====================\n";

    for (const auto& item : transactions) {
        cout << item << endl;
    }

    return 0;
}