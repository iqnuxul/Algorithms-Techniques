#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    bool stillSorting;
    for (int i = 0; i < n - 1; i++) {
        stillSorting = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                stillSorting = true;
            }
        }
        if (!stillSorting) {
            break;
        }
    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minVal = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minVal]) {
                minVal = j;
            }
        }
        if (minVal != i) {
            swap(arr[i], arr[minVal]);
        }
    }
}



void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int bubbleExample[] = {4, 3, 5, 1, 2, 9, 0};
    int selectionExample[] = {4, 3, 5, 1, 2, 9, 0};
    int n = sizeof(bubbleExample) / sizeof(bubbleExample[0]);

    cout << "Original array: ";
    printArray(bubbleExample, n);

    bubbleSort(bubbleExample, n);

    cout << "Array sorted with Bubble Sort: ";
    printArray(bubbleExample, n);

    

    selectionSort(selectionExample, n);

    cout << "Array sorted with Selection Sort: ";
    printArray(selectionExample, n);

    return 0;
}
