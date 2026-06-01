#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    priority_queue<pair<double, string>> topProducts;

    topProducts.push({ 19.99, "Keyboard" });
    topProducts.push({ 99.99, "Monitor" });
    topProducts.push({ 49.99, "Mouse" });
    topProducts.push({ 499.99, "Laptop" });

    cout << "Top 3 Most Expensive\n";
    cout << "====================\n";

    for (int i = 0; i < 3; i++) {

        cout << topProducts.top().second
            << " : $"
            << topProducts.top().first
            << endl;

        topProducts.pop();
    }

    return 0;
}