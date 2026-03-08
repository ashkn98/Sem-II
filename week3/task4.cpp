#include<stdio.h>

main() {
	int n, index, i, *ptr;
	
	printf("Enter number of elements in array: ");
	scanf("%d", &n);
	int ar[n];
	printf("Enter the elements: ");
	for (i=0; i<n; i++) {
		scanf("%d", &ar[i]);
	}
	
	printf("Enter the index to be accessesd: ");
	scanf("%d", &index);
	ptr = ar;
	if (index<0 || index>=n) {
		printf("Invalid index.");
	}
	else {
		printf("Element at index %d is: %d", index, *(ptr+index));
	}
	
	return 0;
}


