#include <stdio.h>
#define MAX 25

void display(int arr[], int size) {
    int i;
    if(size == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertAtPosition(int arr[], int size, int element, int pos) {
    int i;

    if(size >= MAX) {
        printf("Array is full!\n");
        return size;
    }

    if(pos < 0 || pos > size) {
        printf("Invalid position!\n");
        return size;
    }

    for(i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    printf("Element inserted successfully.\n");
    return size + 1;
}

int deleteAtPosition(int arr[], int size, int pos) {
    int i;

    if(size == 0) {
        printf("Array is empty!\n");
        return size;
    }

    if(pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return size;
    }

    for(i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted successfully.\n");
    return size - 1;
}

int main() {
    int arr[MAX];
    int choice, subchoice, pos, element, i, size;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    if (size > 25) {
    	printf("Max size of array allowed is 25.");
    }
	else{
	    printf("Enter elements of the array: ");
    	for(i = 0; i < size; i++) {
    		scanf("%d", &arr[i]);
    	}
    }

    do {
        printf("\n----- MENU -----\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size-1);
                scanf("%d", &pos);
                size = insertAtPosition(arr, size, element, pos);
                break;

            case 2:
                printf("\n--- DELETE MENU ---\n");
                printf("1. Delete from beginning\n");
                printf("2. Delete from middle\n");
                printf("3. Delete from end\n");
                printf("Enter choice: ");
                scanf("%d", &subchoice);
                switch(subchoice) {
                    case 1:
                        size = deleteAtPosition(arr, size, 0);
                        break;
                    case 2:
                        size = deleteAtPosition(arr, size, size/2);
                        break;
                    case 3:
                        size = deleteAtPosition(arr, size, size-1);
                        break;
                }
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } 
	while(choice != 4);

    return 0;
}

