struct stackNode {
    char data;
    struct stackNode * nextPtr;
};

typedef struct stackNode StkNode;
typedef StkNode * StkNodePtr;

// Stack function protoypes

void push(StkNodePtr * top, int info);
int pop(StkNodePtr * top);
int isEmpty(StkNodePtr top);
void printStack(StkNodePtr cur);

void push(StkNodePtr* top, int info) {

    StkNodePtr newPtr = malloc(sizeof(Node));

    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *top;
        *top = newPtr;
    } else {
        printf("\nNot enough memory available to generate stack!\n");
    }

}

int pop(StkNodePtr * top) {

    StkNodePtr temp = * top;
    int val = (*top)->data;
    *top = (*top)->nextPtr;
    free(temp);
    return val;
}
