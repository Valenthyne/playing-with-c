#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    int a[SIZE];

    // Generally use size_t as variable type
    for (size_t i = 0; i < SIZE; i++) {
        a[i] = i;
    }

    for (size_t i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

    puts("");

    return 0;
}
