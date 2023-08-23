#include <stdio.h>
#include <string.h>
#define maxsize 10

char Q[maxsize];
int front = -1, rear = -1;
int size = 0;

void enqueue(char);
char dequeue();

int main()
{
    char msg[100];
    scanf("%s", msg);
    for (int i=0; i<strlen(msg); i++)
    {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            enqueue(msg[i]);
        else if (msg[i] == '0')
            printf("%d%d", front, rear);
        else{
            for (int count=0; count<msg[i] - '0'; count++)
                printf("%c", dequeue());
        }
    }
    return 0;
}

void enqueue(char value)
{
    if (size == maxsize)
        printf("!");
    else{
        rear = (rear+1) % maxsize;
        Q[rear] = value;
        if (front == -1)
            front = 0;
        size++;
    }
}

char dequeue()
{
    char data;
    if (size == 0){
        return '!';
    }else{
        data = Q[front];
        front = (front+1) % maxsize;
        size--;
        return data;
    }
}