#include <stdio.h>

struct Stack{
    int ARR[50];
    int top;
};
typedef struct Stack Stack;

void push(Stack* stack, int data)
{
    if(stack->top == 49)
    {
        printf("Stackoverflow!\n");
        return;
    }
    stack->ARR[++stack->top] = data;
}

int pop(Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack-underflow!\n");
        return -1;
    }

    int temp = stack->ARR[stack->top];
    stack->ARR[stack->top--] = (int)NULL;
    return temp;
}

int top(Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }

    return stack->ARR[stack->top];
}

void printStack(Stack* stack)
{
    int temp = stack->top;
    if(temp == -1){
        printf("Stack Empty\n");
        return;
    }

    printf("Printing Stack:\n");
    while(temp != -1)
    {
        printf("\t%d", stack->ARR[temp--]);
        if(temp + 1 == stack->top) printf(" <- Top");
        printf("\n");
    }
}

int main()
{
    Stack stack;
    stack.top = -1;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    printStack(&stack);

    return 0;
}