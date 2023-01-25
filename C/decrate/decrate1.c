#include <stdio.h>
#include <stdbool.h>

bool isprime(int x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int main()
{
    int a;
    printf("Input a : ");
    scanf("%d",&a);
    isprime(a) ? printf("Is prime"):printf("Is not prime");

    return 0;
}