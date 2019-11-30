struct stackNode {
    char data;
    struct stackNode * nextPtr;
};

typedef struct stackNode StkNode;
typedef StkNode * StkNodePtr;

// Stack function prototypes

void push(StkNodePtr * top, int info);
int pop(StkNodePtr * top);
int isStackEmpty(StkNodePtr top);
void printStack(StkNodePtr cur);

void push(StkNodePtr* top, int info) {

    StkNodePtr newPtr = malloc(sizeof(StkNode));

    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *top;
        *top = newPtr;
    } else {
        printf("\nNot enough memory available to push value!\n");
    }

}

int pop(StkNodePtr * top) {

    if (isStackEmpty(*top)) {
        printf("\n%s\n", "Stack is empty.");
        return -1;
    }

    StkNodePtr temp = * top;
    int result = (*top)->data;
    *top = (*top)->nextPtr;

    printf("\n%s%d\n", "Removing from stack: ", result);

    free(temp);
    return result;
}

void printStack(StkNodePtr cur) {

    StkNodePtr temp = cur;

    printf("\n[ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->nextPtr;
    }
    printf("]\n");

}

int isStackEmpty(StkNodePtr top) {
    return top == NULL;
}
