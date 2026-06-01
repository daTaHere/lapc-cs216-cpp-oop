#include <iostream>
using namespace std;

class Dist {
private:
	int kMeter;
	int meter;

	// Helper function to keep distance normalized
	void simplify() {
		meter = 1000 * kMeter + meter;
		kMeter = meter / 1000;
		meter = meter % 1000;
	}

public:
	// Construtor
	Dist(int k = 0, int m = 0) : kMeter(k), meter(m) {}

	// Setters and getters
	void setDist(int k, int m) {
		kMeter = k;
		meter = m;
	}

	int getMeter() const { return meter; }
	int getKmeter() const { return kMeter; }

	// Display function
	void print() const {
		cout << kMeter << " kmeter and " << meter << " meter" << endl;
	}

	//-----------------------------------------------------------
	// Operator Overloading 
	//-----------------------------------------------------------
	// 1 + operator --> member function
	//Dist operator + (const Dist& rhs) const {
	//	Dist result(kMeter + rhs.kMeter, meter + rhs.meter);
	//	result.simplify();
	//	return result;
	//}

	// 2 + arg --> friend function
	friend Dist operator + (const Dist& d1, const Dist& d2);

};

// friend function defined
Dist operator + (const Dist& d1, const Dist& d2) {
	Dist d;
	d.meter = d1.meter + d2.meter;
	d.kMeter = d1.kMeter + d2.kMeter;
	d.simplify();
	return d;
}

int main() {
	// Initial distances
	Dist d1(2, 900);
	Dist d2(1, 999);
	Dist d3, d4;

	cout << "Initial distances:" << endl;
	cout << "d1 = ";
	d1.print();
	cout << "d2 = ";
	d2.print();
	//-------------------------------------------------------------
	// Test + operater (member and friend are similar

	// test friend
	d3 = d1 + d2;
	cout << "d3 = d1 + d2: ";
	d3.print();

}
