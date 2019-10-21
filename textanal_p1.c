/*
	Solution for question 8.31 part a)
	COMP 3150 -- Introduction to C/C++ Programming
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024
#define LETTERS 26;

int count[LETTERS];

int main()
{
	// ASCII letter references
    // 65 - 90 is A to Z
    // 97 - 122 is a to z

	char str[SIZE];

	printf("%s", "Please enter a string: ");
	fgets(&str, SIZE, stdin);

	// Begin cycling through the input string
	for (int i = 0; str[i] != '\0'; i++) {
		// Check if current character is an alphabetical letter
		if (isalpha(str[i])) {
			// Find the ASCII value of the letter and subtract by 1 for indexing
			int val = (int)str[i] - 1;
			
			// Debug line
			// printf("%c is %d\n", str[i], (val % 32));
			
			// Increment count of the specific letter in count array by one
			// Using modulo two to relate indices of array to ASCII character values
			count[val % 32]++;
		}
	}

	// Print out table of all letters
	puts("\nChar | Occurrences\n-------------");
	for (int i = 0; i < LETTERS; i++) {
		printf("%4c | %4d\n", (char)(i + 65), count[i]);
	}

    return 0;
}
