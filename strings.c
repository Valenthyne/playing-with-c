#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocates 20 bytes of memory for a string
    char str[20];

    // Restricts an input to be stored in str at 20 characters
    scanf("%20s", str);

    // Print the string using formatting
    printf("%s", str);

    return 0;
}
