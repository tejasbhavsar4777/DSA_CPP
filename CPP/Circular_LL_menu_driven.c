#include<stdio.h>
#include<stdlib.h>

#define max_size 5

int queue[max_size];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == max_size - 1) || (front == rear + 1);
}

int isEmpty()
{
    return front == -1;
}

void insert(int value)
{
    if (isFull()){
        printf("Queue is full.cannot insert %d\n",value);
        return;
    }

    if (front==-1)
    {
        front = 0;
    }
    rear = (rear + 1)% max_size;
    queue[rear]=value;
    printf("%d inserted into the queue\n",value);
}
void delete(){
    if(isFull()){
        printf("Queue is full. Cannot insert %d\n");
        return;
    }
    printf("Element %d deleted from the queue\n",queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else{
        front = (front + 1)% max_size;
    }
}
void display(){

    if (isEmpty()){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i!=rear){
        printf("%d", queue[i]);
        i = (i+1)%max_size;
    }
    printf("%d\n", queue[rear]);
}
void search(int value){
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    int i =front;
    while (i!=rear){
        if (queue[i]==value){
            printf("Element %d found in the equal\n", value);
            return;
        }
        i = (i+1)%max_size;
    }
    if (queue[rear]==value){
        printf("Element %d found in the queue\n", value);
    }else{
        printf("Element %d not found in the queue\n", value);
    }
}

int main()
{

    int choice, value;

    while(1){

        printf("\n---Menu Driven Program to implement Circular Queue: ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

