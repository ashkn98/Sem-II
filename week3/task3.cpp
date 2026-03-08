#include<stdio.h>

main() {
	int n, i, *ptr;
	
	printf("Enter number of elements in array: ");
	scanf("%d", &n);
	int ar[n];
	printf("Enter the elements: ");
	for (i=0; i<n; i++) {
		scanf("%d", &ar[i]);
	}
	
	ptr = ar;
	printf("\n<---------------------------------->");
	printf("\nArray elements are: \n");
	for (i=0; i<n; i++) {
		printf("%d ", *ptr);
		ptr++;
	}
	
	return 0;
}


