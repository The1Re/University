#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STRING 30
#define MAX_STACK 10

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

int priority(char c)
{
    char high[] = "^", medium[] = "*/", low[] = "+-";
    if (strchr(high, c))
        return 2;
    else if (strchr(medium, c))
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
            while ((char)peek() != '(')
                output[index++] = pop();
            pop();
        }else{
            if (isEmpty())
                push(input[i]);
            else{
                while (priority(input[i]) <= priority((char)peek()))
                    output[index++] = pop();
                push(input[i]);
            }
        }
    }
    while (!isEmpty())
        output[index++] = pop();
    output[index] = '\0';
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

int hash(char c) //a index is 0 Z index is lastindex
{
    if (isupper(c))
        return c-'A'+26;
    else
        return c-'a';
}

int calculate(char postfix[])
{
    int hash_table[26*2] = {0}; //upper and lower alphabet
    for (int i=0; i<strlen(postfix); i++)
    {
        if (isalnum(postfix[i])){
            int data, key = hash(postfix[i]);
            if (hash_table[key] == 0){
                printf("Enter value of %c : ", postfix[i]);
                scanf("%d", &data);
                hash_table[key] = data;
            }
            push(hash_table[key]);
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
    char infix[MAX_STRING], postfix[MAX_STRING];
    printf("Enter infix : ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix : %s\n", postfix);

    printf("Result = %d\n", calculate(postfix));
    return 0;
}