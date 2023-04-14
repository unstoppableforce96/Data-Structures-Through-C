// Infix to Postfix Conversion
#include <stdio.h>
#include <string.h>
int preced(char ch) {
	if (ch == '^') return 3;
	else if (ch == '*' || ch == '/') return 2;
	else if (ch == '+' || ch == '-') return 1;
	return 0;
}
void convert_to_postfix(char *infix) {
	char postfix[1000], stack[1000];
	int top = -1, j = 0;
	for (int i = 0; i < strlen(infix); i++)  {
		if (preced(infix[i]) == 0) { // if its an operand
			postfix[j++] = infix[i];
		}
		else {
			if (top == -1) {
				stack[++top] = infix[i];
			}
			else {
				while (top != -1 && preced(infix[i]) <= preced(stack[top])) {
					postfix[j++] = stack[top--];
				}
				stack[++top] = infix[i];
			}
		}
	}
	while (top > -1) {
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	printf("%s", postfix);
}
int main() {
	char infix[1000];
	scanf("%s", infix);
	convert_to_postfix(infix);
	return 0;
}