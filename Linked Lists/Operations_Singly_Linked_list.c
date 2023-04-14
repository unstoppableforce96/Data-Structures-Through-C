// Singly Linked List operations
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head = NULL;

void insert_at_head(NODE *nn) {
	if (head == NULL) { // there are no nodes
		head = nn;
	}
	else {
		nn -> next = head;
		head = nn;
	}
}
void insert_at_end(NODE *nn) {
	if (head == NULL) {
		head = nn;
	}
	else {
		NODE *temp = head;
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = nn; // inserting new  node at tail
	}
}
void delete_at_head() {
	if (head == NULL) {
		printf("No Nodes\n");
		return;
	}
	printf("Deleted element is %d: \n", head -> data);
	NODE* dn = head; // storing to be deleted node in dn variable to free
	head = head -> next; //
	free(dn); // deallocating memory
}
void delete_at_end() {
	if (head == NULL) { // list is empty
		printf("No Nodes\n");
	}
	else if (head -> next == NULL) { // list is containing single node
		printf("Deleted element is %d\n", head -> data);
		head = NULL;
	}
	else { // if list is containing more than 1 node
		NODE *temp = head;
		while (temp -> next -> next != NULL) {
			temp = temp -> next;
		}
		printf("Deleted element is %d\n", temp -> next -> data);
		NODE *dn = temp -> next;
		temp -> next = NULL;
		free(dn);
	}
}
void insert_at_pos(NODE *nn, int pos) {
	if (pos == 1) {
		insert_at_head(nn);
	}
	else {
		int flag = 0;
		NODE *temp = head;
		int c = 1;
		while (c < pos - 1) {
			if (temp == NULL) {
				flag = 1;
				break;
			}
			c++;
			temp = temp -> next;
		}
		if (flag == 0) {
			nn -> next = temp -> next;
			temp -> next = nn;
		}
		else {
			printf("Invalid Position\n");
		}
	}
}

void delete_at_pos(int pos) {
	if (pos == 1) {
		delete_at_head();
	}
	else if (head == NULL) {
        printf("No Nodes\n");
	}
	else {
		int flag = 0;
		NODE *temp = head;
		int c = 1;
		while (c < pos - 1) {
			c++;
			temp = temp -> next;
			if (temp == NULL) {
				flag = 1;
				break;
			}
		}
		if (flag == 0 && temp -> next != NULL) {
            printf("Deleted Element is %d\n", temp -> next -> data);
			temp -> next = temp -> next -> next;
		}
		else {
			printf("Invalid Position\n");
		}
	}
}

void display() {
	if (head == NULL) {
		printf("No Nodes\n");
		return;
	}
	NODE *temp = head;
	while (temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp ->  next;
	}
	printf("\n");
}

int main() {
	while (1) {
		int choice;
		printf("Enter\n1. Insert at head\n2. Insert at end\n3. Delete at head\n4. Delete at end\n5. Insert at pos\n6. Delete at pos\n7. Display\nand anything else to exit");
		scanf("%d", &choice);
		if (choice == 1) {
			// insert_at_head()
			int val;
			printf("Enter value to be inserted: ");
			scanf("%d", &val);
			NODE *nn = (NODE *)malloc(sizeof(NODE));
			nn -> data = val;
			nn -> next = NULL;
			insert_at_head(nn);
		}
		else if (choice == 2) {
			// insert_at_end()
			int val;
			printf("Enter value to be inserted: ");
			scanf("%d", &val);
			NODE *nn = (NODE *)malloc(sizeof(NODE));
			nn -> data = val;
			nn -> next = NULL;
			insert_at_end(nn);
		}
		else if (choice == 3) {
			// delete_at_head()
			delete_at_head();

		}
		else if (choice == 4) {
			// delete_at_end();
			delete_at_end();

		}
		else if (choice == 5) {
			// insert_at_pos()
			NODE *nn = (NODE *)malloc(sizeof(NODE));
			int val;
			printf("Enter a value to be inserted: ");
			scanf("%d", &val);
			nn -> data = val;
			nn -> next = NULL;
			int pos;
			printf("Enter the position to insert the node: ");
			scanf("%d", &pos);
			insert_at_pos(nn, pos);
		}
		else if (choice == 6) {
			// delete_at_pos()
			int pos;
			printf("Enter a position: ");
			scanf("%d", &pos);
			delete_at_pos(pos);
		}
		else if (choice == 7) {
			// display()
			display();
		}
		else {
			printf("Thank YOU!");
			break;
		}
	}
}
