#include <stdio.h>
#include <stdlib.h>

int length[29];

int main()
{

    while (1 == 1) {

        char str[1024];

        printf("%s", "Please enter a string: ");
        fgets(&str, 1024, stdin);

        int word = 0;

        for (int i = 0; str[i] != '\0'; i++) {

            if (str[i] != ' ') {
                word++;
            } else {
                if (word >= 29) {
                    length[28]++;
                } else {
                    length[word - 1]++;
                    word = 0;
                }

            }

        }

        length[word - 2]++;

        puts("\nLength | Occurrences\n-------------");
        for (int i = 0; i < 28; i++) {
            printf("%6d | %6d\n", i + 1, length[i]);
        }

        printf("%6s | %6d\n", "> 28", length[28]);

        printf("%s\n", str);

    }


    return 0;
}
