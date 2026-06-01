#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>

using namespace std;

int main() {

    // VECTOR
    vector<int> v = { 1, 2, 3 };
    v.push_back(4);

    cout << "Vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // LIST
    list<int> l = { 1, 2, 3 };
    l.push_back(4);

    cout << "List front: " << l.front() << endl;
    cout << "List back : " << l.back() << endl;

    // DEQUE
    deque<int> d = { 1, 2, 3 };
    d.push_front(0);
    d.push_back(4);

    cout << "Deque[0]: " << d[0] << endl;

    // FORWARD LIST
    forward_list<int> fl = { 1, 2, 3 };
    fl.push_front(0);

    cout << "Forward list front: "
        << fl.front() << endl;

    // ARRAY
    array<int, 3> ar = { 10, 20, 30 };

    cout << "Array[1]: "
        << ar[1] << endl;

    return 0;
}