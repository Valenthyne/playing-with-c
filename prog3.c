/*
	Need to create:
	-- 3 reader threads
	-- 3 converter threads
	-- 3 writer threads
*/

// Directives
#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/types.h>
#include <unistd.h> 

// Constants
#define BUFFER_SIZE 1024

// Function prototypes
void reader();
void writer(char * ptr);
void convert(char * ptr);

char bufA[BUFFER_SIZE];

int main(void) {
	
	// pthread_create(tid, NULL, (void *) func, (void *) args)
	
	reader();
	convert(bufA);
	writer(bufA);

	
	return 0;
}

void reader() {

	printf("%s: ", "Input a string");
	fgets(bufA, BUFFER_SIZE, stdin);
	
}

void convert(char * ptr) {
	
	for (int i = 0; i < strlen(ptr); i++) {
		if (ptr[i] == ' ') {
			ptr[i] = '%';
		}
	}
	
}

void writer(char * ptr) {
	
	printf("%s", ptr);
	
}