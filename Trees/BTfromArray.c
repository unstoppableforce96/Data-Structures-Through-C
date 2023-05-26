// BT from Array
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node NODE;

NODE *q[100];
int front = 0, rear = 0;

NODE* createNode(int val) {
	NODE *nn = (NODE *)malloc(sizeof(NODE));
	nn->data = val;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

NODE* constructBT(int *arr, int n) {
	NODE *temp = createNode(arr[0]);
	q[rear++] = temp;
	int i = 0;
	while (1) {
		if (arr[i] == 0) {
			i++;
			continue;
		}
		if (2 * i + 1 >= n || 2 * i + 2 >= n) {
			break;
		}
		if (2 * i + 1 < n && arr[2 * i + 1] != 0) {
			NODE *t = createNode(arr[2 * i + 1]);
			q[rear++] = t;
			q[front]->left = t;
		}
		if (2 * i + 2 < n && arr[2 * i + 2] != 0) {
			NODE *t = createNode(arr[2 * i + 2]);
			q[rear++] = t;
			q[front]->right = t;
		}
		i++;
		front++;
	}
	return q[0];
}

void inorder(NODE *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int main() {
	int n;
	printf("Enter array size: ");
	scanf("%d", &n);
	printf("Enter node values: ");
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	NODE *root = constructBT(arr, n);
	inorder(root);
}