//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int gcd(int a,int b)
{
    int i,max;
    max = a>b ? a : b;
    for(i=max;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
            break;
    }
    return i;
}

int main()
{
    int n,m;
    printf("Enter n & m : ");
    scanf("%d %d",&n,&m);
    printf("GCD of %d and %d is %d",n,m,gcd(n,m));

    return 0;
}