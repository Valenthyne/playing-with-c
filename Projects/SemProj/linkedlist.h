struct LinkedNode {
    int data;
    struct LinkedNode *next;
};

typedef struct LinkedNode LinkedNode;
typedef LinkedNode * LinkNodePtr;

void insertLNode(LinkNodePtr *ptr, int v);
void showPointers(LinkNodePtr * ptr);
void sortList(LinkNodePtr * ptr);
void revList(LinkNodePtr ptr);
void remValue(LinkNodePtr ptr, int k);


void insertLNode (LinkNodePtr * sPtr, int v) {

    int count = 0;
    LinkNodePtr ptr = malloc(sizeof(LinkedNode));

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
        printf("\nNot enough memory available to insert value!\n");
    }

}

void showPointers(LinkNodePtr * ptr) {

    LinkNodePtr cur = ptr;

    printf("\n[ ");
    while (cur != NULL) {
        int val = cur->data;
        printf("%d -> ", val);
        cur = cur->next;
    }
    printf("NULL]\n");

}

void revList(LinkNodePtr ptr) {

    LinkNodePtr u = NULL;
    LinkNodePtr v = ptr;

    while (v != NULL) {
        LinkNodePtr w = v->next;
        v->next = u;
        u = v;
        v = w;
    }

    ptr = u;

    printf("\n%s\n", "List after reversal:");
    showPointers(ptr);

}

void remValue(LinkNodePtr ptr, int k) {

    LinkNodePtr cur = ptr;
    LinkNodePtr prev = NULL;

    while (cur != NULL) {

        int v = cur->data;

        if (v == k && prev != NULL) {
            prev->next = cur->next;
        } else if (v == k && prev == NULL) {
            ptr = ptr->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }

    printf("\n%s%d\n", "List after removing ", k);
    showPointers(ptr);
}
