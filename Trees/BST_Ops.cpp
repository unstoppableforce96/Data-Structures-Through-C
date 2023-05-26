#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node NODE;

NODE* BST_insert(NODE *root, NODE *nn) {
	if (root == NULL) {
		return nn;
	}
	if (root->data == nn->data) {
		return root;
	}
	else if (root->data > nn->data) {
		root->left = BST_insert(root->left, nn);
	}
	else {
		root->right = BST_insert(root->right, nn);
	}
	return root;
}

int get_io_successor(NODE *root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

NODE* BST_delete(NODE *root, int val) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->data > val) {
		root->left = BST_delete(root, val);
	}
	else if (root->data < val) {
		root->right = BST_delete(root, val);
	}
	else {
		if (root->left == NULL) {
			root->right = NULL;
		}
		else if (root->right == NULL) {
			root->left = NULL;
		}
		else {
			int succ = get_io_successor(root->right);
			root->data = succ;
			root->right = BST_delete(root->right, succ);
		}
	}
	return root;
}

void BST_LoT(NODE *root) {
	if (root == NULL) {
		printf("No TREE!\n");
		return;
	}
	NODE *q[100];
	q[0] = root;
	int front = 0, rear = 1;
	while (front != rear) {
		NODE *pop = q[front++];
		if (pop->left != NULL) {
			q[rear++] = pop->left;
		}
		if (pop->right != NULL) {
			q[rear++] = pop->right;
		}
		printf("%d ", pop->data);
		pop = NULL;
		free(pop);
	}
	printf("\n");
}

int main() {
	printf("Binary Search Tree\n");
	int ch;
	NODE *root = NULL;
	while (1) {
		printf("Enter\n1. Insert\n2. Delete\n3. Display any other to exit");
		scanf("%d", &ch);
		if (ch == 1) {
			int val;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d", &val);
			NODE *nn = (NODE *)malloc(sizeof(NODE));
			nn->data = val;
			nn->left = NULL;
			nn->right = NULL;
			root = BST_insert(root, nn);
		}	
		else if (ch == 2) {
			// delete
			int d;
			printf("Enter a value to be deleted: ");
			scanf("%d", &d);
			root = BST_delete(root, d);
		}
		else if (ch == 3) {
			// Lever Order Traversal
			BST_LoT(root);
		}
		else {
			printf("Thank YOU!");
			break;
		}
	}
	
}