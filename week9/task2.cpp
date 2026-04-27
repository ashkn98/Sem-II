#include<stdio.h>
#include<stdlib.h>

//---LINEAR SEARCH USING NON RECURSIVE---
int lSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

//---LINEAR SEARCH USING RECURSIVE---
int lSearchRec(int arr[], int n, int key, int index) {
    if(index >= n)
        return -1;
    if(arr[index] == key)
        return index;
    return lSearchRec(arr, n, key, index + 1);
}

//---BINARY SEARCH USING NON RECURSIVE---
int bSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//---BINARY SEARCH USING RECURSIVE---
int bSearchRec(int arr[], int low, int high, int key) {
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return bSearchRec(arr, mid + 1, high, key);
    else
        return bSearchRec(arr, low, mid - 1, key);
}

main() {
	int arr[100], n, i, key, result, choice, subchoice;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for (i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter key to search: ");
	scanf("%d", &key);
	printf("\n---MENU---\n");
	printf("1. Search using recursive functions. \n2. Search using non-recursive functions.\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	do {
		switch(choice) {
			case 1:
				printf("\n---RECURSIVE MENU---\n");
				printf("1. Linear Search \n2. Binary Search \n3. Exit\n");
				printf("Enter your choice: ");
				scanf("%d", &subchoice);
				switch(subchoice) {
					case 1:
						result = lSearchRec(arr, n, key, 0);
						break;
					case 2:
						result = bSearchRec(arr, 0, n-1, key);
						break;
					case 3:
						exit(0);
					default:
						printf("Invalid Choice.");
						break;
				}
				break;
			case 2:
				printf("\n---NON-RECURSIVE MENU---\n");
				printf("1. Linear Search \n2. Binary Search \n3. Exit\n");
				printf("Enter your choice: ");
				scanf("%d", &subchoice);
				switch(subchoice) {
					case 1:
						result = lSearch(arr, n, key);
						break;
					case 2:
						result = bSearch(arr, n, key);
						break;
					case 3:
						exit(0);
					default:
						printf("Invalid Choice.");
						break;
				}
				break;
			default:
				printf("Invalid Choice.");
				break;
		}
		if (choice >=1 && choice <=2) {
			if (result != 1)
				printf("Element was found at position %d.\n", result+1);
			else 
				printf("Element was not found.\n");
		}
	} while (choice != 3);
	return 0;
}
