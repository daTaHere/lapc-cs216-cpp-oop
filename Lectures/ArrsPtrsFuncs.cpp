#include <iostream>

using namespace std;

int main()
{
    int x = 19;
    int y = 10;
    int num[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    int* ptr = NULL;
    int* newPtr = nullptr;
    int aa, bb;
    int* pp1, pp2;
    int* pp3, ppr;

    //--------------------------------------

    ptr = &x; // store the address of x into ptr
    cout << "address of x;  &x :" << &x << endl;
    cout << "size of interger in c++ :" << sizeof(x) << endl;
    cout << "value of x:" << x << endl;
    cout << "The content of where ptr is pointing to " << *ptr << endl;

    //---------------------

    // x = ++y; y == 11, x == 11 postfix ( increment y by 1 then assign it to x )
    // x = y++; y == 11, x == 10 prefix ( assign value of y before incrementing )
    cout << "x= " << x << " y= " << y << endl;


    //-------------------------
    (*ptr)++; // *ptr = *ptr + 1
    cout << "Value of x by ptrs after ++: " << x << endl;
    // (*ptr) has higher precendence than the multiplication operator
    *ptr = *ptr * 3 + 1;

    cout << "Value of x after 3 times plus 1: " << x << endl;
    cout << "-------------------------------\n";
    //--------------------------------------------------------

    *ptr *= 2;
    ptr = &y;
    *ptr *= 2;
    newPtr = num;
    cout << "value of x: " << x << endl;
    cout << "valie of y: " << y << endl;
    cout << "name of the array: " << num << endl;
    cout << "numa of the arry: " << num + 1 << endl;
    cout << "ptr to arry: " << newPtr << endl;

    //--------------------------------------------------------


    cout << "first element of num[0]: " << num[0] << endl;
    cout << "first element of num *num: " << *num << endl;
    cout << "addres of the second elem: " << num + 1 << endl;
    cout << "second elem of num; num[1]: " << num << endl;

    for (int i = 0; i < 10; i++) {
        cout << *newPtr << endl;
        newPtr++;
    }

    // dynamic allocation if memory ==> (heap)
    int* dPtr = nullptr;
    dPtr = new(int);
    *dPtr = 110;
    cout << "value iof the dynamic allocated memory: " << *dPtr << endl;
    int* myArray = new int[10];
    myArray[0] = 100;
    *(myArray + 1) = 200;
    cout << "first elem of Array: " << myArray[0] << endl;
    cout << "second elem of Array: " << *(myArray + 1) << endl;
    // NO BUILT-IN GARBAGE COLLECTION must handle manually !!!
    delete dPtr;
    delete[] myArray;

    //--------------------------------------------
    // Array of Interger Pointers
    int a = 10, b = 20, c = 30;
    int* arr1[3]{ &a, &b, &c }; // Array of intergers pointers
    cout << "Value pointed by arr1[0]: " << *arr1[0] << endl;
    cout << "Value pointed by arr1[1]: " << *arr1[1] << endl;
    cout << "Value pointed by arr1[2]: " << *arr1[2] << endl;

    // arr1 ? array of (int*)
    //
    // arr1[0] ? gives &a
    // *arr1[0] ? gives 10

    //--------------------------------------------
    // Array of Pointers to Pointers 
    int* p1 = &a; // "&" --> Address of <---
    int* p2 = &b;
    int* p3 = &c;
    int** arrOfPtr = new int* [3]; // Array of pointers to pointers
    arrOfPtr[0] = p1;
    arrOfPtr[1] = p2;
    arrOfPtr[2] = p3;

    // Accessing values
    cout << "Value at arrOfPtr[0]: " << **(arrOfPtr + 0) << endl; // 10
    cout << "Value at arrOfPtr[1]: " << **(arrOfPtr + 1) << endl; // 20
    cout << "Value at arrOfPtr[2]: " << **(arrOfPtr + 2) << endl; // 30
    delete[] arrOfPtr; // Free allocated memory

    //--------------------------------------------

    // Array of Pointers with Dynamic Memory
    int* arr2[3]; // Array of integer pointers
    // Dynamically allocate memory
    arr2[0] = new int(100);
    arr2[1] = new int(20);
    arr2[2] = new int(300);
    // Access values 
    cout << "First element: " << *arr2[0] << endl;
    cout << "Second element: " << arr2[1] << endl;
    cout << "Third element: " << *arr2[2] << endl;

    //--------------------------------------------
    // Array of String pointers (Char Pointers)

    const char* fruits[] = { "Apple", "Orange", "Grape" };
    cout << "First fruit: " << fruits[0] << endl;
    cout << "Second fruit: " << fruits[1] << endl;
    cout << "Third fruit: " << fruits[2] << endl;

    // ----------------------------------
    int a1[] = { 1,2,3 };
    int a2[] = { 4,5,6 };
    int a3[] = { 7,8,9 };
    int* myArr[] = { a1, a2, a3 };// Array of pointers to arrays

    // Accessing values
    cout << "myArr[0][1]: " << myArr[0][1] << endl; // 2
    cout << "myArr[1][2]: " << myArr[1][2] << endl; // 6
    cout << "myArr[2][0]: " << myArr[2][0] << endl; // 7
    // ----------------------------------
}
