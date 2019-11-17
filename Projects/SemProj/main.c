#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

// Custom header files
#include "tree.h"
#include "queue.h"
#include "linkedlist.h"
#include "stack.h"

// Defining constants
#define MAX_STRING 1024

// Function prototypes for the various menus
void stringMenu();
void arrayMenu();
void structMenu();
void ptrMenu();
void dsMenu();

// Function prototypes for the string menu functions
void setString(char * str);
void revString(char * str);
void swap(char * a, char * b);

// Function prototypes for the array menu functions

// Function prototypes for the structure menu functions

// Function prototypes for the pointer menu functions

// Function prototypes for the data structure menu functions
void linkedExercise();
void queueExercise();
void stackExercise();
void treeExercise();

int main()
{
    char input;
    int cont = 1;

    StkNodePtr stack = NULL;
    LinkNodePtr list = NULL;

    while (cont == 1) {

        // Base print-out for the menu
        printf("%s", "\nWelcome to the Interactive C Reviewer!\n");
        printf("%s", "\n\t[1] String Manipulation");
        printf("%s", "\n\t[2] Arrays");
        printf("%s", "\n\t[3] Structure Management");
        printf("%s", "\n\t[4] Pointers");
        printf("%s", "\n\t[5] Data Structures\n");

        // Receiving input from the user
        printf("%s", "\nPlease select an option: ");
        scanf(" %c", &input);

        // Using switch-case to handle user input
        switch (input) {
            case '1':
                stringMenu();
                break;
            case '2':
                arrayMenu();
                break;
            case '5':
                dsMenu();
                break;
            default:
                cont = 0;
                break;
        }
    }

    printf("\n%s", "Thanks for playing!");
    return 0;
}

void stringMenu() {
    char input[MAX_STRING];
    int cond = 0;
    char ch;

    printf("\n%s", "Welcome to the String Menu!");
    printf("\n\nPlease enter a string: ");
    setString(input);


    while (cond == 0) {

        printf("%s: %s", "Current string", input);
        printf("\n\n%s\n", "What would you like to do with this string?");
        printf("%s", "\n\t[1] Change it!");
        printf("%s", "\n\t[2] Reverse it!");

        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                setString(&input);
                break;
            case '2':
                revString(&input);
                break;
            default:
                cond = -1;
                break;
        }
    }
}

void arrayMenu() {

    srand(time(NULL));
    int arr[10] = {0};
    int cond = 0;
    int v;

    while (cond == 0) {

        for (int i = 0 ; i < 10; i++) {
            arr[i] = rand() % 20;
        }

        printf("\n[");
        for (int i = 0; i < 10; i++) {
            printf(" %d ", arr[i]);
        }
        printf("]\n");

        printf("%s", "\nRandomize again? ");
        scanf(" %d", &v);

        if (v == 0) {
            cond = 1;
        }

    }
}

void dsMenu() {

    printf("\n%s\n", "Welcome to the Data Structure Menu!");
    int cond = 0;
    char ch;

    while (cond == 0) {

        printf("\n%s\n", "Which data structure would you like to use?");
        printf("%s", "\n\t[1] Linked Lists");
        printf("%s", "\n\t[2] Queues");
        printf("%s", "\n\t[3] Stacks");
        printf("%s", "\n\t[4] Trees");

        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                linkedExercise();
                break;
            case '2':
                queueExercise();
                break;
            case '3':
                stackExercise();
                break;
            case '4':
                treeExercise();
                break;
            default:
                cond = -1;
                break;
        }

    }
}

void linkedExercise() {

    LinkNodePtr head = malloc(sizeof(LinkNode));
    puts("Linked List node created!");

}

void queueExercise() {

}

void stackExercise() {

    StkNodePtr head = malloc(sizeof(StkNode));
    puts("Stack node created!");

}

void treeExercise() {

}

void setString(char * str) {
    scanf(" %[^\n]s", str);
}

void revString(char * str) {

    int len = strlen(str);

    char * start = str;
    char * end = str;

    for (int i = 0; i < len - 1; i++) {
        end++;
    }

    for (int i = 0; i < len / 2; i++) {
        swap(start, end);
        start++;
        end--;
    }

}

void swap(char * a, char * b) {
    char temp = *b;
    *b = *a;
    *a = temp;
}
