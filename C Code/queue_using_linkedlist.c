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

int getFront(Queue* q)
{
    return q->head->data;
}

int main()
{
    Queue q;
    q.head = NULL;
    q.back = -1;

    int choice = 10;
    while(choice != 5){
        printf("Your Choices:\n1. Insert an element\n2. Delete an element\n3. Peek at front\n4. Display queue\n5. Exit\nChoose: ");
        scanf("%d", &choice);

        int num;
        switch(choice){
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                push_back(&q, num);
                break;
            case 2:
                pop_front(&q);
                break;
            case 3:
                printf("%d\n", getFront(&q));
                break;
            case 4:
                print_queue(&q);
                break;
            default:
                choice = 5;
                break;
        }
        printf("Done\n\n");
    }

    return 0;
}