#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {

    // SET
    set<int> s;

    s.insert(300);
    s.insert(100);
    s.insert(200);
    s.insert(200);

    cout << "Set:\n";

    for (auto x : s)
        cout << x << " ";

    cout << endl;

    cout << "Count 100: "
        << s.count(100) << endl;

    // UNORDERED SET
    unordered_set<int> us;

    us.insert(300);
    us.insert(100);
    us.insert(200);

    cout << "\nUnordered Set:\n";

    for (auto x : us)
        cout << x << " ";

    cout << endl;

    return 0;
}