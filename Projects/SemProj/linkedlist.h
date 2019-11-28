struct Node {
    char data;
    struct Node *next;
};

typedef struct Node LinkNode;
typedef LinkNode * LinkNodePtr;

void insertLNode(LinkNodePtr *ptr, char v);
void display(LinkNodePtr *ptr);

void insertLNode (LinkNodePtr * sPtr, char v) {

    int count = 0;
    LinkNodePtr ptr = malloc(sizeof(LinkNode));

    if (ptr != NULL) {
        ptr->data = v;
        ptr->next = NULL;

        LinkNodePtr prev = NULL;
        LinkNodePtr cur = * sPtr;

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
void display(LinkNodePtr * ptr) {

    LinkNodePtr cur = ptr;

    printf("\n[ ");
    while (cur != NULL) {
        char ch = cur->data;
        printf("%c ", ch);
        cur = cur->next;
    }
    printf("] \n\n");
}
