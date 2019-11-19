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
int isEmpty(NodePtr top);
void printStack(NodePtr cur);

int main()
{
    char str[MAX_SIZE];
    printf("%s", "Please enter a string: ");
    scanf("%[^\n]s", str);
    int res = check(str);

    if (res) {
        printf("\n%s is a palindrome.\n", str);
    } else {
        printf("\n%s is not a palindrome.\n", str);
    }

    return 0;
}

int check(char * str) {

    char clean[MAX_SIZE];
    int index = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            clean[index++] = tolower(str[i]);
        }
    }

    clean[index] = '\0';

    int len = strlen(clean);

    if (len == 1) {
        return 1;
    }

    int mid = len / 2;

    NodePtr stack = NULL;

    for (int i = 0; i < mid; i++) {
            push(&stack, clean[i]);
    }

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
                return 0;
            }
        }
    }

    return 1;

}

void push(NodePtr* top, int info) {

    NodePtr newPtr = malloc(sizeof(Node));

    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *top;
        *top = newPtr;
    } else {
        printf("\nMemory error.");
    }

}

int pop(NodePtr * top) {

    NodePtr temp = * top;
    int val = (*top)->data;
    *top = (*top)->nextPtr;
    free(temp);
    return val;
}

int isEmpty(NodePtr top) {
    return top == NULL;
}

void printStack(NodePtr cur) {

    printf("\n[ ");
    while (cur != NULL) {
        printf("%c ", cur->data);
        cur = cur->nextPtr;
    }
    printf("]\n");
}

