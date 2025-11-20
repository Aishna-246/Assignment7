#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If the left element is greater than the right element, swap them
        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        // Scan the remaining unsorted part
        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum element at correct position
        swap(arr[left], arr[minIndex]);

        // If max element was swapped when placing min element,
        // update its index
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum element at correct position
        swap(arr[right], arr[maxIndex]);

        // Narrow down the range
        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array (Improved Selection Sort):\n";
    printArray(arr, n);

    return 0;
}
