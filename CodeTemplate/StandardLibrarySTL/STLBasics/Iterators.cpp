#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums =
    {
        10,20,30,40,50
    };

    cout << "Iterator traversal:\n";

    vector<int>::iterator it;

    for (it = nums.begin();
        it != nums.end();
        ++it) {

        cout << *it << " ";
    }

    cout << endl;

    cout << "\nModify using iterator:\n";

    for (it = nums.begin();
        it != nums.end();
        ++it) {

        *it *= 2;
    }

    for (int n : nums)
        cout << n << " ";

    cout << endl;

    return 0;
}