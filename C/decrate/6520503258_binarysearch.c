//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int binary_search(int data[],int length,int x)
{
    int i=0,j=length-1,m;
    while(i<j)
    {
        m = (i+j)/2;
        if(x>data[m])
            i = m+1;
        else
            j = m; 
    }
    return (x == data[i]) ? i+1 : 0;
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

    int search = binary_search(data,n,x);
    search ? printf("found %d at location %d",x,search) : printf("Not found %d",x);

    return 0;
}