#include <iostream>
using namespace std;


// helper
void printVal(const  int* arr, const int size) {
    for (const int* i = arr; i < arr + size; i++) {
        cout << *i << " ";
    }
    cout << endl;
}
// Function with ptrs

//=========================================
void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//==================================================
void reverseArray(int* arr, const int size) {
    printVal(arr, size);
    //---------------------------------------
    int* left = arr;
    int* right = arr + size - 1;
    while (left < right)  {
        // call our helper
        swapValues(left, right);
        left++;
        right--;
    }
    //------------------------
    printVal(arr, size);
}



int num[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

int main() {
    int x = 28;
    int y = 82;
    int *ptr1 =  &x;
    int* ptr2 = &y;

    swapValues(ptr1, ptr2);

    reverseArray( num, 10);
	return 0;
}