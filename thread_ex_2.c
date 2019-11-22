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
void reader(void);
void converter(void);
void writer(void);

// pthread content declarations
pthread_t rdr[3];
pthread_t conv[3];
pthread_t wtr[3];
pthread_mutex_t lock;

// Character buffer arrays
char bufA[MAX_STRINGS][STR_LENGTH] = {"0"};
char bufB[MAX_STRINGS][STR_LENGTH] = {"0"};

int main(void) {

	// Initializing the mutex lock
	pthread_mutex_init(&lock, NULL);
	
	// Creating threads for each of the reader, converter, and writer elements
	for (int i = 0; i < 3; i++) {
		pthread_create(&rdr[i], NULL, &reader, NULL);
		pthread_create(&conv[i], NULL, &converter, NULL);
		pthread_create(&wtr[i], NULL, &writer, NULL);
	}

	// Joining all the reader threads
	for (int i = 0; i < 3; i++) {
		pthread_join(rdr[i], NULL);
	}
	
	// Joining all the converter threads
	for (int i = 0; i < 3; i++) {
		pthread_join(conv[i], NULL);
	}
	
	// Joining all the writer threads
	for (int i = 0; i < 3; i++) {
		pthread_join(wtr[i], NULL);
	}
	
	// Ultimately, destroy the long
	pthread_mutex_destroy(&lock);
	
	return 0;
}

// Starting routine for the reader threads
void reader(void) {
	
	// Taking in user input
	pthread_mutex_lock(&lock);
	
	// Develop a new string variable
	char inStr[STR_LENGTH];
	
	// Request input from the user and store it in inStr
	printf("%s: ", "Input a string: ");
	fgets(inStr, STR_LENGTH, stdin);
	
	pthread_mutex_unlock(&lock);

	// Storing user input in buffer A
	pthread_mutex_lock(&lock);
	
	// Cycle through buffer A to find an empty spot
	for (int i = 0; i < MAX_STRINGS; i++) {
		if (!strcmp(bufA[i], "0")) {
			strcpy(bufA[i], inStr);
			break;
		}
	}
	
	pthread_mutex_unlock(&lock);
	
}

// Starting routine for the converter threads
void converter(void) {
	
	pthread_mutex_lock(&lock);
		
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
	for (int i = 0; i < MAX_STRINGS; i++) {
		if (!strcmp(bufB[i], "0")) {
			strcpy(bufB[i], newStr);
			break;
		}
	}
		
	pthread_mutex_unlock(&lock);

}

// Starting routine for the writer threads
void writer(void) {

	pthread_mutex_lock(&lock);

	// Read a string from buffer B
	for (int i = 0; i < MAX_STRINGS; i++) {
		if (strcmp(bufB[i], "0")) {
			printf("%s", bufB[i]);
			strcpy(bufB[i], "0");
			break;
		}
	}
	
	pthread_mutex_unlock(&lock);
	
}
