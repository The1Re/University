//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int lcm(int a,int b)
{
    int i;
    for(i=1;i<=a*b;i++)
    {
        if(i%a==0 && i%b==0)
            break;
    }
    return i;
}

int main()
{
    int n,m;
    printf("Enter n & m : ");
    scanf("%d %d",&n,&m);
    printf("LCM of %d and %d is %d",n,m,lcm(n,m));

    return 0;
}