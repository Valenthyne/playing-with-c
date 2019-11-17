struct Node {
    char data;
    struct Node *next;
};

typedef struct Node LinkNode;
typedef LinkNode * LinkNodePtr;

void insert(LinkNodePtr *ptr, char v);
void display(LinkNodePtr *ptr);
