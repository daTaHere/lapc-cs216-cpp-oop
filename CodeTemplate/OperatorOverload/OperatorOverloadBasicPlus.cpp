#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

    // Helper funcction Normalization
    void simplify() {
        meter = 1000 * kMeter + meter;
        kMeter = meter / 1000;
        meter = meter % 1000;
    }

public:

    Dist(int k = 0, int m = 0) : kMeter(k), meter(m) {}

    void print() const {
        cout << kMeter << " kilometer and " << meter << " meter" << endl;
    }

    // Friend function 
    friend Dist operator+(const Dist& d1, const Dist& d2);
};

// Function definition  + overload
Dist operator+(const Dist& d1, const Dist& d2) {
    Dist result;
    result.kMeter = d1.kMeter + d2.kMeter;
    result.meter = d1.meter + d2.meter;

    result.simplify();

    return result;
}

int main() {
    Dist d1(2, 900);
    Dist d2(1, 999);

    Dist d3 = d1 + d2;

    d1.print();
    d2.print();
    d3.print();

    return 0;
}