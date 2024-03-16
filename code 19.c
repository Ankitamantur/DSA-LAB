#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Display the stack
void display(struct Stack* stack) {
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; ++i)
        printf("%d ", stack->arr[i]);
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
