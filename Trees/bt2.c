// BT from Array (Recursive)
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

NODE* constructBT(int *arr, int i, int n) {
	NODE *temp = NULL;
	if (i < n && arr[i] != 0) {
		// new node
		temp = createNode(arr[i]);
		
		// left
		temp->left = constructBT(arr, 2 * i + 1, n);
		
		// right
		temp->right = constructBT(arr, 2 * i + 2, n);
	}
	return temp;
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
	scanf("%d", &n);
	printf("Enter node values: ");
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	NODE *root = constructBT(arr, 0, n);
	inorder(root);
}