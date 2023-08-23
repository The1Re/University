#include <stdio.h>
#define maxsize 10

int Q[maxsize] = {0};
int front = -1, rear = -1;
int size = 0;

void enqueue(int);
int dequeue();
void display();

int main()
{
    int i,n;
    for (i=1; i<1000; i*=2)
        enqueue(i);
    display();

    scanf("%d", &n);
    for (i=1; i<=n; i++)
        dequeue();
    display();

    for (i=10; i>=1; i/=2)
        enqueue(i);
    display();
    return 0;
}

void enqueue(int value)
{
    if (size == maxsize)
        printf("Queue is Full\n");
    else{
        rear = (rear+1) % maxsize;
        Q[rear] = value;
        if (front == -1)
            front = 0;
        size++;
    }
}

int dequeue()
{
    int data;
    if (size == 0){
        printf("Queue is Empty\n");
        return -1;
    }else{
        data = Q[front];
        front = (front+1) % maxsize;
        size--;
        return data;
    }
}

void display()
{
    int i;
    if (size == 0)
        printf("Queue is Empty\n");
    else{
        printf("front[ ");
        for (i=front; i<size + front; i++)
            printf("%d ", Q[i%maxsize]);
        printf("] rear\n");
    }
}