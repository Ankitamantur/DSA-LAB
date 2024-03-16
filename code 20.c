#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Initialize an empty queue
void initialize(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    queue->arr[++queue->rear] = value;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[++queue->front];
}

// Display the queue
void display(struct Queue* queue) {
    printf("Queue contents: ");
    for (int i = queue->front + 1; i <= queue->rear; ++i)
        printf("%d ", queue->arr[i]);
    printf("\n");
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Dequeued element: %d\n", dequeue);
}
