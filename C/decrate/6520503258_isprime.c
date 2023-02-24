//นายคเณศ อรชุนเลิศไมตรี 6520503258
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
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    isprime(n) ? printf("%d is a prime number",n):printf("%d is not a prime number",n);

    return 0;
}