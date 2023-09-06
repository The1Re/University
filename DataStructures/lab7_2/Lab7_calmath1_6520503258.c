#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING 20
#define MAX_STACK 10

char stack[MAX_STACK];
int top = -1;

bool isEmpty()
{
    return top == -1 ? true : false;
}

void push(char value)
{
    if (top == MAX_STACK)
        printf("Stack is Max!");
    else{
        stack[++top] = value;
    }
}

char pop()
{
    char data = '!';
    if (!isEmpty()){
        data = stack[top];
        top = top - 1;
    }
    return data;
}

char peek()
{
    return isEmpty() ? -1 : stack[top];
}

int priority(char c)
{
    char high[] = "*/^", low[] = "+-";
    if (strchr(high, c))
        return 1;
    else if (strchr(low, c))
        return 0;
    else
        return -1;
}

void infixToPostfix(char input[], char output[])
{
    int index = 0;
    for (int i=0; i<strlen(input); i++)
    {
        if (isalnum(input[i]))
            output[index++] = input[i];
        else if (input[i] == '(')
            push(input[i]);
        else if (input[i] == ')'){
            while (peek() != '(')
                output[index++] = pop();
            pop();
        }else{
            if (isEmpty())
                push(input[i]);
            else{
                while (priority(input[i]) <= priority(peek()))
                    output[index++] = pop();
                push(input[i]);
            }
        }
    }
    while (!isEmpty())
        output[index++] = pop();
    output[index] = '\0';
}

int main(void)
{
    char infix[MAX_STRING], postfix[MAX_STRING];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    puts(postfix);

    return 0;
}