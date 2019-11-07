/*
    12.9 (Creating a Linked List, Then Reversing Its Elements)
    Write a program that creates a linked list of 10 characters,
    then creates a copy of the list in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

typedef struct Node Node;
typedef Node * NodePtr;

void insert(NodePtr *ptr, char v);
void display(NodePtr *ptr);
NodePtr reverse(NodePtr *ptr);

int main()
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

    printf("\nReversed List:");
    NodePtr rev = reverse(start);
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

        while (cur != NULL && v > cur->data) {
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

    NodePtr head = NULL;
    NodePtr tail = ptr;

    while (tail != NULL) {
        NodePtr temp = tail->next;
        tail->next = head;
        head = tail;
        tail = temp;
    }

    return head;
}
