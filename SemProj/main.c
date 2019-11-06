#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

// Defining constants
#define MAX_STRING 1024

// Function prototypes for the various menus
void stringMenu();
void arrayMenu();
void structMenu();
void ptrMenu();
void dsMenu();

// Function prototypes for the string menu functions
void setString();

// Function prototypes for the array menu functions

// Function prototypes for the structure menu functions

// Function prototypes for the pointer menu functions

// Function prototypes for the data structure menu functions

int main()
{
    char input;
    int cont = 1;

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

    printf("\n%s\n", "Welcome to the String Menu!");
    printf("\n\nPlease enter a string: ");
    setString(input);


    while (cond == 0) {

        printf("%s: %s", "Current string", input);
        printf("\n%s\n", "What would you like to do with this string?");

        scanf(" %c", &ch);

        if (ch == '1') {
            setString(&input);
        }

        if (ch == '0') {
            cond = -1;
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

void setString(char * str) {
    scanf(" %[^\n]s", str);
}
