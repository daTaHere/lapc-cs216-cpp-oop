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

    // Unit coverter km to meters
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

    // Friend functions
    friend bool operator<(const Dist& d1, const Dist& d2);
    friend bool operator<=(const Dist& d1, const Dist& d2);
    friend bool operator>=(const Dist& d1, const Dist& d2);
    friend bool operator==(const Dist& d1, const Dist& d2);
    friend bool operator!=(const Dist& d1, const Dist& d2);
};


// Function definition

//               Less Than
bool operator<(const Dist& d1, const Dist& d2) {
    return d1.totalMeters() < d2.totalMeters();
}

//               Less Than Equal to 
bool operator<=(const Dist& d1, const Dist& d2) {
    return d1.totalMeters() <= d2.totalMeters();
}

//               Greater Than Equal to 
bool operator>=(const Dist& d1, const Dist& d2) {
    return d1.totalMeters() >= d2.totalMeters();
}

//               Equal to
bool operator==(const Dist& d1, const Dist& d2) {
    return d1.totalMeters() == d2.totalMeters();
}

//               NOT Equal to 
bool operator!=(const Dist& d1, const Dist& d2) {
    return d1.totalMeters() != d2.totalMeters();
}

int main() {
    Dist d1(2, 900);
    Dist d2(1, 999);
    Dist d3(2, 900);

    cout << "d1 < d2? " << ((d1 < d2) ? "Yes" : "No") << endl;
    cout << "d1 <= d2? " << ((d1 <= d2) ? "Yes" : "No") << endl;
    cout << "d1 >= d2? " << ((d1 >= d2) ? "Yes" : "No") << endl;
    cout << "d1 == d3? " << ((d1 == d3) ? "Yes" : "No") << endl;
    cout << "d1 != d2? " << ((d1 != d2) ? "Yes" : "No") << endl;

    return 0;
}