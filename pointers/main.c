#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Normal variable established
    int a = 5;
    // Pointer to a variable (address) established
    int * b = &a;

    // a = 5; b = 5
    printf("%d\n", a);
    printf("%d\n", * b);

    // Dereferences address with b and sets value to 30
    * b = 30;

    // a = 30; b = 30
    printf("%d\n", a);
    printf("%d\n", * b);

    return 0;
}
