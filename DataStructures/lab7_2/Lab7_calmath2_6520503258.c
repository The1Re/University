#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#define MAX_STACK 10
#define MAX_STRING 20

int stack[MAX_STACK];
int top = -1;

bool isEmpty()
{
    return top == -1 ? true : false;
}

void push(int value)
{
    if (top == MAX_STACK)
        printf("Stack is Max!");
    else{
        stack[++top] = value;
    }
}

int pop()
{
    int data = -1;
    if (!isEmpty()){
        data = stack[top];
        top = top - 1;
    }
    return data;
}

int peek()
{
    return isEmpty() ? -1 : stack[top];
}

int operation(char opt, int x, int y)
{
    switch(opt)
    {
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
        case '^':return pow(x,y);
        default:
            return -1;
    }
}

int calculate(char postfix[])
{
    for (int i=0; i<strlen(postfix); i++)
    {
        if (isdigit(postfix[i])){
            push(postfix[i] - '0');
        }else{
            int num2 = pop();
            int num1 = pop();
            push(operation(postfix[i], num1, num2));
        }
    }
    return pop();
}

int main(void)
{
    char postfix[MAX_STRING];
    scanf("%s", postfix);
    printf("%d", calculate(postfix));
    return 0;
}