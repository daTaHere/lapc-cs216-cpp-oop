#include <iostream>
#include <string>
using namespace std;
//====================================================
// TEMPLATE SORTING LAB
// Generic Programming using Templates
//====================================================
long long totalComparisons = 0;
long long totalSwaps = 0;

//====================================================
// TEMPLATE FUNCTION PROTOTYPES
//====================================================
template <typename T>
void display(T arr[], int size);
template <typename T>
void MySwap(T arr[], int index1, int index2);
template <typename T>
T findMin(T arr[], int size);
template <typename T>
int findMinIndex(T arr[], int size);
template <typename T>
int findMinIndexFrom(T arr[], int size, int start);
// NOTE:
// mySort() must ONLY use:
// 1. MySwap()
// 2. findMinIndexFrom()
template <typename T>
void mySort(T arr[], int size);
//====================================================
// TEMPLATE CLASS
//====================================================
template <typename T>
class SortClass {
private:
    T* arr;
    int size;
public:
    // TODO:
    // constructor
    SortClass(T a[], int s) {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = a[i];
        }
    }
    ~SortClass() {
        delete[] arr;
    }
    // TODO:
    void sort() {
        mySort(arr, size);
    }
    // TODO:
    // display array
    void display() {
        ::display(arr, size);
    }
};
//====================================================
// MAIN
//====================================================
int main() {
    int choice;
    int intArr[] = { 5,2,9,1,7 };
    double doubleArr[] = { 4.4,1.1,9.9,2.2 };
    char charArr[] = { 'z','a','m','b' };
    string stringArr[] = { "Ali","John","Sara","Mike" };
    int intSize = 5;
    int doubleSize = 4;
    int charSize = 4;
    int stringSize = 4;
    do {
        cout << "\n========== TEMPLATE SORT MENU ==========\n";
        cout << "1. Display Integer Array\n";
        cout << "2. Sort Integer Array\n";
        cout << "3. Display Double Array\n";
        cout << "4. Sort Double Array\n";
        cout << "5. Display Character Array\n";
        cout << "6. Sort Character Array\n";
        cout << "7. Display String Array\n";
        cout << "8. Sort String Array\n";
        cout << "9. Find Smallest Element in Integer Array\n";
        cout << "10. Test SortClass with Integer Array\n";
        cout << "0. Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            //------------------------------------------------
        case 1:
            display(intArr, intSize);

            break;
            //------------------------------------------------
        case 2:
            mySort(intArr, intSize);
            cout << "Sorted Integer Array:\n";
            display(intArr, intSize);
            break;
            //------------------------------------------------
        case 3:
            display(doubleArr, doubleSize);

            break;
            //------------------------------------------------
        case 4:
            mySort(doubleArr, doubleSize);
            cout << "Sorted Double Array:\n";
            display(doubleArr, doubleSize);
            break;
            //------------------------------------------------
        case 5:
            display(charArr, charSize);
            break;
            //------------------------------------------------
        case 6:
            mySort(charArr, charSize);
            cout << "Sorted Character Array:\n";
            display(charArr, charSize);
            break;
            //------------------------------------------------
        case 7:
            display(stringArr, stringSize);
            break;
            //------------------------------------------------
        case 8:
            mySort(stringArr, stringSize);
            cout << "Sorted String Array:\n";
            display(stringArr, stringSize);
            break;
            //------------------------------------------------
        case 9:
            cout << "Smallest Element = " <<
                findMin(intArr, intSize) <<
                endl;
            break;
            //------------------------------------------------
        case 10: {
            SortClass<int> s(intArr, intSize);
            s.sort();
            cout << "SortClass Integer Array:\n";
            s.display();
            break;
        }
               //------------------------------------------------
        case 0:
            cout << "Goodbye...\n";
            break;
            //------------------------------------------------
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
//====================================================
// TODO:
// implement SortClass member functions below
//====================================================
template <typename T>
void display(T arr[], int size) {
    if (size <= 0) {
        cout << "Empty Array" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void MySwap(T arr[], int index1, int index2) {
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}


template <typename T>
int findMinIndex(T arr[], int size) {
    return findMinIndexFrom(arr, size, 0);
}


template <typename T>
T findMin(T arr[], int size) {
    int min = findMinIndex(arr, size);
    return arr[min];
}


template <typename T>
int findMinIndexFrom(T arr[], int size, int start) {
    int minIndex = start;
    for (int i = start; i < size; ++i) {
        totalComparisons++;

        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

template <typename T>
void mySort(T arr[], int size) {
    for (int i = 0; i < size; ++i) {

        int minIndex = findMinIndexFrom(arr, size, i);
        if (minIndex != i) {
            MySwap(arr, i, minIndex);
            totalSwaps++;
        }
    }
}