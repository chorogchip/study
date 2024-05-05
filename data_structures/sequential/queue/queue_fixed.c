
typedef int item_t;
#define MAX_SIZE 100

typedef struct
{
    int front;
    int rear;
    item_t data[MAX_SIZE];
} Queue_Fixed;

void init_queue(Queue_Fixed* qu) {
    qu->front = 0;
    qu->rear = 0;
}

int empty(Queue_Fixed* qu) {
    return qu->front == qu->rear;
}

int push(Queue_Fixed* qu, item_t x) {
    if (qu->front != (qu->rear + 1) % MAX_SIZE) {
        qu->data[qu->rear] = x;
        qu->rear = (qu->rear + 1) % MAX_SIZE;
        return 0;
    } else {
        return -1;
    }
}

item_t pop(Queue_Fixed* qu) {
    item_t* tmp = &qu->data[qu->front];
    qu->front = (qu->front + 1) % MAX_SIZE;
    return *tmp;
}

int main(void) {
    Queue_Fixed qu;
    init_queue(&qu);
    for (int i = 1; i <= 200; ++i) push(&qu, i);
    for (int i = 1; i <= 60; ++i) printf("%d ", pop(&qu));
    for (int i = 201; i <= 300; ++i) push(&qu, i);
    for (int i = 1; i < MAX_SIZE; ++i) printf("%d ", pop(&qu));
}