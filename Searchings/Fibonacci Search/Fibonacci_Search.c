// Fibonacci Search
#include <stdio.h>
#define min(a, b) a < b ? a : b
int fibonacci_search(int *arr, int n, int se) {
	int a = 0, b = 1, c;
	while (c < n) {
		a = b;
		b = c;
		c = a + b;
	}
	int offset = -1;
	while (c > 1) {
		int pos = min(offset + a, n - 1);
		if (se == arr[pos]) {
			return pos;
		}
		else if (se < arr[pos]) {
			// bringing all 3 fibonacci numbers 1 fibonacci down
			c = b;
			b = a;
			a = c - b;
			// setting offset to current position
			offset = pos;
		}
		else {
			// bringing all 3 fibonacci numbers 2 fibonacci down
			c = a;
			b = b - a;
			a = c - b;
		}
	}
	if (arr[offset + 1] == se) {
		return offset + 1;
	}
	return -1;
}

int main() {
	int arr[6] = {6, 5, 4, 3, 2, 1};
	int se;
	scanf("%d", &se);
	int res = fibonacci_search(arr, 6, se);
	if (res == -1) {
		printf("Element not found");
	}
	else {
		printf("Element found at %d index", res);
	}
	return 0;
}