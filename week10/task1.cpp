#include <stdio.h>
#include <string.h>

//---INSERTION SORT---
void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//---BUBBLE SORT---
void bubbleSort(char arr[], int n) {
    int i, j;
    char temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//---SELECTION SORT---
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n - 1; i++) {
        min_idx = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    char temp;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

//---QUICK SORT---
void quickSort(char arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printIntArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printCharArray(char arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

int main() {
    int choice, subchoice, n, i;
    do {
        printf("\n---DATA TYPE MENU---\n");
        printf("1. Integers\n2. Characters\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
	        case 1: {
	            int arr[100];
	            printf("Enter number of elements: ");
	            scanf("%d", &n);
	            printf("Enter integers:\n");
	            for(i = 0; i < n; i++)
	                scanf("%d", &arr[i]);
	            printf("\n---SORT MENU---\n");
	            printf("1. Insertion sort \n2. Selection sort \n3. Exit\n");
	            printf("Enter choice: ");
	            scanf("%d", &subchoice);
	            switch(subchoice) {
	            	case 1:
	            		insertionSort(arr, n);
	            		printf("Sorted array:\n");
	            		printIntArray(arr, n);
	            		break;
	            	case 2:
	            		selectionSort(arr, n);
			            printf("Sorted array:\n");
			            printIntArray(arr, n);
			            break;
			        case 3:
			        	printf("Exiting...");
			        	break;
			        default:
			        	printf("Invalid choice.");
			        	break;
				}
				break;
			}
	        case 2: {
	            char arr2[100];
	            printf("Enter characters (no space): ");
	            scanf("%s", arr2);
	            n = strlen(arr2);
	            printf("\n---SORT MENU---\n");
	            printf("1. Bubble sort \n2. Quick sort \n3. Exit\n");
	            printf("Enter choice: ");
	            scanf("%d", &subchoice);
	            switch(subchoice) {
	            	case 1:
	            		bubbleSort(arr2, n);
			            printf("Sorted characters:\n");
			            printCharArray(arr2, n);
			            break;
			        case 2:
				        quickSort(arr2, 0, n - 1);
			            printf("Sorted characters:\n");
			            printCharArray(arr2, n);
			            break; 
					case 3:
						printf("Exiting...");
						break;
					default:
						printf("Invalid choice!\n");
						break;	
				}
				break;
			}
			case 3:
				printf("Exiting...");
				break;
	        default:
	            printf("Invalid choice!\n");
	            break;
        }
    } while(choice != 3);
    return 0;
}
