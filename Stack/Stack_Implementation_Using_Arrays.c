#include <stdio.h>
#include <stdlib.h>
int stack[100], top = -1, size;
void push(int ele) {
	// checking if the stack is full
	if (top == size - 1) {
		printf("Stack is full. Adding more elements will overflow the stack\n");
		return;
	}
	// incrementing the top variable and inserting the element at index top;
	stack[++top] = ele;
}
int pop() {
	// checking if stack is empty
	if (top == -1) {
		return -1;
	}
	int rm_ele = stack[top];
	top--;
	return rm_ele;
}

void peek() {
	if (top == -1) {
		printf("Nothing is on the top of the stack to show\n");
		return;
	}
	printf("Element on top is: %d\n", stack[top]);
}

void display() {
	// printing all the stack element from top-to-bottom
	if (top == -1) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack is currenly having the following elements from top to bottom:\n");
	for (int i = top; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	printf("Enter size of stack: ");
	scanf("%d", &size);
	int choice;
	while (1) {
		printf("Enter 1.Push 2. Pop 3. Peek 4. Display Any other to Terminate: ");
		scanf("%d", &choice);
		if (choice == 1) {
			// implement push algorithm
			int element;
			printf("Enter an element to be pushed into the stack: ");
			scanf("%d", &element);
			push(element);
		}
		else if (choice == 2) {
			// implement pop algorithm
			int removed_element = pop();
			if (removed_element == -1) {
				printf("Stack is empty. Cannot perform deletions.\n");
			}
			else {
				printf("Element popped out from the stack is: %d\n", removed_element);
			}
			
		}
		else if (choice == 3) {
			// implement peek algorithm
			peek();
		}
		else if (choice == 4) {
			// implement Display algorithm
			display();
		}
		else {
			printf("Thank you\n");
			break;
		}
	}
	return 0;
}