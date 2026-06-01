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
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    printVector(v);

    cout << "Size: " << v.size() << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    v.pop_back();

    printVector(v);

    return 0;
}