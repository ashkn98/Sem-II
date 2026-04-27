#include<stdio.h>
#include<stdlib.h>
#define MAX 25

int front=-1, rear=-1;

//---QUEUE USING ARRAY---
int queue[MAX];

void enqueueArr() {
	int value;
	if (rear == MAX-1)
		printf("Queue Overflow.\n");
	else {
		printf("Enter value: ");
		scanf("%d", &value);
		if (front == -1)
			front = 0;
		queue[++rear] = value;
		printf("Inserted: %d\n", value);
	}
}

void dequeueArr() {
	if (front == -1 || front>rear) 
		printf("Queue Underflow.\n");
	else 
		printf("Deleted element: %d\n", queue[front++]);
}

void displayArr() {
	int i;
	if (front == -1 || front>rear)
		printf("Queue is empty.\n");
	else {
		for (i = front; i<=rear; i++)
			printf("%d ", queue[i]);
	}
	printf("\n");
}

//---QUEUE USING LINKED LIST---
struct node {
	int data;
	struct node *next;
};

struct node *frontLL = NULL, *rearLL = NULL;

void enqueueLL() {
	struct node *newnode;
	int value;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter value: ");
	scanf("%d", &value);
	newnode->data = value;
	newnode->next = NULL;
	if (rearLL == NULL)
		frontLL = rearLL = newnode;
	else {
		rearLL->next = newnode;
		rearLL = newnode;
	}
	printf("Inserted: %d\n", value);
}

void dequeueLL() {
	if (frontLL == NULL)
		printf("Queue Underflow.\n");
	else {
		struct node *temp = frontLL;
		printf("Deleted element: %d\n", frontLL->data);
		frontLL = frontLL->next;
		free(temp);
		if (frontLL == NULL)
			rearLL = NULL;
	}
}

void displayLL() {
	struct node *temp = frontLL;
	if (temp == NULL) 
		printf("Queue is empty.\n");
	else {
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

main() {
	char choice;
	int subChoice;
		
	while(1) {
		printf("IMPLEMENT QUEUE USING: \n");
		printf("\na. ARRAYS \nb. LINKED LIST(POINTERS)");
		printf("\nEnter choice: ");
		scanf(" %c", &choice);
		switch(choice) {
			case 'a':
				while(1) {
					printf("\n---ARRAY QUEUE MENU---");
					printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");
					printf("\nEnter choice: ");
					scanf("%d", &subChoice);
					switch(subChoice) {
						case 1:
							enqueueArr();
							break;
						case 2:
							dequeueArr();
							break;
						case 3:
							displayArr();
							break;
						case 4:
							exit(0);
						default:
							printf("Invalid Choice.");
							break;
					}
				}
				break;
			case 'b':
				while(1) {
					printf("\n---LINKED LIST QUEUE MENU---");
					printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");
					printf("\nEnter choice: ");
					scanf("%d", &subChoice);
					switch(subChoice) {
						case 1:
							enqueueLL();
							break;
						case 2:
							dequeueLL();
							break;
						case 3:
							displayLL();
							break;
						case 4:
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
