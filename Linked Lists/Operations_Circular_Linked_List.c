#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

Node *head = NULL;

void insert_at_head(Node *nn) {
	if (head == NULL) {
		head = nn;
		head -> next = head;
	}
	else {
		Node *temp = head;
		while (temp -> next != head) {
			temp = temp -> next;
		}
		temp -> next = nn;
		nn -> next = head;
		head = nn;
	}
}

void insert_at_end(Node *nn) {
	if (head == NULL) {
		head = nn;
		nn -> next = head;
	}
	else {
		Node *temp = head;
		while (temp -> next != head) {
			temp = temp -> next;
		}
		temp -> next = nn;
		nn -> next = head;
	}
}

void delete_at_head() {
	if (head == NULL) {
		printf("No Nodes\n");
	}
	else if (head -> next == head) {
		printf("%d is deleted\n", head -> data);
		head = NULL;
	}
	else {
		Node *temp = head;
		while (temp -> next != head) {
			temp = temp -> next;
		}
		temp -> next = head -> next;
		printf("%d is deleted\n", head -> data);
		head = head -> next;
	}
}

void delete_at_end() {
	if (head == NULL) {
		printf("No Nodes\n");
	}
	else if (head -> next == head) {
		printf("%d is deleted\n", head -> data);
		head = NULL;
	}
	else {
		Node *temp = head;
		while (temp -> next -> next != head) {
			temp = temp -> next;
		}
		printf("%d is deleted\n", temp -> next -> data);
		temp -> next = head;
	}
}

void display() {
	if (head == NULL) {
		printf("No Nodes\n");
		return;
	}
	Node *temp = head;
	do {
		printf("%d ", temp -> data);
		temp = temp -> next;
	} while (temp != head);
	printf("\n");
}

void display_n_nodes(int n) {
	Node *temp = head;
	for (int i = 0; i < n; i++) {
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

int main() {
	while (1) {
		int ch;
		printf("Enter\n1. Insert at head\n2. Insert at end\n3. Delete at head\n4. Delete at end\n5. Display\n6. Display_n_nodes\nand any other to exit: ");
		scanf("%d", &ch);
		if (ch == 1) {
			// insert_at_head()
			Node *nn = (Node *)malloc(sizeof(Node));
			int val;
			printf("Enter an element to be inserted: ");
			scanf("%d", &val);
			nn -> data = val;
			nn -> next = NULL;
			insert_at_head(nn);
		}
		else if (ch == 2) {
			// insert_at_end()
			Node *nn = (Node *)malloc(sizeof(Node));
			int val;
			printf("Enter an element to be inserted: ");
			scanf("%d", &val);
			nn -> data = val;
			nn -> next = NULL;
			insert_at_end(nn);
		}
		else if (ch == 3) {
			// delete_at_head()
			delete_at_head();
		}
		else if (ch == 4) {
			// delete_at_end()
			delete_at_end();
			
		}
		else if (ch == 5) {
			// display()
			display();
			
		}
		else if (ch == 6) {
			// display_n_nodes;
			int n;
			scanf("%d", &n);
			display_n_nodes(n);
		}
		else {
			printf("Thank YOU!");
			break;
		}
	}
}