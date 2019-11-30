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

// Struct for use in a later example
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
void removePunct(char * str);
void swap(char * a, char * b);

// Function prototypes for array menu functions
void printArray(int arr[], int len);
void initArray(int arr[], int len);
int useArray(int arr[], int len);
void bubbleSort(int arr[], int len);
void zeroArray(int arr[], int len, int k);
void revArray(int arr[], int len);
void swapInt(int * a, int * b);

// Function prototypes for the structure menu functions
void printID(ID_ptr s);

// Function prototypes for the data structure menu functions
void linkedExercise();
void queueExercise();
void stackExercise();
void treeExercise();

// Function prototypes for the arithmetic menu functions
void calculator();
void mathlib();
void randomizer();

int main()
{
    char input;
    int cont = 1;

    while (cont == 1) {

        // Base print-out for the menu
        printf("%s", "\nWelcome to the Interactive C Reviewer!\n");
        printf("%s", "\n\t[1] String Manipulation");
        printf("%s", "\n\t[2] Arrays");
        printf("%s", "\n\t[3] Struct Exercise");
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

// Start String Content

void stringMenu() {
    char input[MAX_STRING];
    int cond = 1;
    char ch;

    printf("\n%s", "Welcome to the String Menu!");
    printf("\n\nPlease enter a string: ");
    setString(input);


    while (cond == 1) {

        printf("%s: %s", "Current string", input);
        printf("\n\n%s\n", "[String Menu] What would you like to do with this string?");
        printf("%s", "\n\t[1] Change it!");
        printf("%s", "\n\t[2] Reverse it!");
        printf("%s", "\n\t[3] Remove punctuation!");

        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                setString(&input);
                break;
            case '2':
                revString(&input);
                break;
            case '3':
                removePunct(&input);
                break;
            default:
                cond = -1;
                break;
        }
    }
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

void removePunct(char * str) {

    int len = strlen(str);
    char newStr[len];
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i]) || isdigit(str[i])) {
            newStr[index++] = str[i];
        }
    }
    newStr[index] = '\0';

    strcpy(str, newStr);

}

void swap(char * a, char * b) {
    char temp = *b;
    *b = *a;
    *a = temp;
}

// End String Content

// Start Array Content

void arrayMenu() {

    int cond = 1;

    while (cond == 1) {

        char in;
        int vals;

        printf("\n%s\n", "Let's build an array!");

        printf("\n%s", "How many values do you want it to be? ");
        scanf("%d", &vals);
        int arr[vals];
        initArray(arr, vals);

        printf("\n%s", "Do you want it randomized? (Y\\N) ");
        scanf(" %c", &in);

        if (in == 'Y' || in == 'y') {
            srand(time(NULL));
            int b;

            printf("\n%s", "What would you like your bound to be? ");
            scanf("%d", &b);

            for (int i = 0 ; i < vals; i++) {
                arr[i] = rand() % b;
            }
        } else {
            for (int i = 0; i < vals; i++) {
                printf("\n%s", "Enter a value: ");
                scanf("%d", &arr[i]);
            }
        }

        int res = useArray(arr, vals);

        if (res == 0) {
            cond = 0;
        }
    }
}

void printArray(int arr[], int len) {

    printf("\n[");
    for (int i = 0; i < len; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

}

void initArray(int arr[], int len) {

    for (int i = 0 ; i < len; i++) {
        arr[i] = 0;
    }

}

int useArray(int arr[], int len) {

    char ch;
    printArray(arr, len);

    while (1 == 1) {

        printf("\n%s\n", "[Array Menu] What do you want to do with the array?");
        printf("%s", "\n\t[1] Sort Array");
        printf("%s", "\n\t[2] Zero a Value");
        printf("%s", "\n\t[3] Reverse Values");
        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                {
                    bubbleSort(arr, len);
                    printf("\n%s", "Sorted Array");
                    printArray(arr, len);
                }
                break;
            case '2':
                {
                    int k;
                    printf("\n%s\n", "Which value do you want to remove? ");
                    scanf("%d", &k);
                    zeroArray(arr, len, k);
                    printf("\n%s", "Resulting Array");
                    printArray(arr, len);
                    break;
                }
            case '3':
                {
                    revArray(arr, len);
                    printf("\n%s", "Reversed Array");
                    printArray(arr, len);
                    break;
                }
            default:
                return 0;
        }

    }

}

