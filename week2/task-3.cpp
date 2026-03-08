#include <stdio.h>

struct Complex {
    int real;
    int imag;
};

struct Complex addComplex(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

main() {
    struct Complex c1, c2, sum;

    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%d %d", &c2.real, &c2.imag);

    sum = addComplex(c1, c2);
    printf("Sum = (%d + %di)\n", sum.real, sum.imag);

    return 0;
}

