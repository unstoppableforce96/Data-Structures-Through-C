#include <stdio.h>
#define min(a, b) (a < b) ? a : b // simple macro to find minimum of two values

// merge function to merge two sorted arrays
void merge(int *arr, int L, int M, int R) {
	int i = L, j = M + 1, k = 0;
	int res[R - L + 1];
	while (i <= M && j <= R) {
		if (arr[i] <= arr[j]) {
			res[k++] = arr[i++];
		}
		else {
			res[k++] = arr[j++];
		}
	}
	while (i <= M) {
		res[k++] = arr[i++];
	}
	while (j <= R) {
		res[k++] = arr[j++];
	}
	k = 0;
	for (int z = L; z <= R; z++) {
		arr[z] = res[k++];
	}
}
// Iterative function to perform merge sort
void merge_sort(int *arr, int n) {
	int L, R, M;
	for (int p = 1; p < n; p *= 2) {
		for (int i = 0; i < n; i += 2 * p) {
			L = i;
			M = min(L + p - 1, n - 1);
			R = min(L + 2 * p - 1, n - 1);
			merge(arr, L, M, R);
			// printArray(arr, n);
		}
	}
}
// To view the array
void peek(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main () {
    int arr[5] = {64, 25, 12, 22, 11};
    printf("Before sorting\n");
    peek(arr, 5);
    // function call
    merge_sort(arr, 5);
    printf("After sorting\n");
    peek(arr, 5);
}
