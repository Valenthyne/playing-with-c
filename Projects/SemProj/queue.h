struct QueueNode {
    char data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode * front;
    struct QueueNode * back;
};

typedef struct QueueNode QueueNode;
typedef QueueNode * QueueNodePtr;
typedef struct Queue * QueuePtr;

void enqueue(QueuePtr q, int val);
QueueNodePtr dequeue(QueueNodePtr q);


void enqueue(QueuePtr q, int val) {

    QueueNodePtr node = NULL;
    node = malloc(sizeof(QueueNode));
    node->data = val;

    if (q->back == NULL) {
        q->front = node;
        q->back = node;
        return;
    }

    q->back->next = node;
    q->back = node;


}

QueueNodePtr dequeue(QueueNodePtr q) {



}
