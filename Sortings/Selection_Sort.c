#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// viewing the array
void peek(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to perform insertion sort (performs sorting inplace)
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main () {
    int arr[5] = {5, 4, 3, 2, 1};
    printf("Before sorting\n");
    peek(arr, 5);
    // function call
    insertion_sort(arr, 5);
    printf("After sorting\n");
    peek(arr, 5);
}