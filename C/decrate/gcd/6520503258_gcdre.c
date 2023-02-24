//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}

int main()
{
    int n,m;
    printf("Enter n & m : ");
    scanf("%d %d",&n,&m);
    printf("GCD of %d and %d is %d",n,m,gcd(n,m));

    return 0;
}