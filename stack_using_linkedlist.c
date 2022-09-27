#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node* insertInHead(Node* head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    return newNode;
}

Node* removeFromHead(Node* head)
{
    Node* temp = head->next;
    free(head);
    return temp;
}

void printAll(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        printf("\t%d", temp->data);
        if(temp == head) printf(" <- Top");
        printf("\n");
        temp = temp->next;
    }
    
}

struct Stack{
    Node* head;
};
typedef struct Stack Stack;

Stack* push(Stack* stack, int data)
{
    stack->head = insertInHead(stack->head, data);
    return stack;
}

Stack* pop(Stack* stack, int data)
{
    stack->head = removeFromHead(stack->head);
    return stack;
}

int top(Stack* stack)
{
    return stack->head->data;
}

void printStack(Stack* stack){
    printf("Printing the stack:\n");
    printAll(stack->head);
}

int main()
{
    Stack stk;
    stk.head = NULL;
    push(&stk, 10);
    push(&stk, 20);
    push(&stk, 30);
    printStack(&stk);

    return 0;
}