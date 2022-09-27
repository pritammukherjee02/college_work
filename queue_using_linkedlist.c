#include <stdio.h>
#include <stdlib.h>

// push_back <- O(N)
// pop_front <- O(1)
// printing <- O(N)

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node* insertAtBack(Node* head, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return head;
    }

    Node* pointer = head;
    while(pointer->next != NULL)
        pointer = pointer->next;
    
    pointer->next = temp;
    return head;
}

Node* deleteFromFront(Node* head)
{
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void printAll(Node* head, int back)
{
    Node* temp = head;
    printf("Printing Queue:\n");
    int i = 0;
    while(temp){
        printf("\t%d", temp->data);
        if(temp == head)
            printf(" <- Front");
        else if(i == back)
            printf(" <- Back");

        printf("\n");
        i++;
        temp = temp->next;
    }
}

struct Queue{
    Node* head;
    int back;
};
typedef struct Queue Queue;

void push_back(Queue* q, int data)
{
    q->head = insertAtBack(q->head, data);
    q->back++;
}

void pop_front(Queue* q)
{
    q->head = deleteFromFront(q->head);
    q->back--;
}

void print_queue(Queue* q)
{
    printAll(q->head, q->back);
}

int main()
{
    Queue q;
    q.head = NULL;
    q.back = -1;
    push_back(&q, 10);
    push_back(&q, 20);
    push_back(&q, 30);
    print_queue(&q);

    return 0;
}