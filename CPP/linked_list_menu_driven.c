#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void insert_beg(struct Node** head, int data);
void insert_end(struct Node** head, int data);
void insert_position(struct Node** head, int data, int position);
void delete_beg(struct Node** head);
void delete_end(struct Node** head);
void delete_position(struct Node** head, int position);
void display(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &data);
                insert_beg(&head, data);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert (1-based index): ");
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
                printf("Enter the position to delete (1-based index): ");
                scanf("%d", &position);
                delete_position(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void insert_beg(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    printf("Inserted %d at the beginning.\n", data);
}

void insert_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;  // If the list is empty, make new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Inserted %d at the end.\n", data);
}

void insert_position(struct Node** head, int data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 1) {  // Insert at beginning if position is 1
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range!\n");
            free(new_node);
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf("Inserted %d at position %d.\n", data, position);
}

void delete_beg(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete from beginning.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void delete_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete from end.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {  // If only one node in the list
        printf("Deleted %d from the end.\n", temp->data);
        free(temp);
        *head = NULL;
    } else {
        struct Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted %d from the end.\n", temp->data);
        free(temp);
    }
}

void delete_position(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete from position %d.\n", position);
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {  // Delete from beginning if position is 1
        *head = (*head)->next;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
    } else {
        struct Node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range!\n");
            return;
        }
        prev->next = temp->next;
        printf("Deleted %d from position %d.\n", temp->data, position);
        free(temp);
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
