#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1024

char count[SIZE];

char * convert(char * ptr);

int main() {

    // Create input of max byte size
    char str[SIZE];

    // Create two-dimensional array of max words by max length (30 chars)
    char dictionary[SIZE][30];

    printf("%s", "Please enter a string: ");
    fgets(&str, SIZE, stdin);

    // Preparations for string tokenization
    char * word = strtok(str, " ");

    // Variables to be used in the process of analysis
    int i = 0;
    int index = 0;

    while (word != NULL) {
        // Makes it easier to convert all words to lower case
		// Using a custom function instead of strlwr() to allow for GCC compliance
		convert(word);

        // Find length of the word
        int wordLength = strlen(word);

        // Edge case where last part of tokenized word is punctuation
        if (!isalpha(word[wordLength - 1])) {
            word[wordLength - 1] = '\0';
        }

        // Edge case for the last word of input that may end in a symbol
        if (!isalpha(word[wordLength - 2])) {
            word[wordLength - 2] = '\0';
        }

        // Edge case where the first character of the word is a symbol
        if (!isalpha(word[0])) {
            for (int j = 0; j < wordLength; j++) {
                char temp = word[j];
                word[j] = word[j+1];
                word[j + 1] = temp;
            }
            word[wordLength - 1] = '\0';
        }

        // Assume that the word found is its first appearance
        bool firstAppearance = true;

        // Steadily compare word to the others
        for (i = 0; i < index && firstAppearance; i++) {
			// Compare dictionary entries thus far to current word
            if (strcmp(dictionary[i], word) == 0)
                firstAppearance = false;
        }

        // Case 1: Word found for the first time
        if (firstAppearance) {
            // Copy word to the dictionary array
            strcpy(dictionary[index], word);
            // Increment count of the word and the index itself
            count[index++]++;
        } else {
            // Word already in the array, just increment its index
            count[i - 1]++;
        }

        // Continue tokenizing the input string
        word = strtok(NULL, " ");
    }

    // Prepare to print out a table
    printf("\n%30s | %-30s\n", "Word", "Occurrence");
    puts("------------------------------------------------------------");
    for (int i = 0; i < index; i++) {
        printf("%30s | %d\n", dictionary[i], count[i]);
    }

    return 0;
}

char * convert(char * word) {
	
	// Point to first character in the word
	char * p = (char *) word;
	
	// Cycle through all characters
	while (* p != NULL) {
		// Convert the character to lower case
		* p = tolower((char) * p);
		p++;
	}
	
	return word;
	
}
