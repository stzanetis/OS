#include <stdio.h>

int add(int* a, int* b, int* c) {
    return *a+ *b + *c;
}

int main() {
    int a = 5;
    int *ap = &a;
    int b = 10;
    int *bp = &b;
    int c = 2;
    int *cp = &c;

    int sum = add(ap, bp, cp);
    printf("Sum: %d\n", sum);

    return 0;
}
