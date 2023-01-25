#include <stdio.h>

int sol1_gcd(int a,int b)
{
    int i;
    for(i=a;a%i!=0 || b%i!=0;i--);
    return i;
}

int sol1_lcm(int a,int b)
{
    int i;
    for(i=b;i%b!=0 || i%a!=0;i++);
    return i;
}

int main()
{
    int a,b;
    printf("Input a,b : ");
    scanf("%d %d",&a,&b);
    printf("gcd sol1 = %d\n",sol1_gcd(a,b));
    printf("lcm sol1 = %d\n",sol1_lcm(a,b));

    return 0;
}