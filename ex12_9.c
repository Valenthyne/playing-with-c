#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 10

// Basic constructs for a linked list structure
struct LinkedListNode {
    char data;
    struct Node *next;
};

typedef struct LinkedListNode Node;
typedef Node * NodePtr;

// Function prototypes for linked list operations
void insert(NodePtr *ptr, char v);
void display(NodePtr *ptr);
NodePtr reverse(NodePtr *ptr);

int main(void)
{
    printf("This program will allow you to reverse a linked list of ten characters!\n\n");

    NodePtr start = NULL;
    char ch;
    int c = 0;

    printf("%s\n\n", "Please enter 10 characters!");

    // Prompt user to input ten characters of their choice
    while (c != 10) {
        printf("Remaining Characters: %d\n", (10 - c));
        printf("%s", "Input value: ");
        scanf(" %c", &ch);
        insert(&start, ch);
        display(start);
        c++;
    }

    // Create a new node pointer that seeks to reverse the list
    NodePtr rev = reverse(start);

    // Display original list to show that it was not modified
    printf("\nOriginal List:");
    display(start);

    // Display reversed list to show it is new and reversed
    printf("\nReversed List:");
    display(rev);

    return 0;
}

// Basic function used to insert nodes into a linked list
void insert(NodePtr * sPtr, char v) {

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
        printf("\nNot enough memory available to generate node!\n");
    }

}

// Basic function used to display a linked list from a given pointer
void display(NodePtr * ptr) {

    NodePtr cur = ptr;

    printf("\n[ ");
    while (cur != NULL) {
        char ch = cur->data;
        printf("%c ", ch);
        cur = cur->next;
    }
    printf("] \n\n");
}

// Function used to generate a new list to be comprised of the reversed list of the original input
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
