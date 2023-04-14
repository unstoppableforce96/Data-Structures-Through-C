// Binary Search Using recursion
#include <stdio.h>
int binary_search_rec(int *arr, int n, int se, int low, int high) {
	if (low > high) return -1;
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == se) 
			return mid;
		else if (se > arr[mid])
			binary_search_rec(arr, n, se, mid + 1, high);
		else
			binary_search_rec(arr, n, se, low, mid - 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int se;
	scanf("%d", &se);
	int res = binary_search_rec(arr, n, se, 0, n - 1);
	if (res == -1) {
		printf("Element not found");
	} else {
		printf("Element found at index %d", res);
	}
	return 0;
}