#include <iostream>
#include <utility>

using namespace std;

int main() {

    pair<int, int> p;

    p.first = 10;
    p.second = 20;

    cout << "("
        << p.first
        << ", "
        << p.second
        << ")"
        << endl;

    pair<string, int> student =
        make_pair("Mary", 19);

    cout << student.first
        << " "
        << student.second
        << endl;

    return 0;
}