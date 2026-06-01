#include <iostream>
using namespace std;

class Dist {
private:
    int meters;

public:
    Dist(int m = 0) : meters(m) {}

    // Member overload
    Dist& operator--() {
        --meters;
        return *this;
    }

    // Friend overload
    friend Dist operator+(const Dist& lhs,
        const Dist& rhs);

    void print() const {
        cout << meters << endl;
    }
};

// Function definition
Dist operator+(const Dist& lhs,
    const Dist& rhs) {
    return Dist(lhs.meters + rhs.meters);
}

int main() {
    Dist d1(100);
    Dist d2(50);

    --d1;

    Dist d3 = d1 + d2;

    cout << "d1 = ";
    d1.print();

    cout << "d3 = ";
    d3.print();

    return 0;
}