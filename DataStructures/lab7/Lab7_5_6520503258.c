#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 6

bool isEmpty(int top)
{
    return top == -1 ? true : false;
}

void push(char arr[], int *top, char value)
{
    *top = *top + 1;
    arr[*top] = value;
}

char pop(char arr[], int *top)
{
    if (isEmpty(*top)){
        return '!';
    }

    char value = arr[*top];
    *top = *top - 1;
    return value;
}



int main()
{
    char option[MAX], input;
    char current_text[MAX], temp_text[MAX];
    int cTop = -1, tTop = -1;

    while (true)
    {
        scanf("%s", option);
        if (!strcmp(option, "WRITE")){
            scanf(" %c", &input);
            push(current_text, &cTop, input);
        }else if (!strcmp(option, "UNDO")){
            push(temp_text, &tTop, pop(current_text, &cTop));
        }else if (!strcmp(option, "REDO")){
            push(current_text, &cTop, pop(temp_text, &tTop));
        }else if (!strcmp(option, "READ")){
            if (cTop == -1)
                printf("Blank document");
            else{
                for (int i=0; i<=cTop; i++)
                    printf("%c", current_text[i]);
                printf("\n");
            }
        }else{
            break;
        }
    }
    return 0;
}