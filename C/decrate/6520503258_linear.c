//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int linear_search(int data[],int length,int x)
{
    int location = 0;
    for(int i=0;i<length;i++)
    {
        if(data[i]==x){
            location = i+1;
            break;
        }
    }
    return location;
}

int main()
{
    int n,x;
    printf("Enter n : ");
    scanf("%d",&n);

    int data[n];
    printf("Enter %d data : ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);

    printf("Enter x : ");
    scanf("%d",&x);

    int search = linear_search(data,n,x);
    search ? printf("found %d at location %d",x,search) : printf("Not found %d",x);

    return 0;
}