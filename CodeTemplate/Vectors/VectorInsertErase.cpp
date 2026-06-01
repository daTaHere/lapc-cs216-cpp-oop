#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    for (int value : v) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = { 10, 20, 30, 40 };

    printVector(v);

    v.insert(v.begin(), 5);
    printVector(v);

    v.insert(v.begin() + 2, 15);
    printVector(v);

    v.erase(v.begin() + 1);
    printVector(v);

    v.erase(v.begin(), v.begin() + 2);
    printVector(v);

    v.clear();
    printVector(v);

    return 0;
}