void bubbleSort(int arr[], int len) {

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void zeroArray(int arr[], int len, int k) {

    for (int i = 0; i < len; i++) {
        if (arr[i] == k) {
            arr[i] = 0;
        }
    }

}

void revArray(int arr[], int len) {

    int i = 0;
    int j = len - 1;

    for (; i < j; i++, j--) {
        swap(&arr[i], &arr[j]);
    }

}

void swapInt(int * x, int * y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// End Array Content

// Start Struct Content

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

// End Struct Content

// Start Data Structure Content

void dsMenu() {

    int cond = 1;
    char ch;

    while (cond == 1) {

        printf("\n%s\n", "Note: All structures allow integers as input only.");
        printf("\n%s\n", "[DS Menu] Which data structure would you like to use?");
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

    LinkNodePtr head = NULL;

    printf("\n%s\n", "Let's build a linked list!");

    while (1 == 1) {
        int val;
        printf("\n%s", "Insert value (-1 to end): ");
        scanf("%d", &val);
        if (val == -1)
            break;
        insertLNode(&head, val);
        showPointers(head);
    }

    int cond = 1;
    char ch;

    while (cond == 1) {

        printf("\n%s\n", "[List Menu] What do you want to do to the list?");
        printf("%s", "\n\t[1] Add Value");
        printf("%s", "\n\t[2] Remove Value");
        printf("%s", "\n\t[3] Reverse List");
        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                {
                    int k;
                    printf("\n%s", "Enter a value to add: ");
                    scanf("%d", &k);
                    insertLNode(&head, k);
                    showPointers(head);
                    break;
                }
                break;
            case '2':
                {
                    int k;
                    printf("\n%s", "Enter a value to remove: ");
                    scanf("%d", &k);
                    remValue(head, k);
                    break;
                }
            case '3':
                revList(head);
                break;
            default:
                cond = -1;
                break;
        }

    }

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

// End Data Structure Content

// Start Arithmetic Content

void arithMenu() {

    int cond = 1;
    char ch;

    while (cond == 1) {

        printf("\n%s\n", "[Math Menu] What would you like to do?");
        printf("%s", "\n\t[1] Access the basic calculator");
        printf("%s", "\n\t[2] Work with some math functions");
        printf("%s", "\n\t[3] Play with random numbers");
        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                calculator();
                break;
            case '2':
                mathlib();
                break;
            case '3':
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

void mathlib() {

    int cond = 1;
    char ch;

    while (cond == 1) {

        printf("\n%s\n", "[Math Menu] What would you like to do?");
        printf("%s", "\n\t[1] Evaluating a Power");
        printf("%s", "\n\t[2] Modulo Evaluation");
        printf("%s", "\n\t[3] Finding Square Root");
        printf("%s", "\n\t[4] Log-10 Value");
        printf("%s", "\n\t[5] Natural Log Value");
        printf("%s", "\n\nPlease select an option: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                {
                    int x;
                    int y;
                    printf("\n%s", "Enter a number: ");
                    scanf("%d", &x);
                    printf("\n%s", "Enter an exponent: ");
                    scanf("%d", &y);
                    double r = pow(x, y);
                    printf("\n%d raised to %d equals %.0f\n", x, y, r);
                }
                break;
            case '2':
                {
                    float x;
                    float y;
                    printf("\n%s", "Enter a number: ");
                    scanf("%f", &x);
                    printf("\n%s", "Enter an divisor: ");
                    scanf("%f", &y);
                    double r = fmod(x, y);
                    printf("\n%.2f modulo %.2f equals %.0f\n", x, y, r);
                }
                break;
            case '3':
                {
                    int x;
                    printf("\n%s", "Enter a number: ");
                    scanf("%d", &x);
                    double r = sqrt(x);
                    printf("\nSquare root of %d equals %.3f\n", x, r);
                }
                break;
            case '4':
                {
                    int x;
                    printf("\n%s", "Enter a number: ");
                    scanf("%d", &x);
                    double r = log10(x);
                    printf("\nLog-10 value of %d equals %.3f\n", x, r);
                }
                break;
            case '5':
                {
                    int x;
                    printf("\n%s", "Enter a number: ");
                    scanf("%d", &x);
                    double r = log(x);
                    printf("\nNatural log value of %d equals %.3f\n", x, r);
                }
                break;
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            default:
                cond = -1;
                break;
        }

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

     printf("]\n");

}

// End Arithmetic Content
