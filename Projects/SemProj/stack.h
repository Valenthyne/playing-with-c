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
