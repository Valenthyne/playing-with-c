struct QueueNode {
    int data;
    struct QueueNode *next;
};

typedef struct QueueNode QueueNode;
typedef QueueNode * QueueNodePtr;

void enqueue(QueueNodePtr * head, QueueNodePtr * tail, int val);
int dequeue(QueueNodePtr * head, QueueNodePtr * tail);
int isQueueEmpty(QueueNodePtr head);
void printQueue(QueueNodePtr cur);

void enqueue(QueueNodePtr * head, QueueNodePtr * tail, int val) {

    QueueNodePtr nodePtr = malloc(sizeof(QueueNode));

    if (nodePtr != NULL) {
        nodePtr->data = val;
        nodePtr->next = NULL;

        if (isQueueEmpty(*head)) {
            *head = nodePtr;
        } else {
            (*tail)->next = nodePtr;
        }

        *tail = nodePtr;
    } else {
        printf("Memory issue.");
    }

}

int dequeue(QueueNodePtr * head, QueueNodePtr * tail) {

    if (isQueueEmpty(*head)) {
        printf("\n%s\n", "The queue is empty.");
        return -1;
    }

    int result = (*head)->data;
    QueueNodePtr temp = *head;
    *head = (*head)->next;

    if (head == NULL) {
        tail = NULL;
    }

    free(temp);

    printf("\n%s%d\n", "Removing from queue: ", result);

    return result;

}


int isQueueEmpty(QueueNodePtr head) {
    return head == NULL;
}

void printQueue(QueueNodePtr cur) {

    QueueNodePtr temp = cur;

    printf("\n[ ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("]\n");

}
