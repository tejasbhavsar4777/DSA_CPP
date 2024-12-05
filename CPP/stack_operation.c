#include<stdio.h>
#include<stdlib.h>


typedef struct Stack{
    int *arr;
    int top;
    int capacity;
}Stack;


Stack* createStack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity=capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity*sizeof(int));
    return stack;

}

int isFull(Stack*stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack*stack){
    return stack->top == -1;
}

void push(Stack*stack, int item){
    if (isFull(stack)){
        printf("Stack overflow! unable to push %d\n",item);
        return;
    }
    stack->arr[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack*stack){
    if (isEmpty(stack)){
        printf("stack underflow! unable to pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
int peek(Stack*stack){
    if (isEmpty(stack)){
        printf("stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(Stack*stack){
    if (isEmpty(stack)){
        printf("stack is empty\n");
        return;
    }
    printf("stack elements: ");
    for (int i=0;i<=stack->top;i++){
        printf("%d", stack->arr[i]);

    }
    printf("\n");
}
void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

int main()
{
    int capacity, choice, value;

    printf("Enter the capacity of the stack: ");
    scanf("%d",&capacity);

    Stack*stack = createStack(capacity);

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek(stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                freeStack(stack);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}







