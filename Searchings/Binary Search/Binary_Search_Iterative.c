#include <stdio.h>
int binary_search(int *arr, int n, int se) {
	int low = 0, high = n - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (se == arr[mid]) {
            return mid;
		}
		else if (se > arr[mid]) {
            low = mid + 1;
		}
		else {
            high = mid - 1;
		}
	}
	return -1;
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
	int res = binary_search(arr, n, se);
	if (res == -1) {
		printf("Element not found");
	} else {
		printf("Element found at index %d", res);
	}
	return 0;
}
