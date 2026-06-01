#include <iostream>
using namespace std;

// Common base class
class A {
public:
    void test() {
        cout << "A::test()" << endl;
    }
};

// Virtual inheritance prevents duplicate copies of A
class B : virtual public A {
};

// Virtual inheritance prevents duplicate copies of A
class C : virtual public A {
};

// D inherits from both B and C
class D : public B, public C {
};

int main() {
    D obj;

    obj.test();

    return 0;
}