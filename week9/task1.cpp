#include <stdio.h>
#define MAX 25

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX-1)
        printf("Queue Overflow!\n");
    if (front == -1) 
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (front == -1 || front>rear)
        printf("Queue Underflow!\n");
    printf("Deleted: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
	else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1 || front>rear)
        printf("Queue is empty!\n");
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);    
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;    
            case 3:
                display();
                break;    
            case 4:
                printf("Exiting...\n");
                return 0; 
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
