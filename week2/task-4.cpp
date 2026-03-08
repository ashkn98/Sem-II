#include <stdio.h>

struct Time {
    int h, m, s;
};

int main() {
    struct Time t1, t2, diff;

	printf("<-----Calculate the difference between two time periods.----->\n");
    printf("Enter first time (HH MM SS): ");
    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    if (t1.h < 0 || t1.h > 23 || t1.m < 0 || t1.m > 59 || t1.s < 0 || t1.s > 59) {
        printf("Invalid first time!\n");
        return 0;
    }

    printf("Enter second time (HH MM SS): ");
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
    if (t2.h < 0 || t2.h > 23 || t2.m < 0 || t2.m > 59 || t2.s < 0 || t2.s > 59) {
        printf("Invalid second time!\n");
        return 0;
    }
    
    if (t1.s < t2.s) {
        t1.s += 60;
        t1.m--;
    }
    diff.s = t1.s - t2.s;
    if (t1.m < t2.m) {
        t1.m += 60;
        t1.h--;
    }
    diff.m = t1.m - t2.m;
    diff.h = t1.h - t2.h;
    printf("Time Difference = %02d:%02d:%02d\n", diff.h, diff.m, diff.s);

    return 0;
}

