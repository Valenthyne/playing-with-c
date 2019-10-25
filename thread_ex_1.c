/*
    This program will read in a string of input decimals, terminated by -1, and
    print out the maximum, minimum, and average values through the generation
    of three separate threads for each function.

    This will only work on POSIX-compatible systems as it utilizes the pthread library.
*/

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

int avg = 0;
int max = -2147483648;
int min = 2147483647;

// Structure of relevant data to be passed as arguments
struct data {

    int * numbers;
    int index;

};

// Determine the average value
void average(void * args) {
    struct data * vals = (struct data *)args;

    int * num = vals->numbers;
    int index = vals->index;

    int total = 0;
    for (int i = 0; i < index; i++) {
        total += num[i];
    }
    avg = total / index;

    // Exit thread after task was completed
    pthread_exit(0);
}

// Determine the minimum value
void minimum(void * args) {
    struct data * vals = (struct data *)args;

    int * num = vals->numbers;
    int index = vals->index;

    for (int i = 0; i < index; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }

    // Exit thread after task was completed
    pthread_exit(0);
}

// Determine the maximum value
void maximum(void * args) {
    struct data * vals = (struct data *)args;

    int * num = vals->numbers;
    int index = vals->index;

    for (int i = 0; i < index; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }

    // Exit thread after task was completed
    pthread_exit(0);
}

// Main function body
int main() {

    // Accepts a maximum of 100 integers
    int num[100] = {};
    int index = 0;
    int input = 0;

    // Read input from the user
    printf("%s", "Enter some numbers (terminate on -1): ");

    scanf("%d", &input);
    while (input != -1) {
        num[index++] = input;
        scanf("%d", &input);
    }

    // Create a structure object of data based upon the input
    struct data facts = {.numbers = num, .index = index};
    struct data * args = &facts;

    // Create a function of void pointers to reference the functions at a later time
    void (*funcArr[3]) = {(void *) average, (void *) minimum, (void *) maximum};

    // Begin the process of creating and executing threads to do work
    pthread_t tid[3];

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&tid[i], NULL, funcArr[i], (void *)args) != 0) {
            // Error in the process of creating the threads
            printf("\n%s\n", "Something very not-good just happened...");
        } else {
            // Successful creation of threads!
            pthread_join(tid[i], NULL);
        }
    }

    // Parent thread printing the values
    printf("\n%s: %d", "The average value is: ", avg);
    printf("\n%s: %d", "The minimum value is: ", min);
    printf("\n%s: %d", "The maximum value is: ", max);
    puts("\n");

    return 0;
}
