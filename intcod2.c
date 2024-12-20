#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0; // If the array is empty, return 0

    int j = 0; // Pointer for the new array's index

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i]; // Update the array to keep unique elements in place
        }
    }

    return j + 1; // Return the new size of the array
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 5, 5, 6}; // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int newSize = removeDuplicates(arr, size);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
