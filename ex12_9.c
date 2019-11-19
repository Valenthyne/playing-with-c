/*
    12.9 (Creating a Linked List, Then Reversing Its Elements)
    Write a program that creates a linked list of 10 characters,
    then creates a copy of the list in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 10

// Basic constructs for a linked list structure
struct Node {
    char data;
    struct Node *next;
};

typedef struct Node Node;
typedef Node * NodePtr;

// Function prototypes for linked list operations
void insert(NodePtr *ptr, char v);
void display(NodePtr *ptr);
NodePtr reverse(NodePtr *ptr);

int main(void)
{
    NodePtr start = NULL;
    char ch;
    int c = 0;

    printf("%s\n\n", "Please enter 10 characters!");

    while (c != 10) {
        printf("Remaining Characters: %d\n", (10 - c));
        printf("%s", "Enter: ");
        scanf(" %c", &ch);
        insert(&start, ch);
        display(start);
        c++;
    }

    NodePtr rev = reverse(start);

    printf("\nOriginal List:");
    display(start);

    printf("\nReversed List:");
    display(rev);

    return 0;
}

void insert(NodePtr *sPtr, char v) {

    int count = 0;
    NodePtr ptr = malloc(sizeof(Node));

    if (ptr != NULL) {
        ptr->data = v;
        ptr->next = NULL;

        NodePtr prev = NULL;
        NodePtr cur = * sPtr;

        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
            count++;
        }

        if (prev == NULL) {
            ptr->next = * sPtr;
            * sPtr = ptr;
        } else {
            prev->next = ptr;
            ptr->next = cur;
        }
    } else {
        printf("Memory not available.");
    }

}

void display(NodePtr* ptr) {

    NodePtr cur = ptr;

    printf("\n[ ");
    while (cur != NULL) {
        char ch = cur->data;
        printf("%c ", ch);
        cur = cur->next;
    }
    printf("] \n\n");
}

NodePtr reverse(NodePtr * ptr) {

    char val[MAX_CHAR] = {};
    int index = 0;

    NodePtr rev = NULL;
    NodePtr cur = ptr;

    while (cur != NULL) {
        val[index++] = cur->data;
        cur = cur->next;
    }

    for (size_t i = 0; i < MAX_CHAR; i++) {
        insert(&rev, val[i]);
    }

    NodePtr head = NULL;
    NodePtr tail = rev;

    while (tail != NULL) {
        NodePtr temp = tail->next;
        tail->next = head;
        head = tail;
        tail = temp;
    }

    return head;
}
