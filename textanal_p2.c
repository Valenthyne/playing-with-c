#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024
#define MAX_LENGTH 29

int length[MAX_LENGTH];

int main()
{

	char str[SIZE];

	printf("%s", "Please enter a string: ");
	fgets(&str, SIZE, stdin);

	int word = 0;

	// Begin cycling through input string
	for (int i = 0; str[i] != '\0'; i++) {

		// Determine if current character is a space
		if (str[i] != ' ') {
			word++;
		} else {
			// Edge case where word might be longer than 29 characters
			if (word >= MAX_LENGTH) {
				length[MAX_LENGTH - 1]++;
			} else {
				// Otherwise, increment length array with the proper length value
				length[word - 1]++;
				// Reset length
				word = 0;
			}

		}

	}

	length[word - 2]++;

	puts("\nLength | Occurrences\n-------------");
	for (int i = 0; i < MAX_LENGTH - 1; i++) {
		printf("%6d | %6d\n", i + 1, length[i]);
	}

	printf("%6s | %6d\n", "> 28", length[MAX_LENGTH - 1]);

	printf("%s\n", str);

    return 0;
}
