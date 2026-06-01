#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

    // Helper function Normalization
    void simplify() {
        meter = ( 1000 * kMeter ) + meter;
        kMeter = meter / 1000;
        meter = meter % 1000;
    }

    // Helper covert total meter units
    int totalMeters() const {
        return kMeter * 1000 + meter;
    }

public:
    Dist(int k = 0, int m = 0) : kMeter(k), meter(m) {
        simplify();
    }

    void print() const {
        cout << kMeter << " kilometer and " << meter << " meter" << endl;
    }

    // Friend function
    friend Dist operator-(const Dist& d1, const Dist& d2);
    friend Dist operator*(const Dist& d1, const Dist& d2);
    friend Dist operator/(const Dist& d1, const Dist& d2);
};


// Function definitions

//               Subtract ( - )
Dist operator-(const Dist& d1, const Dist& d2) {
    Dist result(0, d1.totalMeters() - d2.totalMeters());
    return result;
}

//                Multiply  ( * )
Dist operator*(const Dist& d1, const Dist& d2) {
    Dist result(0, d1.totalMeters() * d2.totalMeters());
    return result;
}

//                Divided ( / )
Dist operator/(const Dist& d1, const Dist& d2) {
    Dist result(0, d1.totalMeters() / d2.totalMeters());
    return result;
}

int main() {
    Dist d1(2, 900);
    Dist d2(1, 999);

    Dist d3 = d1 - d2;
    Dist d4 = d1 * d2;
    Dist d5 = d1 / d2;

    cout << "d1 - d2 = ";
    d3.print();

    cout << "d1 * d2 = ";
    d4.print();

    cout << "d1 / d2 = ";
    d5.print();

    return 0;
}