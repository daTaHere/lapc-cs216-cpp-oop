#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

    // Helper function Normalization
    void simplify() {
        meter = 1000 * kMeter + meter;
        kMeter = meter / 1000;
        meter = meter % 1000;
    }

public:
    Dist(int k = 0, int m = 0) : kMeter(k), meter(m) {
        simplify();
    }

    void print() const {
        cout << kMeter << " kilometer and " << meter << " meter" << endl;
    }

    // Member operator overload
    Dist operator-(const Dist& rhs) const {
        Dist result(kMeter - rhs.kMeter, meter - rhs.meter);
        result.simplify();
        return result;
    }

    // Friend operator overload
    friend Dist operator+(const Dist& d1, const Dist& d2);
};

Dist operator+(const Dist& d1, const Dist& d2) {
    Dist result(d1.kMeter + d2.kMeter, d1.meter + d2.meter);
    result.simplify();
    return result;
}

int main() {
    Dist d1(2, 900);
    Dist d2(1, 999);

    // Member function version
    Dist d3 = d1 - d2;

    // Friend function version
    Dist d4 = d1 + d2;

    cout << "d1 - d2 = ";
    d3.print();

    cout << "d1 + d2 = ";
    d4.print();

    return 0;
}