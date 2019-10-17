#include <stdio.h>
#include <stdlib.h>

int count[26];

int main()
{
    // 65 - 90 is A to Z
    // 97 - 122 is a to z

    while (1 == 1) {

        char str[100];

        printf("%s", "Please enter a string: ");
        fgets(&str, 100, stdin);

        for (int i = 0; str[i] != '\0'; i++) {
            int val = (int)str[i] - 1;
            // printf("%c is %d", str[i], (val % 32));
            count[val % 32]++;
        }

        puts("\nChar | Occurrences\n-------------");
        for (int i = 0; i < 26; i++) {
            printf("%4c | %4d\n", (char)(i + 65), count[i]);
        }

    }
    
    return 0;
}
