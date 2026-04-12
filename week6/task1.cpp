#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

void create(int n) {
    struct node *temp, *newnode;
    int i, value;
    printf("Enter data: ");
    for(i = 0; i < n; i++) {
    	scanf("%d", &value);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        if(last == NULL) {
            last = newnode;
            last->next = last;
        }
        else {
            newnode->next = last->next;
            last->next = newnode;
            last = newnode;
        }
    }
}

void insert() {
    struct node *newnode, *temp;
    int choice, pos, i, value;
    printf("\n{INSERTION MENU}");
    printf("\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("Enter data: ");
    scanf("%d", &value);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if (last == NULL) {
        last = newnode;
        last->next = last;
        return;
    }
    switch(choice) {
        case 1:
            newnode->next = last->next;
            last->next = newnode;
            break;
        case 2:
            printf("Enter position: ");
			scanf("%d", &pos);
            temp = last->next;
            if (pos == 1) {
                newnode->next = last->next;
                last->next = newnode;
                return;
            }
            for (i = 1; i < pos - 1; i++) {
                temp = temp->next;
                if (temp == last->next) {
                    printf("Invalid position\n");
                    free(newnode);
                    return;
                }
            }
            newnode->next = temp->next;
            temp->next = newnode;
            if (temp == last)
                last = newnode;
            break;
        case 3:
            newnode->next = last->next;
            last->next = newnode;
            last = newnode;
            break;
        default:
            printf("Invalid choice\n");
            free(newnode);
    }
}

void deletep() {
    struct node *temp, *prev;
    int choice, pos, i;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("\n{DELETION MENU}");
    printf("\n1. Delete from beginning\n2. Delete from middle\n3. Delete from end\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            temp = last->next;
            if (last->next == last) {
                free(last);
                last = NULL;
            } else {
                last->next = temp->next;
                free(temp);
            }
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            temp = last->next;
            if (pos == 1) {
                if (last->next == last) {
                    free(last);
                    last = NULL;
                } else {
                    last->next = temp->next;
                    free(temp);
                }
                return;
            }
            prev = temp;
            temp = temp->next;
            for (i = 2; i < pos; i++) {
                prev = temp;
                temp = temp->next;
                if (temp == last->next) {
                    printf("Invalid position\n");
                    return;
                }
            }
            prev->next = temp->next;
            if (temp == last)
                last = prev;
            free(temp);
            break;
        case 3:
            temp = last->next;
            if (last->next == last) {
                free(last);
                last = NULL;
                return;
            }
            while (temp->next != last) {
                temp = temp->next;
            }
            temp->next = last->next;
            free(last);
            last = temp;
            break;
        default:
            printf("Invalid choice\n");
    }
}

void traverse() {
    struct node *temp;
    if(last == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != last->next);
    printf("\n");
}

main() {
    int n, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    create(n);

    while(1) {
    	printf("\n<-----OPERATION MENU----->");
        printf("\n1. Insert\n2. Delete\n3. Traversal\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert();
                break;

            case 2:
                deletep();
                break;

            case 3:
                traverse();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
