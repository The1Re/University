//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int mod(int n,int m)
{
    int result = n%m;
    if(n<0)
        result += m;
    return result;
}

int main()
{
    int n,m,temp;
    printf("Enter n m : ");
    scanf("%d %d",&n,&m);

    printf("%d mod %d = %d",n,m,mod(n,m));

    return 0;
}