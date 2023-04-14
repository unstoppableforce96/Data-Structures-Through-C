#include <stdio.h>
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
// Recursive function to perform merge sort
void merge_sort(int *arr, int l, int r) {
    if (r > l) {
		int m = (r + l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
// viewing the array
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
    merge_sort(arr, 0, 5 - 1);
    printf("After sorting\n");
    peek(arr, 5);
}
