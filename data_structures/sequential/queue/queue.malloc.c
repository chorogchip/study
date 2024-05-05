
typedef int item_t;

typedef struct
{
    int front;
    int rear;
    int size;
    item_t* data;
} Queue_Fixed;

void init_queue(Queue_Fixed* qu, int size) {
    qu->front = 0;
    qu->rear = 0;
    qu->size = size;
    qu->data = (item_t*)malloc(size*sizeof(item_t));
}

int empty(Queue_Fixed* qu) {
    return qu->front == qu->rear;
}

int push(Queue_Fixed* qu, item_t x) {
    if (qu->front != (qu->rear + 1) % qu->size) {
        qu->data[qu->rear] = x;
        qu->rear = (qu->rear + 1) % qu->size;
        return 0;
    } else {
        return -1;
    }
}

item_t pop(Queue_Fixed* qu) {
    item_t* tmp = &qu->data[qu->front];
    qu->front = (qu->front + 1) % qu->size;
    return *tmp;
}

void remove_queue(Queue_Fixed* qu) {
    free(qu->data);
}

int main(void) {
    Queue_Fixed qu;
    init_queue(&qu, 100);
    for (int i = 1; i <= 200; ++i) push(&qu, i);
    for (int i = 1; i <= 60; ++i) printf("%d ", pop(&qu));
    for (int i = 201; i <= 300; ++i) push(&qu, i);
    for (int i = 1; i < qu.size; ++i) printf("%d ", pop(&qu));
}