//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

void Bubblesort(int data[],int length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-i-1;j++)
        {
            if(data[j]>data[j+1])
            {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
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

    Bubblesort(data,n);

    printf("Sorted data list is");
    for(int i=0;i<n;i++)
        printf(" %d",data[i]);

    return 0;
}