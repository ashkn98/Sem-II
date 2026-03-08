#include<stdio.h>

struct addDIST {
	int feet, inches;
};

main() {
	struct addDIST d1, d2, sum;
	printf("Enter the first distance (feet inches): ");
	scanf("%d %d", &d1.feet, &d1.inches);
	printf("Enter the second distance (feet inches): ");
	scanf("%d %d", &d2.feet, &d2.inches);
	
	sum.feet = d1.feet + d2.feet;
	sum.inches = d1.inches + d2.inches;
	if (sum.inches >= 12) {
		sum.feet += sum.inches / 12;
		sum.inches = sum.inches % 12;
	}
	
	printf("The sum of the two distances is %d feet %d inches.", sum.feet, sum.inches);
}


