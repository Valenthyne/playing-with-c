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

typedef struct identificationCard {

    char fname[15];
    char lname[15];
    int age;
    char gender[15];

} ID, *ID_ptr;

// Function prototypes for the various menus
void stringMenu();
void arrayMenu();
void structMenu();
void ptrMenu();
void dsMenu();
void arithMenu();

// Function prototypes for the string menu functions
void setString(char * str);
void revString(char * str);
void swap(char * a, char * b);

// Function prototypes for the structure menu functions
void printID(ID_ptr s);

// Function prototypes for the data structure menu functions
void linkedExercise();
void queueExercise();
void stackExercise();
void treeExercise();

// Function prototypes for the arithmetic menu functions
void calculator();
void randomizer();

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
        printf("%s", "\n\t[4] Data Structures");
        printf("%s", "\n\t[5] Arithmetic Operations\n");

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
            case '3':
                structMenu();
                break;
            case '4':
                dsMenu();
                break;
            case '5':
                arithMenu();
                break;
            default:
                cont = 0;
                break;
        }
    }

    printf("\n%s", "Thanks for playing!\n");
    return 0;
}

void stringMenu() {
    char input[MAX_STRING];
    int cond = 1;
    char ch;

    printf("\n%s", "Welcome to the String Menu!");
    printf("\n\nPlease enter a string: ");
    setString(input);


    while (cond == 1) {

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
    int cond = 1;
    int v;

    while (cond == 1) {

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

void structMenu() {

    printf("\n%s\n", "Welcome to the Struct Menu!");
    printf("\n%s\n", "Let's build an ID card...");

    ID user;
    ID_ptr user_ptr = &user;

    printf("\n%s", "Please enter a name: ");
    scanf("%s", user_ptr->fname);

    printf("\n%s", "Please enter a last name: ");
    scanf("%s", user_ptr->lname);

    printf("\n%s", "Please enter an age: ");
    scanf("%d", &user_ptr->age);

    printf("\n%s", "Please enter a gender: ");
    scanf("%s", user_ptr->gender);

    printID(user_ptr);

    puts("\nReturning to menu...");

}

void printID(ID_ptr s) {

    printf("\n---------------------------\n");

    printf("\n[%25s]\n", "User Identification Chart");

    printf("\n%15s: %-15s", "First Name", s->fname);
    printf("\n%15s: %-15s", "Last Name", s->lname);
    printf("\n%15s: %-15d", "Age", s->age);
    printf("\n%15s: %-15s\n", "Gender", s->gender);

    puts("\n---------------------------");

}

void dsMenu() {

    printf("\n%s\n", "Welcome to the Data Structure Menu!");
    int cond = 1;
    char ch;

    while (cond == 1) {

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

void arithMenu() {

    printf("\n%s\n", "Welcome to the Arithmetic Menu!");
    int cond = 1;
    char ch;

    while (cond == 1) {

        printf("\n%s\n", "What would you like to do?");
        printf("%s", "\n\t[1] Access the basic calculator");
        printf("%s", "\n\t[2] Play with random numbers");

        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                calculator();
                break;
            case '2':
                randomizer();
                break;
            default:
                cond = -1;
                break;
        }

    }

}

void calculator() {

    srand(time(NULL));

    printf("\n%s\n", "Let's crunch some numbers!");
    int cond = 1;
    char ch;
    int x;
    int y;

    while (cond == 1) {

        printf("\nPlease pick two numbers (-1 to exit): ");
        scanf("%d", &x);
        scanf("%d", &y);

        if (x == -1 || y == -1) {
            break;
        }

        printf("\nWhat do you want to do with %d and %d?\n", x, y);
        printf("%s", "\n\t[1] Addition (+)");
        printf("%s", "\n\t[2] Subtraction (-)");
        printf("%s", "\n\t[3] Multiplication (x)");
        printf("%s", "\n\t[4] Division (\\)");
        printf("%s", "\n\t[5] Equality (=)");

        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                printf("\nResult: %d", x + y);
                break;
            case '2':
                printf("\nResult: %d", x - y);
                break;
            case '3':
                printf("\nResult: %d", x * y);
                break;
            case '4':
                printf("\nResult: %d", x / y);
                break;
            case '5':
                if (x == y) {
                    printf("\n%d and %d are equal!", x, y);
                } else {
                    printf("\n%d and %d are not equal!", x, y);
                }
                break;
            default:
                cond = -1;
                break;
        }

        puts("");

    }


}

void randomizer() {

     srand(time(NULL));

     int n;

     printf("%s ", "\nHow many numbers would you like to randomize?");
     scanf("%d", &n);

     int nums[n];
     int bound;

     printf("\nTime to randomize %d numbers...\n", n);
     printf("\n%s", "What would you like your bound to be? ");
     scanf("%d", &bound);

     printf("\n\n%s","Generating numbers...\n\n");

     for (int i = 0; i < n; i++) {
        nums[i] = rand() % bound;
     }

     printf("[ ");

     for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
     }

     printf(" ]\n");

}

void linkedExercise() {

    LinkNodePtr head = malloc(sizeof(LinkedNode));
    puts("Linked List node created!");

}

void queueExercise() {

    QueueNodePtr head = NULL;
    QueueNodePtr tail = NULL;

    printf("\n%s\n", "Let's build a queue!");
    printf("\n%s\n", "Insert [-1] to Dequeue, [-2] to exit!");

    int cond = 1;

    while (cond) {
        int val;
        printf("\n%s", "Insert value: ");
        scanf("%d", &val);
        if (val == -1) {
            dequeue(&head, &tail);
        } else if (val == -2) {
            break;
        } else {
            enqueue(&head, &tail, val);
        }
        printQueue(head);
    }

}

void stackExercise() {

    StkNodePtr head = NULL;

    printf("\n%s\n", "Let's build a stack!");
    printf("\n%s\n", "Insert [-1] to Pop, [-2] to exit!");

    int cond = 1;

    while (cond) {
        int val;
        printf("\n%s", "Insert value: ");
        scanf("%d", &val);
        if (val == -1) {
            pop(&head);
        } else if (val == -2) {
            break;
        } else {
            push(&head, val);
        }
        printStack(head);
    }

}

void treeExercise() {

    TreeNodePtr root = NULL;

    printf("\n%s\n", "Let's build a binary tree!");

    int cond = 1;

    while (cond) {
        int val;
        printf("\n%s", "Please enter a value for the tree (-1 to end): ");
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        insertTNode(&root, val);
    }

    printf("\nLet's see your tree!");

    printf("\n[ ");
    inOrder(root);
    printf("]\n");

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
