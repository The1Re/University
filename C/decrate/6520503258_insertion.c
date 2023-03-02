//นายคเณศ อรชุนเลิศไมตรี 6520503258
#include <stdio.h>

void Insertsort(int data[],int length)
{
    int temp,i,j;
    for(i=1;i<length;i++)
    {
        temp = data[i];
        j = i-1;
        while(j>=0 && data[j]>temp)
        {
            data[j+1]=data[j];
            j--;
        }
        data[j+1] = temp;
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

    Insertsort(data,n);

    printf("Sorted data list is");
    for(int i=0;i<n;i++)
        printf(" %d",data[i]);

    return 0;
}