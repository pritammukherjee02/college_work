#include <stdlib.h>

int stack1[100], stack2[100], top1 = -1, top2 = -1, count = 0;

void push1(int x){
    stack1[++top1] = x;
}

int pop1(){
    return stack1[top1--];
}

void push2(int x){
    stack2[++top2] = x;
}

int pop2(){
    return stack2[top2--];
}

void enqueue(){
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);
    push1(data);
    count++;
}

void dequeue(){
    int i;
    for(i = 0; i <= count; i++){
        push2(pop1());
    }
    pop2();
    count--;
    for(i = 0; i <= count; i++){
        push1(pop2());
    }
}

void display(){
    int i;
    for(i = 0; i <= top1; i++){
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main(){
    int num;
    printf("Choose your option:\n");
    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
        printf("Enter correct choice\n");
            break;
        }
    } while (num != 4);
    

    return 0;
}