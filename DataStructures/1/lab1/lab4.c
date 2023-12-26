#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char id[5];
    int score;
    bool pass;
}Student;

int main(void)
{
    int n,k=0,sum=0;
    float avg;
    
    scanf("%d",&n);
    Student student[n];
    for (int i=0;i<n;i++)
    {
        scanf("%s %d",&student[i].id,&student[i].score);
        sum += student[i].score;
    }
    avg = (float)sum/n;

    for (int i=0;i<n;i++)
    {
        if (student[i].score >= avg){
            k++;
            student[i].pass = true;
        }else
            student[i].pass = false;
    }

    printf("%d\n",k);
    for (int i=0;i<n;i++)
    {
        if (student[i].pass)
            printf("%s\n",student[i].id);
    }
    return 0;
}