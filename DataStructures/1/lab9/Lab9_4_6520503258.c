#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK 10
int stack[MAX_STACK] = {0}, top = -1;
int sum = 0;

bool isEmpty()
{
    return (top == -1) ? true : false;
}
void push(int data)
{
    if (top == MAX_STACK-1)
        printf("Stack is Full!\n");
    else{
        stack[++top] = data;
    }
}
int pop()
{
    if (isEmpty())
        return -1;
    else{
        return stack[top--];
    }
}

int leftNode(int k)
{
    return 2*k+1;
}
int rightNode(int k)
{
    return 2*k+2;
}

bool Inorder(int T[], int MAXTREE, int node, int low, int high)
{
    int max = 0;
    while (!isEmpty() || node < MAXTREE)
    {
        if (node < MAXTREE){
            push(node);
            node = leftNode(node);
        }else{
            node = pop();

            if (T[node] != 0){
                if (T[node] > max)
                    max = T[node];
                else
                    return false;

                if (T[node] >= low && T[node] <= high)
                    sum += T[node];
            } 

            node = rightNode(node);
        }
    }
    return true;
}


int main(void)
{
    int n, low, high;
    scanf("%d", &n);
    int Tree[n];
    for (int i=0; i<n; i++)
        scanf("%d", &Tree[i]);
    scanf("%d %d", &low, &high);

    bool isBinarySearchTree = Inorder(Tree, n, 0, low, high);
    printf("%d\n", isBinarySearchTree);
    if (isBinarySearchTree)
        printf("%d\n", sum);
        
    return 0;
}