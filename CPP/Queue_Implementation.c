#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front, rear;
    int capacity;
} Queue;


Queue* createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}


int isEmpty(Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}


void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue overflow! Unable to enqueue %d\n", item);
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->arr[++queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}


int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Unable to dequeue\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}


int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}


int rear(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->rear];
}


void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}


void freeQueue(Queue *queue) {
    free(queue->arr);
    free(queue);
}

int main() {
    int capacity, choice, value;

    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Queue *queue = createQueue(capacity);

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1)
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                value = front(queue);
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;
            case 4:
                value = rear(queue);
                if (value != -1)
                    printf("Rear element: %d\n", value);
                break;
            case 5:
                display(queue);
                break;
            case 6:
                freeQueue(queue);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
