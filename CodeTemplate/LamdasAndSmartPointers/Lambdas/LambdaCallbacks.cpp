#include <iostream>
#include <functional>

using namespace std;

void doOp( int x, int y, const function<int(int, int)>& op ) {
    cout << op( x,  y ) << endl;
}

void callbackFunction( const string& message, const function<void(string)>& callback) {
    callback(message);
}

int main() {

    doOp(10, 5, [](int a, int b) {
            return a + b;
        }
    );

    doOp(10, 5, [](int a, int b) {
            return a * b;
        }
    );

    auto myCallback = [](string msg) {  
        cout << msg << endl; 
        };

    callbackFunction( "Hello Callback",  myCallback );

    return 0;
}