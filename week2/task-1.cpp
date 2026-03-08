#include<stdio.h>

struct studentREC {
	char name[30], subject[30];
	int roll, contact;
};
	
main() {
	int num, i;
	printf("Enter the total number of students: ");
	scanf("%d", &num);
	
	struct studentREC st[100];
	if(num>100) {
		printf("Maximun number of students allowed is 100.");
		return 1;
	}
	
	printf("Enter Student Information: \n");
	for(i=0; i<num; i++) {
		printf("S.No. %d\n", i+1);
		printf("Name: ");
		scanf("%s", st[i].name);
		printf("Roll No.: ");
		scanf("%d", &st[i].roll);
		printf("Subject: ");
		scanf("%s", st[i].subject);
		printf("Contact No.: ");
		scanf("%d", &st[i].contact);
	}
	
	printf("\n--<STUDENT RECORDS>--\n");
	for(i=0; i<num; i++) {
		printf("Name: %s, Roll No.: %d, Subject: %s, Contact No.: %d\n", st[i].name, st[i].roll, st[i].subject, st[i].contact);
	}
}


