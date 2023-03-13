//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

void greedy(int type[],int n,int value)
{
    printf("%d = ",value);
    for(int i=0;i<n-1;i++)
    {
        if(value/type[i]!=0)
            printf("%d*%d+",value/type[i],type[i]);
        value = value%type[i];
    }
    printf("%d*%d",value/type[n-1],type[n-1]);
}

int main()
{
    int n,value;
    printf("Enter number of money types : ");
    scanf("%d",&n);
    
    int type[n];
    printf("Enter values of each type (greatest to lowest) : ");
    for(int i=0;i<n;i++)
        scanf("%d",&type[i]);
    
    printf("Enter target value : ");
    scanf("%d",&value);

    greedy(type,n,value);

    return 0;
}