#include <stdio.h>

int removeKey(int arr[], int size, int key) {
    int count = 0; // Count of values not equal to the key
    
    for (int i = 0; i < size; i++) {
        if (arr[i] != key) {
            arr[count] = arr[i]; // Copy the valid element forward
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {3, 1, 2, 3, 4, 3, 5}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int newSize = removeKey(arr, size, key);

    printf("Modified array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of values not equal to %d: %d\n", key, newSize);

    return 0;
}
