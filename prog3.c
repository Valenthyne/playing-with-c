// Directives
#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/types.h>
#include <unistd.h> 

// Constants
#define STR_LENGTH 100

// Function prototypes
void reader(void * bufA);
void converter(void * bufA);
void writer(void * bufB);

pthread_t rdr[3];
pthread_t conv[3];
pthread_t wtr[3];

pthread_mutex_t rdr_lock;
pthread_mutex_t conv_lock;
pthread_mutex_t wtr_lock;

char bufA[STR_LENGTH];
char bufB[STR_LENGTH];

int main(void) {
	
	for (int i = 0; i < 3; i++) {
		pthread_create(&rdr[i], NULL, &reader, (void *) bufA);
	}

	// Works up to here

	for (int i = 0; i < 3; i++) {
		pthread_create(&conv[i], NULL, &converter, (void *) bufA);
	}
	
	for (int i = 0; i < 3; i++) {
		pthread_create(&wtr[i], NULL, &writer, (void *) bufB);
	}

	for (int i = 0; i < 3; i++) {
		pthread_join(rdr[i], NULL);
	}
	
	for (int i = 0; i < 3; i++) {
		pthread_join(conv[i], NULL);
	}
	
	for (int i = 0; i < 3; i++) {
		pthread_join(wtr[i], NULL);
	}
	
	return 0;
}

void reader(void * bufA) {

	pthread_mutex_lock(&rdr_lock);

	printf("%s: ", "Input a string: ");
	fgets((char *) bufA, STR_LENGTH, stdin);
	
	pthread_mutex_unlock(&rdr_lock);
	
}

void converter(void * bufA) {
	
	pthread_mutex_lock(&conv_lock);
	
	char newStr[STR_LENGTH];
	strcpy(newStr, bufA);
	
	// Conversion process
	for (int i = 0; i < strlen(newStr); i++) {
		if (newStr[i] == ' ') {
			newStr[i] = '%';
		}
	}
	
	strcpy(bufB, bufA);
		
	pthread_mutex_unlock(&conv_lock);

}

void writer(void * bufB) {
	
	printf("Writer gang");
	
	pthread_mutex_unlock(&wtr_lock);
	
	char newStr[STR_LENGTH];
	strcpy(newStr, (char *) bufB);
	
	printf("%s", newStr);
	
	pthread_mutex_unlock(&wtr_lock);
	
}