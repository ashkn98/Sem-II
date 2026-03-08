#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newnode, *temp;
    int i;
    printf("Enter the data: ");
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void insertBeginning(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    head = newnode;
}

void insertMiddle(int data, int pos) {
    struct node *newnode, *temp = head;
    int i;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    for(i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void insertEnd(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
	while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteBeginning() {
    struct node *temp;
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteMiddle(int pos) {
    struct node *temp = head;
    int i;
    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void deleteEnd() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
	free(temp);
}

void traverse() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, subchoice, n, data, pos;

    do {
        printf("------ MENU ------\n");
        printf("1. Creation\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
	        case 1:
	            printf("Enter number of nodes: ");
	            scanf("%d", &n);
	            create(n);
	            break;
	
	        case 2:
	            printf("\n--- INSERTION MENU ---\n");
	            printf("1. Insert at Beginning\n");
	            printf("2. Insert at Middle\n");
	            printf("3. Insert at End\n");
	            printf("Enter choice: ");
	            scanf("%d", &subchoice);
	            switch(subchoice) {
		            case 1:
		                printf("Enter data: ");
		                scanf("%d", &data);
		                insertBeginning(data);
		                break;
		            case 2:
		                printf("Enter data: ");
		                scanf("%d", &data);
		                printf("Enter position: ");
		                scanf("%d", &pos);
		                insertMiddle(data, pos);
		                break;
		            case 3:
		                printf("Enter data: ");
		                scanf("%d", &data);
		                insertEnd(data);
		                break;
		            default:
		                printf("Invalid choice\n");
		        }
	            break;
	
	        case 3:
	            printf("\n--- DELETION MENU ---\n");
	            printf("1. Delete from Beginning\n");
	            printf("2. Delete from Middle\n");
	            printf("3. Delete from End\n");
	            printf("Enter choice: ");
	            scanf("%d", &subchoice);
	            switch(subchoice) {
	            	case 1:
	                	deleteBeginning();
						break;
		            case 2:
		                printf("Enter position: ");
		                scanf("%d", &pos);
		                deleteMiddle(pos);
		                break;
		            case 3:
		                deleteEnd();
		                break;
		            default:
		                printf("Invalid choice\n");
		        }
	        	break;
	
	        case 4:
	            traverse();
	            break;
	
	        case 5:
	            printf("Exiting...\n");
	            break;
	
	        default:
	            printf("Invalid choice\n");
	    }
	    printf("\n");
    }
	while(choice != 5);

    return 0;
}
