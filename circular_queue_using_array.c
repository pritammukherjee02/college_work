#include <stdio.h>

// TODO: NOT COMPLETED

struct CQueue{
    int ARR[20];
    int front;
};
typedef struct CQueue CQueue;

CQueue* push_back(CQueue* q, int data)
{
    if(q->front >= 20)
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

CQueue* pop_front(CQueue* q)
{
    if(q->front <= 0){
        printf("Queue empty\n");
        return NULL;
    }

    q->ARR[q->front--] == 0;
    return q;
}

int main()
{


    return 0;
}