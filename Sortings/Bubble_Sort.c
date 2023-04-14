#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// peek function prints the given array on the screen
void peek(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// swap function to swap two elements in place (function works on reference)
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Bubble sort sorts the array in-place using exchange of elements techniques
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int swapped = 0;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

int main() {
    int A[] = {5, 4, 3, 2, 1};
    // before sorting
    printf("Before Sorting\n");
    peek(A, 5); // viewing the array
    bubble_sort(A, 5);
    // after sorting
    printf("After Sorting\n");
    peek(A, 5); // viewing the array
    return 0;
}
