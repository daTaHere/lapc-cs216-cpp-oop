#include <iostream>
#include <memory>

using namespace std;

class Book {
public:
    string title;

    Book( string t ) : title( t ) { }
};

int main() {

    shared_ptr<Book> b1 = make_shared<Book>( "C++ Programming" );

    cout << b1.use_count() << endl;

    shared_ptr<Book> b2 = b1;

    cout << b1.use_count() << endl;

    shared_ptr<Book> b3 = b1;

    cout << b1.use_count() << endl;

    return 0;
}