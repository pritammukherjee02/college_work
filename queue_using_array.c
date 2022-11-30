#include <stdio.h>

// push_back -> O(N)
// pop_front -> O(1)
// printinf -> O(N)

#define QUEUE_SIZE 50

struct Queue{
    int ARR[QUEUE_SIZE];
    int front;
};
typedef struct Queue Queue;

Queue* push_back(Queue* q, int data)
{
    if(q->front >= QUEUE_SIZE)
    {
        printf("Queue Full!\n");
        return NULL;
    }
    
    for(int ptr = q->front++; ptr >= 0; ptr--)
    {
        q->ARR[ptr+1] = q->ARR[ptr];
    }
    q->ARR[0] = data;
    return q;
}

Queue* pop_front(Queue* q)
{
    if(q->front <= 0){
        printf("Queue empty\n");
        return NULL;
    }

    q->ARR[q->front--] == 0;
    return q;
}

int getFront(Queue* q)
{
    return q->ARR[q->front];
}

void printQueue(Queue* q)
{
    printf("Printing Queue:\n");
    for(int i = q->front; i >= 0; i--)
    {
        printf("\t%d", q->ARR[i]);
        if(i == q->front)
            printf(" <- Front");
        else if(i == 0)
            printf(" <- Back");

        printf("\n");
    }
}

int main()
{
    Queue q;
    q.front = -1;
    int choice = 0;
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
                printQueue(&q);
                break;
            default:
                choice = 5;
                break;
        }
        printf("Done\n\n");
    }

    return 0;
}