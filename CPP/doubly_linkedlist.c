#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insert_beg(struct Node **head, int data);
void insert_end(struct Node **head, int data);
void insert_position(struct Node **head, int data, int position);
void delete_beg(struct Node **head);
void delete_end(struct Node **head);
void delete_position(struct Node **head, int position);
void display(struct Node *head);

int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_beg(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insert_position(&head, data, position);
                break;
            case 4:
                delete_beg(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                delete_position(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void insert_beg(struct Node **head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void insert_end(struct Node **head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}

void insert_position(struct Node **head, int data, int position) {
    if (position == 1) {
        insert_beg(head, data);
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    new_node->data = data;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
}

void delete_beg(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void delete_end(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;

    free(temp);
}

void delete_position(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1) {
        delete_beg(head);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
