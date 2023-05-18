// polynomial expression representation using linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
	int expo;
	float coeff;
	struct node *next;
};

typedef struct node NODE;

NODE* insert(NODE* head, float co, int ex) {
	NODE* temp;
	NODE* nn = (NODE *)malloc(sizeof(NODE));
	nn -> coeff = co;
	nn -> expo = ex;
	nn -> next = NULL;
	
	if (head == NULL || ex > head -> expo) {
		nn -> next = head;
		head = nn;
	}
	else {
		temp = head;
		while (temp -> next != NULL && temp -> next -> expo > ex) {
			temp = temp -> next;
		}
		nn -> next = temp -> next;
		temp -> next = nn;
	}
	return head;
}

NODE* create(NODE* head) {
	int n;
	float coeff;
	int expo;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter the coefficient for term %d: ", i + 1);
		scanf("%f", &coeff);
		printf("Enter the exponent for term %d: ", i + 1);
		scanf("%d", &expo);
		head = insert(head, coeff, expo);
	}
	return head;
}

void print(NODE* head) {
	if (head == NULL) {
		printf("No Polynomial\n");
	}
	else {
		NODE* temp = head;
		while (temp != NULL) {
			printf("(%.1fx^%d)", temp -> coeff, temp -> expo);
			temp = temp -> next;
			if (temp != NULL) {
				printf(" + ");
			}
			else {
				printf("\n");
			}
		}
	}
}


int main() {
	printf("Polynomial\n");
	NODE *head = NULL;
	head = create(head);
	print(head);
	return 0;
}