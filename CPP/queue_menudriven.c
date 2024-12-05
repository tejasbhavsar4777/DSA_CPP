#include <stdio.h>
#include <stdlib.h>

#define MAX 5
struct Queue {
    int front, rear;
    int items[MAX];
};


void insert(struct Queue *q, int element);
void deleteElement(struct Queue *q);
void display(struct Queue *q);
void search(struct Queue *q, int element);

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, element;


    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insertion
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(&q, element);
                break;
            case 2: // Deletion
                deleteElement(&q);
                break;
            case 3: // Display
                display(&q);
                break;
            case 4: // Search
                printf("Enter the element to search: ");
                scanf("%d", &element);
                search(&q, element);
                break;
            case 5: // Exit
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}


int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}


int isEmpty(struct Queue *q) {
    return q->front == -1;
}


void insert(struct Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert element.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = element;
        printf("Inserted %d into the queue.\n", element);
    }
}


void deleteElement(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete element.\n");
    } else {
        printf("Deleted %d from the queue.\n", q->items[q->front]);
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
    }
}


void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}


void search(struct Queue *q, int element) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int found = 0;
        for (int i = q->front; i <= q->rear; i++) {
            if (q->items[i] == element) {
                printf("Element %d found at position %d.\n", element, i);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Element %d not found in the queue.\n", element);
        }
    }
}
