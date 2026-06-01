#include <iostream>
using namespace std;

template <typename T>
void display(T arr[], int size) {
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
int findMinIndexFrom(T arr[], int size, int start) {
    int minIndex = start;

    for (int i = start + 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}

template <typename T>
void mySort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = findMinIndexFrom(arr, size, i);

        if (minIndex != i) {
            MySwap(arr, i, minIndex);
        }
    }
}

int main() {
    int nums[] = { 5, 2, 9, 1, 7 };
    string names[] = { "Ali", "John", "Sara", "Mike" };

    mySort(nums, 5);
    mySort(names, 4);

    display(nums, 5);
    display(names, 4);

    return 0;
}