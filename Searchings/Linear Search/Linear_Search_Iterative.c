// Linear Search - Iterative
#include <stdio.h>
// create an iterative function called linear_search
int linear_search(int *arr, int n, int se) {
	int i;
	for (i = 0; i < n; i++) {
		//i --> index, arr[i] --> element at ith index
		if (arr[i] == se) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n, i;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int se;
	scanf("%d", &se);
	int res = linear_search(arr, n, se);
	
	if (res == -1) {
		printf("Element not found");
	}
	else {
		printf("Found at %d index", res);
	}
}