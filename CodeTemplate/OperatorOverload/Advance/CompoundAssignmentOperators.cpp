#include <iostream>
using namespace std;

class Dist {
private:
    int meters;

public:
    Dist(int m = 0) : meters(m) {}

    Dist& operator+=(const Dist& rhs) {
        meters += rhs.meters;
        return *this;
    }

    Dist& operator-=(const Dist& rhs) {
        meters -= rhs.meters;
        return *this;
    }

    Dist& operator*=(const Dist& rhs) {
        meters *= rhs.meters;
        return *this;
    }

    Dist& operator/=(const Dist& rhs) {
        meters /= rhs.meters;
        return *this;
    }

    void print() const {
        cout << meters << " meters" << endl;
    }
};

int main() {
    Dist d1(100);
    Dist d2(20);

    d1 += d2;
    d1.print();

    d1 -= d2;
    d1.print();

    d1 *= d2;
    d1.print();

    d1 /= d2;
    d1.print();

    return 0;
}