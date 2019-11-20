#include <stdio.h>
#include <stdlib.h>

// Basic constructs for a linked list node structure
struct LinkedListNode {
    char data;
    struct Node *next;
};

typedef struct LinkedListNode Node;
typedef Node * NodePtr;

// Function prototypes for linked list operations
void insert(NodePtr *ptr, char v);
void display(NodePtr *ptr);
void concatenate(NodePtr *p1, NodePtr *p2);

int main(void)
{

    // Initialize pointers for the two lists
    NodePtr s1 = NULL;
    NodePtr s2 = NULL;

    char ch;
    int c1;
    int c2;

    printf("This program will allow you to generate two lists and concatenate them!\n\n");

    printf("How many characters do you want in List #1? ");
    scanf(" %d", &c1);
    printf("\nPlease enter %d characters!\n\n", c1);

    while (c1 != 0) {
        printf("Remaining Characters: %d\n", c1);
        printf("%s", "Enter: ");
        scanf(" %c", &ch);
        insert(&s1, ch);
        display(s1);
        c1--;
    }

    printf("How many characters do you want in List #2? ");
    scanf(" %d", &c2);
    printf("Please enter %d characters!\n\n", c2);


    while (c2 != 0) {
        printf("Remaining Characters: %d\n", c2);
        printf("%s", "Enter: ");
        scanf(" %c", &ch);
        insert(&s2, ch);
        display(s2);
        c2--;
    }

    printf("\nConcenation of List 1 and List 2:");
    concatenate(s1, s2);
    display(s1);

    return 0;
}

void insert(NodePtr *sPtr, char v) {

    NodePtr ptr = malloc(sizeof(Node));

    if (ptr != NULL) {
        ptr->data = v;
        ptr->next = NULL;

        NodePtr prev = NULL;
        NodePtr cur = * sPtr;

        while (cur != NULL) {
        prev = cur;
        cur = cur->next;
        }

        if (prev == NULL) {
            ptr->next = * sPtr;
            * sPtr = ptr;
        } else {
            prev->next = ptr;
            ptr->next = cur;
        }
    } else {
        printf("\nNot enough memory available to generate node!\n");
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

void concatenate(NodePtr * p1, NodePtr * p2) {

    // There's nothing to do if both lists are empty
    if (p1 == NULL && p2 == NULL) {
        return;
    }

    NodePtr cur = p1;

    // Cycle through and find the end of the first list
    while (cur->next != NULL) {
        cur = cur->next;
    }

    // Link the end of the first list to the second list
    cur->next = p2;
}
