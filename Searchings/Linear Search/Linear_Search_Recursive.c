// Linear Search - Recursive
#include <stdio.h>
// create a recursive function called linear_search
int linear_search_recursive(int *arr, int n, int i, int se) {
	if (i == n) {
        return -1;
	}
	if (arr[i] == se) {
        return i;
	}
	return linear_search_recursive(arr, n, i+1, se);
}
int main() {
	int n, i;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int se;
	scanf("%d", &se);
	int res = linear_search_recursive(arr, n, 0, se);
	if (res == -1) {
		printf("Element not found");
	}
	else {
		printf("Found at %d index", res);
	}
}
