#include <stdio.h>
#include <stdbool.h>

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

bool isRelativelyPrime(int a,int b)
{
    if(gcd(a,b)==1)
        return true;
    return false;
}

void swap_min_to_max(int *a,int *b)
{
    int temp;
    if(b<a){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int a,b;
    printf("Input a,b : ");
    scanf("%d %d",&a,&b);
    
    swap_min_to_max(&a,&b);
    isRelativelyPrime(a,b) ? printf("-> True") : printf("-> False");
    return 0;
}