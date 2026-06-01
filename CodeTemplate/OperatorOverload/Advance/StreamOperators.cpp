#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

public:
    Dist(int k = 0, int m = 0)
        : kMeter(k), meter(m) {
    }

    friend ostream& operator<<(ostream& out,
        const Dist& d);

    friend istream& operator>>(istream& in,
        Dist& d);
};

ostream& operator<<(ostream& out,
    const Dist& d) {
    out << d.kMeter
        << " km and "
        << d.meter
        << " m";

    return out;
}

istream& operator>>(istream& in,
    Dist& d) {
    in >> d.kMeter >> d.meter;
    return in;
}

int main() {
    Dist d;

    cout << "Enter km and meters: ";
    cin >> d;

    cout << d << endl;

    return 0;
}