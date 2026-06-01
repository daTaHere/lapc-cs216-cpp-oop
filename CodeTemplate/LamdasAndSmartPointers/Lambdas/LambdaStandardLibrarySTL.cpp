#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    vector<int> nums =
    { 1,2,3,4,5 };

    int product =
        accumulate( nums.begin(), nums.end(), 1,
            [](int a, int b) {
                return a * b;
            }
        );

    cout << product << endl;

    auto it = 
        find_if( nums.begin(), nums.end(), 
            [](int n) {
                return n > 3;
            }
        );

    if (it != nums.end())
        cout << *it << endl;

    for_each( nums.begin(), nums.end(),
        [](int n) {
            cout << n << " ";
        }
    );

    cout << endl;

    return 0;
}