#include<stdio.h>

main() {
	int n1, n2, i, j, k;
	
	printf("Enter number of elements in first sorted array: ");
	scanf("%d", &n1);
	int a[n1];
	printf("Enter elements in sorted order: ");
	for (i=0; i<n1; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("Enter number of elements in second sorted array: ");
	scanf("%d", &n2);
	int b[n2];
	printf("Enter elements in sorted order: ");
	for (i=0; i<n2; i++) {
		scanf("%d", &b[i]);
	}
	
	int merged[n1+n2];
	i = j = k = 0;
	while (i<n1 && j<n2) {
		if (a[i] <= b[j]) {
			merged[k++] = a[i++];
		}
		else {
			merged[k++] = b[j++];
		}
	}
	
	while (i<n1) {
		merged[k++] = a[i++];
	}
	while (j<n2) {
		merged[k++] = b[j++];
	}
	
	printf("The merged sorted array is: \n");
	for (i=0; i<n1+n2; i++) {
		printf("%d ", merged[i]);
	}
	return 0;
}


