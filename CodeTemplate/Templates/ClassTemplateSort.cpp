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

template <typename T>
class SortClass {
private:
    T* arr;
    int size;

public:
    SortClass(T a[], int s) {
        size = s;
        arr = new T[size];

        for (int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
    }

    ~SortClass() {
        delete[] arr;
    }

    void sort() {
        mySort(arr, size);
    }

    void display() {
        ::display(arr, size);
    }
};

int main() {
    int nums[] = { 5, 2, 9, 1, 7 };

    SortClass<int> sorter(nums, 5);

    sorter.sort();
    sorter.display();

    return 0;
}