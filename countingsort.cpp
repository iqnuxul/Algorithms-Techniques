#include <iostream>
using namespace std;


void countSort(int arr[], int n) {
    
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    
    int count[maxVal + 1] = {0}; 

    
    for (int i = 0; i < n; i++) {
        count[arr[i]] = count[arr[i]] + 1;
    }


    
    int j = 0; //j是arr中下一个要放的位置
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;
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
    int example[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(example) / sizeof(example[0]);

    cout << "Original array:" << endl;
    printArray(example, n);

    countSort(example, n);

    cout << "Sorted Array：" << endl;
    printArray(example, n);

    return 0;
}
