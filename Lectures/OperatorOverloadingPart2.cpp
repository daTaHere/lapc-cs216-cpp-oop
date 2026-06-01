#include <iostream>
using namespace std;

class Dist {
private:
	int kMeter;
	int meter;

	// Helper function to keep distance normalized
	void simplify() {
		meter = ( 1000 * kMeter ) + meter;
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

	// 2. > operator
	bool operator > (const Dist& rhs) const {
		return (kMeter > rhs.kMeter) ||
			(kMeter == rhs.kMeter && meter > rhs.meter);
	}

	// 3.Prefix ++
	Dist operator ++() {
		++meter;
		simplify();
		return *this;
	}

	// 4.Postfix ++
	Dist operator ++(int x) {
		Dist temp(*this);
		++meter;
		simplify();
		return temp;
	}

	// 5.+= operator x += 10=> x= x+10
	Dist operator += (int n) {
		meter += n;
		simplify();
		return *this;
	}

	// 6. Assignment operator
	const Dist& operator = (const Dist& rhs) {
		if (this != &rhs) {
			kMeter = rhs.kMeter;
			meter = rhs.meter;
		}
		return *this;
	}

	// 2 + arg --> friend function
	friend Dist operator + (const Dist& d1, const Dist& d2);

};

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

	// test > operatoor
	cout << "\nIs d1 > d2? " << ((d1 > d2) ? "Yes" : "No") << endl;

	// test prefix ++
	++d2;
	cout << "\nAfter prefix ++dx: ";
	d2.print();


	// test > operatoor
	d2++;
	cout << "\nAfter postfix ++dx: ";
	d2.print();

	// test +=
	d1 += 100;
	cout << "\nAfter d1 += 100: ";
	d1.print();

	// Test assingment operator
	d3 = d1;
	cout << "\nAfter d3 = d1: ";
	d3.print();

	d4 = d3 = d2;
	cout << "\nAfter d4 = d3 = d2: " << endl;

	cout << "d3: ";
	d3.print();

	cout << "\nd4: ";
	d4.print();

}
