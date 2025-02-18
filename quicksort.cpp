#include <iostream>
using namespace std;


int divide(int arr[], int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}



void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int x = divide(arr, left, right);
        quickSort(arr, left, x - 1);
        quickSort(arr, x, right);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int example[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(example)/sizeof(example[0]);

   cout << "Original array: ";
    printArray(example, n);
    quickSort(example, 0, n-1);

    cout << "Array sorted: ";
    printArray(example, n);


    return 0;
}
