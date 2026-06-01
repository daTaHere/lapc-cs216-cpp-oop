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


	//=================        Member methods     =========================
	//// 1.Prefix --
	Dist& operator--() {
		meter--;
		simplify();
		return *this;
	}

	//// 2.Postfix --
	Dist& operator--(int x) {
		Dist temp(*this);
		--(*this);
		simplify();
		return temp;
	}

	// 3. -= operator 
	Dist& operator-=(const Dist& rhs) {
		kMeter -= rhs.kMeter;
		meter -= rhs.meter;
		simplify();
		return *this;
	}

	// 4. *- operator
	Dist& operator*=(const Dist& rhs) {
		meter = (kMeter * 1000 + meter) * (rhs.kMeter * 1000 + rhs.meter);
		kMeter = 0;
		simplify();
		return *this;
	}

	// 4. *- operator
	Dist& operator/=(const Dist& rhs) {
		meter = (kMeter * 1000 + meter) / (rhs.kMeter * 1000 + rhs.meter);
		kMeter = 0;
		simplify();
		return *this;
	}


	//=================        Friend Functions     =========================
	friend istream& operator>>(istream& stream, Dist& d); // >> operator
	friend ostream& operator<<(ostream& stream, const Dist& d); // << operator

	//friend Dist& operator--(Dist& d); // 1.Prefix -- operator
	//friend Dist operator--(Dist& d,int x); // 2.Postfix ++ operator

	//friend Dist& operator-=(Dist& lhs, const Dist& rhs); // 3. -= operator
	//friend Dist& operator*=(Dist& lhs, const Dist& rhs); // 4. *= operator
	//friend Dist& operator/=(Dist& lhs, const Dist& rhs); // 5. /= operator
	//

};

istream& operator >> (istream& stream, Dist& d) {
	stream >> d.kMeter >> d.meter;
	return stream;
};

ostream& operator << (ostream& stream, const Dist& d) {
	stream << d.kMeter << " kmeter and " << d.meter << " meter";
	return stream;
};


//// ======================      Function def    ==============================
//1.Prefix -- operator
//Dist& operator --(Dist& d) {
//	--d.meter;
//	d.simplify();
//	return d;
//
//}
//
//// 2.Postfix -- operator
//Dist operator --(Dist& d, int x) {
//	Dist temp = d;
//	--d;
//	return temp;
//}
//
//// 3. -= operator
//Dist& operator -= (Dist& lhs, const Dist& rhs) {
//	lhs.kMeter -= rhs.kMeter;
//	lhs.meter -= rhs.meter;
//	lhs.simplify();
//	return lhs;
//
//};
//
//Dist& operator*=(Dist& lhs, const Dist& rhs) {
//	lhs.meter = (lhs.kMeter * 1000 + lhs.meter) * (rhs.kMeter * 1000 + rhs.meter);
//	lhs.kMeter = 0;
//	lhs.simplify();
//	return lhs;
//}
//
//Dist& operator/=(Dist& lhs, const Dist& rhs) {
//	lhs.meter = (lhs.kMeter * 1000 + lhs.meter) / (rhs.kMeter * 1000 + rhs.meter);
//	lhs.kMeter = 0;
//	lhs.simplify();
//	return lhs;
//}


int main() {
	// Initial distances
	Dist d1(1, 200);
	Dist d2(2, 900);


	cout << d1 << endl;
	cout << d2 << endl;

	// test -- operator prefix overload
	cout << "\nTest --d1: " << --d1 << endl;

	// test -- operator postfix overload
	cout << "\nBefore d1--: " << d1-- << endl;
	cout << "\After d1--: " << d1 << endl;

	// test -= operator
	d2 -= d1;
	cout << "\n-= " << d2 << endl;

	// test *= operator
	d1 *= d1;
	cout << "*= " << d1 << endl;

	Dist d3(2, 2);
	// test *= operator
	d1 /= d3;
	cout << "/= " << d1 << endl;

	return 0;

}