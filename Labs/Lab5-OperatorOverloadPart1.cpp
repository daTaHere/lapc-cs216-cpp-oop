#include <iostream>

using namespace std;
/*
Overload the following operators both as a member function and as a friend
" -, *, /, <, <=, >=, ==, !=
*/

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

	const Dist& operator = (const Dist& rhs) {
		if (this != &rhs) {
			kMeter = rhs.kMeter;
			meter = rhs.meter;
		}
		return *this;
	}

	//-----------------------------------------------------------
	// Operator Overloading  MEMBER FUNCTIONS
	//-----------------------------------------------------------
	// " - " operator --> member function
	//Dist operator - (const Dist& rhs) const {
	//	Dist result(kMeter - rhs.kMeter, meter - rhs.meter);
	//	result.simplify();
	//	return result;
	//}

		// " * " operator --> member function
	//Dist operator * (const Dist& rhs) const {
	//	int prod = (kMeter * 1000 + meter) * (rhs.kMeter * 1000 + rhs.meter);
	//	Dist result(0, prod);
	//	result.simplify();
	//	return result;
	//}

	// " / " operator --> member function
	//Dist operator / (const Dist& rhs) const {
	//	int qoution = (kMeter * 1000 + meter) / (rhs.kMeter * 1000 + rhs.meter);
	//	Dist result(0, qoution);
	//	result.simplify();
	//	return result;
	//}

	// " < " operator --->member function
	//bool operator < (const Dist& rhs) const {
	//	return (kMeter < rhs.kMeter);
	//}

	// " <= " operator --->member function
	//bool operator <= (const Dist& rhs) const {
	//	return (kMeter < rhs.kMeter || kMeter == rhs.kMeter);
	//}

	// " >= " operator --->member function
	//bool operator >= (const Dist& rhs) const {
	//	return (kMeter > rhs.kMeter || kMeter == rhs.kMeter);
	//}

	// " == " operator --->member function
	//bool operator == (const Dist& rhs) const {
	//	return (kMeter == rhs.kMeter);
	//}

	 //" != " operator --->member function
	//bool operator != (const Dist& rhs) const {
	//	return (kMeter != rhs.kMeter && meter != rhs.meter);
	//}

	// ======= Friends ======================

	friend Dist operator - (const Dist& d1, const Dist& d2);
	friend Dist operator * (const Dist& d1, const Dist& d2);
	friend Dist operator / (const Dist& d1, const Dist& d2);
	friend bool operator < (const Dist& d1, const Dist& d2);
	friend bool operator <= (const Dist& d1, const Dist& d2);
	friend bool operator >= (const Dist& d1, const Dist& d2);
	friend bool operator == (const Dist& d1, const Dist& d2);
	friend bool operator != (const Dist& d1, const Dist& d2);
};

Dist operator - (const Dist& d1, const Dist& d2) {
	Dist d;
	d.meter = d1.meter - d2.meter;
	d.kMeter = d1.kMeter - d2.kMeter;
	d.simplify();
	return d;
}

Dist operator * (const Dist& d1, const Dist& d2) {
	int prod = (d1.kMeter * 1000 + d1.meter) * (d2.kMeter * 1000 + d2.meter);
	Dist result(0, prod);
	result.simplify();
	return result;
}

Dist operator / (const Dist& d1, const Dist& d2) {
	int qoution = (d1.kMeter * 1000 + d1.meter) / (d2.kMeter * 1000 + d2.meter);
	Dist result(0, qoution);
	result.simplify();
	return result;
}

bool operator < (const Dist& d1, const Dist& d2) {
	return (d1.kMeter < d2.kMeter);
}

bool operator <= (const Dist& d1, const Dist& d2) {
	return (d1.kMeter <= d2.kMeter);
}
bool operator >= (const Dist& d1, const Dist& d2) {
	return (d1.kMeter < d2.kMeter || d1.kMeter == d2.kMeter);
}
bool operator == (const Dist& d1, const Dist& d2) {
	return (d1.kMeter == d2.kMeter && d1.kMeter == d2.kMeter);
}

bool operator != (const Dist& d1, const Dist& d2) {
	return (d1.kMeter != d2.kMeter && d1.kMeter != d2.kMeter);
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

	d3 = d1 - d2;
	d3.print();

	d4 = d1 * d2;
	d4.print();

	Dist d5 = d4 / d1;
	d5.print();

	// test < operatoor
	cout << "\nIs d1 < d2? " << ((d1 < d2) ? "Yes" : "No");
	// test < operatoor
	cout << "\nIs d2 < d1? " << ((d2 < d1) ? "Yes" : "No");
	// test < operatoor
	cout << "\nIs d1 < d2? " << ((d1 < d2) ? "Yes" : "No");
	cout << "\n=========================================\n" << endl;

	// test <= operatoor
	cout << "\nIs d2 <= d1? " << ((d2 <= d1) ? "Yes" : "No");
	// test <= operatoor
	cout << "\nIs d2 <= d2? " << ((d2 <= d2) ? "Yes" : "No");
	// test <= operatoor
	cout << "\nIs d1 <= d2? " << ((d1 <= d2) ? "Yes" : "No");
	cout << "\n=========================================\n" << endl;


	// test >= operatoor
	cout << "\nIs d2 >= d1? " << ((d2 >= d1) ? "Yes" : "No");
	// test >= operatoor
	cout << "\nIs d2 >= d2? " << ((d2 >= d2) ? "Yes" : "No");
	// test >= operatoor
	cout << "\nIs d1 >= d2? " << ((d1 >= d2) ? "Yes" : "No");

	cout << "\n=========================================\n" << endl;
	// test == operatoor
	cout << "\nIs d2 == d2? " << ((d2 >= d2) ? "Yes" : "No");
	cout << "\nIs d2 == d1? " << ((d2 == d1) ? "Yes" : "No");
	cout << "\nIs d1 == d2? " << ((d1 == d2) ? "Yes" : "No");

	cout << "\n=========================================\n" << endl;
	// test != operatoor
	cout << "\nIs d2 != d2? " << ((d2 != d2) ? "Yes" : "No");
	cout << "\nIs d2 != d1? " << ((d2 != d1) ? "Yes" : "No");

}

