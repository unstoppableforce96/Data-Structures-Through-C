#include <stdio.h>
#include <stdio.h>
// helper function for swapping two values in-place (call by reference)
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
// partition using Lomuto Partition Technique
int lomuto_partition(int *arr, int l, int r) {
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[r], &arr[i + 1]);
	return i + 1;
}
// recursive quick sort function
void quick_sort(int *arr, int l, int r) {
	if (l < r) {
		int p = lomuto_partition(arr, l, r);
		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, r);
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
    quick_sort(arr, 0, 5-1);
    printf("After sorting\n");
    peek(arr, 5);
}
