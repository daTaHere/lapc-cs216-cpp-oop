#include <iostream>
#include <functional>    // function, bind
#include <algorithm>     // sort
#include <vector>
#include <numeric>       // accumulate

using namespace std;

//==============================================================
// Lambda Expression Syntax
//==============================================================

// [capture](parameters) -> return_type {
//     function body
// };

// capture:
//     variables from surrounding scope

// Lambdas are useful for:
// 1. Short one-time functions
// 2. Callbacks
// 3. Sorting
// 4. STL algorithms
// 5. Functional programming

//==============================================================
struct Student {
    string name;
    int age;
};

//==============================================================
int addFunc(int a, int b) {
    return a + b;
}

//==============================================================
// Function used with bind()

int addOffset(int a, int b, int offset) {
    return a + b + offset;
}

//==============================================================
// Callback Function
//==============================================================

// doOp accepts:
// 1. two integers
// 2. any callable object

// callable object can be:
// - lambda
// - regular function
// - function pointer
// - functor
// - bind expression

//==============================================================

void doOp(int x, int y, const function<int(int, int)>& op) {
    int result = op(x, y);
    cout << "Result = " << result << endl;
}

//==============================================================
// Functor Class
//==============================================================

// functor (or function object) is an object that can be called like
// a function by overloading the operator() (the function call operator)
// within a class or struct

class Addition {
public:

    int operator()(int a, int b) const {

        return a + b;
    }
};


//==============================================================
// Print Students
//==============================================================

void printStudents(const vector<Student>& students) {

    for (const auto& s : students) {

        cout << s.name
            << " - "
            << s.age
            << " years old" << endl;
    }

    cout << endl;
}

//==============================================================
// Main
//==============================================================
int main() {
    cout << "\nLAMBDA EXPRESSIONS & CALLBACKS" << endl;
    cout << "================================" << endl;

    //==============================================================
    // 1. SIMPLE LAMBDA
    //==============================================================
    auto sayHi = []() {

        cout << "Hello from lambda!" << endl;
        };

    sayHi();

    //==============================================================
    // 2. LAMBDA WITH PARAMETERS
    //==============================================================

    auto add = [](int a, int b) -> int {
        return a + b;
    };

    cout << "\n10 + 11 = " << add(10, 11) << endl;

     //==============================================================
     // 3. LAMBDA WITH CAPTURE
     //==============================================================
        int x = 3;
        int y = 10;

        auto multiply = [x,y](){
            return x * y;
            };

    cout << "\nCapture multiply result = " << multiply() << endl;

    //==============================================================
    // 4. CALLBACKS LAMBDA
    //==============================================================

    cout << "\n-----Callback Examples ----" << endl;

    // Addition
    doOp(10, 5, [](int a, int b) {
        return a + b;
        });

    // Mulitpulcation
    doOp(8, 4, [](int a, int b) {
        return a * b;
        });

    // Subtraction
    doOp(20, 6, [](int a, int b) {
        return a - b;
        });

    //==============================================================
    // 5. SORTING WITH LAMBDAS
    //==============================================================

    vector<Student> students = {

        {"Pete", 21},
        {"Alex", 25},
        {"Emma", 18},
        {"Mary", 19}

    };

    cout << "\n--- Original Students ---" << endl;

    printStudents(students);

    //====== Sort by age  ====

    sort(students.begin(),students.end(),
            [](const Student& s1, const Student& s2) {
                return s1.age < s2.age;
            }
        );

    cout << "===== Sorted By Age ======" << endl;
    printStudents(students);

    //====== Sort by name  ====

    sort(students.begin(),students.end(),
        [](const Student& s1, const Student& s2) {
                return s1.name < s2.name;
            }
        );

    cout << "===== Sorted By Name ======" << endl;
    printStudents(students);

    //=====================================
    // 6. DIFFERENT WAYS TO PASS FUCTIONS
    //=====================================
    cout << "-------- Different Callable Types ----" << endl;

    //-----------------------------------------
    // A. Regular Functions
    //-----------------------------------------
    cout << "Call Regular Functions: ";
    doOp(100, 19, addFunc);

    //-----------------------------------------
    // B. Regular Pointer
    //-----------------------------------------
    cout << "Call Regular Pointer: ";
    int (*funcPtr)(int, int) = addFunc;
    doOp(200, 19, funcPtr);

    //-----------------------------------------
    // C. Function Obj
    //-----------------------------------------
    cout << "Call Regular Object: ";
    Addition addOp;
    doOp(300, 19, addOp);

    //--------------------------------------------------------------
    // D. Bind Expression
    //--------------------------------------------------------------

    // bind function creates a callable wrapper that acts as a shortcut
    // function creates a callable wrapper that acts as a shortcut.
    //
    // It forwards the arguments passed to boundAdd to the original
    // addOffset function, inserting 10 as the third parameter automatically
    cout << "Call binding : ";
    auto boundAdd =
        bind(addOffset,
            placeholders::_1,
            placeholders::_2,
            10);
    doOp(400, 19, boundAdd);

    //--------------------------------------------------------------
    // E. function Var
    //--------------------------------------------------------------
    cout << "Call by function var : ";
    function<int(int, int)> plus13Op =
        [](int a, int b) {
        return a + b + 13;
        };

    doOp(500, 19, plus13Op);
    //=====================================
    // 7. REF with LAMBDA
    //=====================================
    cout << "\n--- Capture By Reference ---" << endl;

    int count = 0;

    auto incDisplay = [&count]() {
            count++;
            cout << "Counter = " << count << endl;
            };

    for (int i = 0; i < 5; i++) {
        incDisplay();
    }

    //==============================================================
    // 8. accumulate() WITH LAMBDA
    //==============================================================

    cout << "\n--- accumulate() Example ---" << endl;

    vector<int> numbers = { 1, 2, 3, 4, 5 };

    // Calculate product of elements

    int product = accumulate(numbers.begin(), numbers.end(),1,
                             [](int x, int y) {
                                return x * y;
                              }
                            );

    cout << "Product = " << product << endl;


    //==============================================================
    // 9. find_if() WITH LAMBDA
    //==============================================================

    cout << "\n--- find_if() Example ---" << endl;

    vector<int> values = { 4, 7, 12, 19, 22 };

    auto it = find_if(values.begin(), values.end(),
                    [](int n) {
                        return n > 10;
                    }
               );

    if (it != values.end()) {
        cout << "First value > 10 is "
            << *it << endl;
    }

    //==============================================================
    // 10. for_each() WITH LAMBDA
    //==============================================================

    cout << "\n--- for_each() Example ---" << endl;

    for_each(values.begin(),values.end(),
        [](int n) {
            cout << n << " ";
        }
    );

    cout << endl;

    //==============================================================
    // 11. Mutable Lambda
    //==============================================================

        cout << "\n--- Mutable Lambda ---" << endl;
        int num = 5;

        auto changeValue = [num]() mutable {
            num += 10;
            cout << "Inside lambda: "
                << num << endl;
            };

        changeValue();

        cout << "Outside lambda: "
            << num << endl;
    
	return 0;
}