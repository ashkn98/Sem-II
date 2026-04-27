#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
	stack[++top] = x;
}

char pop() {
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

int precedence (char x) {
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	return 0;
}

main() {
	char infix[MAX], postfix[MAX];
	int i, j = 0;
	char x;
	
	printf("Enter an infix expression: ");
	scanf("%s",infix);
	
	for (i=0; infix[i] != '\0'; i++) {
		if(isalnum(infix[i])) 
			postfix[j++] = infix[i];
		else if (infix[i] == '(')
			push(infix[i]);
		else if (infix[i] == ')') {
			while ((x = pop()) != '(')
				postfix[j++] = x;
		}
		else {
			while (precedence(stack[top]) >= precedence(infix[i])) 
				postfix[j++] = pop();
			push(infix[i]);
		}
	}
	
	while (top != -1)
		postfix[j++] = pop();
	
	postfix[j] = '\0';
	
	printf("Postfix Expression: %s\n", postfix);
	
	return 0;
}
