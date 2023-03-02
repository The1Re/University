//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

int findmax(int data[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(data[i]>data[i+1]){
            int temp = data[i];
            data[i] = data[i+1];
            data[i+1] = temp;
        }
    }
    return data[n-1];
}

int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int data[n];
    printf("Enter %d data : ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);

    printf("The maximum is %d",findmax(data,n));
    
    return 0;
}