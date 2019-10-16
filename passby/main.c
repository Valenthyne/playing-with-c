#include <stdio.h>
#include <stdlib.h>

void sum(int n, int p);

int main()
{
    int a = 3;
    int b = 5;

    // a = 3, b = 5
    printf("%d, %d\n", a, b);

    // Passing-by-value, a & b wont change
    foo(a, b);

    // a = 3, b = 5
    printf("%d, %d\n", a, b);

    // Passing address will change values
    bar(&a, &b);

    // a = 5, b = 0
    printf("%d, %d\n", a, b);

}

void foo(int x, int y) {

    x = y;
    y = y * y + y;

}

void bar(int * x, int * y) {

    *x = *y;
    *y = 0;

}
