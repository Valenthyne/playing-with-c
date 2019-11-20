#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int check(char * str);

// Basic constructs for a stack structure
struct stackNode {
    char data;
    struct stackNode * nextPtr;
};

typedef struct stackNode Node;
typedef Node * NodePtr;

// Stack function prototypes
void push(NodePtr * top, int info);
int pop(NodePtr * top);

int main(void)
{
    printf("This program will allow you to use a stack to see if a string is a palindrome!\n\n");

    char str[MAX_SIZE];
    printf("%s", "Enter a string: ");
    scanf("%[^\n]s", str);
    int res = check(str);

    if (res) {
        printf("\n%s is INDEED a palindrome.\n", str);
    } else {
        printf("\n%s is NOT a palindrome.\n", str);
    }

    return 0;
}

int check(char * str) {

    // Starts to generate a clean string, free of punctuation and spaces
    char clean[MAX_SIZE];
    int index = 0;

    // Checks if the given character is an alphabetical one
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            // Makes it lower case for ease of analysis; case is irrelevant for this problem
            clean[index++] = tolower(str[i]);
        }
    }

    // Terminates the string with a null character
    clean[index] = '\0';

    int len = strlen(clean);

    if (len == 1) {
        return 1;
    }

    // Midpoint identified for palindrome evaluation
    int mid = len / 2;

    // Start generating a stack
    NodePtr stack = NULL;

    for (int i = 0; i < mid; i++) {
            push(&stack, clean[i]);
    }

    // Algorithm for palindrome evaluation will differ by string length (odd or even)
    if (len % 2 != 0) {
        for (int i = mid + 1; i < len; i++) {
            char ch = pop(&stack);
            if (ch != clean[i]) {
                return 0;
            }
        }
    } else {
        for (int i = mid; i < len; i++) {
            char ch = pop(&stack);
            if (ch != clean[i]) {
                // If at any point the stack char doesn't match the string, not a palindrome
                return 0;
            }
        }
    }

    // Palindrome achieved
    return 1;

}

void push(NodePtr* top, int info) {

    NodePtr newPtr = malloc(sizeof(Node));

    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *top;
        *top = newPtr;
    } else {
        printf("\nNot enough memory available to generate stack!\n");
    }

}

int pop(NodePtr * top) {

    NodePtr temp = * top;
    int val = (*top)->data;
    *top = (*top)->nextPtr;
    free(temp);
    return val;
}
