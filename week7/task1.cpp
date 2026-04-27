#include<stdio.h>
#include<stdlib.h>
#define MAX 25

//---STACK USING ARRAY---
int stack[MAX];
int top = -1;

void pushArr(int value) {
	if (top == MAX)
		printf("Stack Overflow.\n");
	else{
		top++;
		stack[top] = value;
		printf("%d pushed into stack.\n", value);
	}
}

void popArr() {
	if (top == -1) 
		printf("Stack Underflow.\n");
	else {
		printf("%d popped from stack.\n", stack[top]);
		top--;
	}
}

void peekArr() {
	if (top == -1)
		printf("Stack is empty.\n");
	else{
		printf("The top element is %d.\n", stack[top]);
	}
}

void displayArr() {
	int i;
	if (top == -1) 
		printf("Stack is empty.\n");
	else {
		printf("Stack elements: \n");
		for (i=top; i>=0; i--) {
			printf("%d\n", stack[i]);
		}
	}
}

//---STACK USING LINKED LIST---
struct node {
	int data;
	struct node* next;
};

struct node* topLL = NULL;

void pushLL(int value) {
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL) 
		printf("Stack Overflow.\n");
	else {
		newnode->data = value;
		newnode->next = topLL;
		topLL = newnode;
		printf("%d pushed into stack.\n", value);
	}
}

void popLL() {
	struct node* temp;
	if(topLL == NULL)
		printf("Stack Underflow,\n");
	else {
		temp = topLL;
		printf("%d popped from stack.\n", temp->data);
		topLL = topLL->next;
		free(temp);
	}
}

void peekLL() {
	if (topLL == NULL) 
		printf("Stack is empty.\n");
	else {
		printf("Top element is %d.\n", topLL->data);
	}
}

void displayLL() {
	struct node* temp;
	if (topLL == NULL)
		printf("Stack is empty.\n");
	else {
		temp = topLL;
		printf("Stack elements are:\n");
		while (temp != NULL) {
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}

main() {
	char choice;
	int value, subChoice;
	
	while(1) {
		printf("IMPLEMENT STACK USING:\n");
		printf("\na. ARRAY\nb. LINKED LIST");
		printf("\nEnter choice: ");
		scanf(" %c", &choice);
		switch(choice) {
			case 'a':
				while(1) {
					printf("\n---ARRAY STACK MENU---");
					printf("\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit");
					printf("\nEnter choice: ");
					scanf("%d", &subChoice);
					switch(subChoice) {
						case 1:
							printf("Enter value: ");
                			scanf("%d", &value);
							pushArr(value);
							break;
						case 2:
							popArr();
							break;
						case 3:
							peekArr();
							break;
						case 4:
							displayArr();
							break;
						case 5:
							exit(0);
						default:
							printf("Invalid Choice.");
							break;
					}
				}
				break;
			case 'b':
				while(1) {
					printf("\n---LINKED LIST STACK MENU---");
					printf("\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit");
					printf("\nEnter choice: ");
					scanf("%d", &subChoice);
					switch(subChoice) {
						case 1:
							printf("Enter value: ");
                			scanf("%d", &value);
							pushLL(value);
							break;
						case 2:
							popLL();
							break;
						case 3:
							peekLL();
							break;
						case 4:
							displayLL();
							break;
						case 5:
							exit(0);
						default:
							printf("Invalid Choice.");
							break;
					}
				}
				break;
		}
	}
}
