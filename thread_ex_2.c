// Directives
#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/types.h>
#include <unistd.h> 

// Constants
#define MAX_STRINGS 3
#define STR_LENGTH 100

// Function prototypes for pthreads
void readerFunc(void);
void converterFunc(void);
void writerFunc(void);

// pthread content declarations
pthread_t readerThread[3];
pthread_t converterThread[3];
pthread_t writerThread[3];
pthread_mutex_t lock;

int readerID = 1;
int converterID = 1;
int writerID = 1;

// Character buffer arrays
char bufA[MAX_STRINGS][STR_LENGTH] = {"0"};
char bufB[MAX_STRINGS][STR_LENGTH] = {"0"};

int main(void) {
	
	printf("\n%s\n\n", "\tThank you for choosing the String Converter!");
	printf("%s\n\n", "\tWe take pleasure in removing those pesky whitespace characters.");
	printf("%s\n\n", "\tProud to announce we are pthread-enabled!");

	// Initializing the mutex lock
	pthread_mutex_init(&lock, NULL);
	
	// Creating threads for each of the readers, converters, and writers
	for (int i = 0; i < 3; i++) {
		pthread_create(&readerThread[i], NULL, &readerFunc, NULL);
		pthread_create(&converterThread[i], NULL, &converterFunc, NULL);
		pthread_create(&writerThread[i], NULL, &writerFunc, NULL);
	}

	// Joining all the reader threads
	for (int i = 0; i < 3; i++) {
		pthread_join(readerThread[i], NULL);
	}
	
	// Joining all the converter threads
	for (int i = 0; i < 3; i++) {
		pthread_join(converterThread[i], NULL);
	}
	
	// Joining all the writer threads
	for (int i = 0; i < 3; i++) {
		pthread_join(writerThread[i], NULL);
	}
	
	// Destroy the lock at the end
	pthread_mutex_destroy(&lock);
	
	printf("\n%s\n\n", "Regretfully, each customer is limited to three strings per execution.");
	printf("%s\n\n", "Thank you for using our service. Have a nice day!");
	
	return 0;
}

// Starting routine for the readerFunc threads
void readerFunc(void) {
	
	// Taking in user input
	pthread_mutex_lock(&lock);
	// Develop a new string variable
	char inStr[STR_LENGTH];
	
	// Request input from the user and store it in inStr
	printf("%s: ", "Enter a string");
	fgets(inStr, STR_LENGTH, stdin);
	printf("\n[%9s %d]: Receiving user input, accessing Buffer A...", "Reader", readerID++);
	
	// Storing user input in buffer A
	// Cycle through buffer A to find an empty spot
	for (int i = 0; i < MAX_STRINGS; i++) {
		if (!strcmp(bufA[i], "0")) {
			strcpy(bufA[i], inStr);
			break;
		}
	}
	
	pthread_mutex_unlock(&lock);
	
}

// Starting routine for the converterFunc threads
void converterFunc(void) {
	
	pthread_mutex_lock(&lock);
	printf("\n[%9s %d]: Converting user input...", "Converter", converterID++);
	// Develop a new string variable
	char newStr[STR_LENGTH];

	// Read string from buffer A
	
	for (int i = 0; i < MAX_STRINGS; i++) {
		if (strcmp(bufA[i], "0")) {
			strcpy(newStr, bufA[i]);
			strcpy(bufA[i], "0");
			break;
		}
	}
	
	// Conversion process for the string
	for (int i = 0; i < strlen(newStr); i++) {
		if (newStr[i] == ' ') {
			newStr[i] = '%';
		}
	}
	
	// Storing the converted string in buffer B
	int found = 0;
	
	while (!found) {
		for (int i = 0; i < MAX_STRINGS; i++) {
			if (!strcmp(bufB[i], "0")) {
				strcpy(bufB[i], newStr);
				found = 1;
				break;
			}
		}
	}
		
	pthread_mutex_unlock(&lock);

}

// Starting routine for the writerFunc threads
void writerFunc(void) {

	pthread_mutex_lock(&lock);
	printf("\n[%9s %d]: Accessing Buffer B and writing to standard output...\n\n", "Writer", writerID++);

	// Read a string from buffer B
	int found = 0;
	
	printf("\nCongratulations! Your converted string: ");
	
	while (!found) {
		for (int i = 0; i < MAX_STRINGS; i++) {
			if (strcmp(bufB[i], "0")) {
				printf("%s\n", bufB[i]);
				strcpy(bufB[i], "0");
				found = 1;
				break;
			}
		}
	}
	
	pthread_mutex_unlock(&lock);
	
}
