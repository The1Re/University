#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char id[5];
    int score;
    bool pass;
}Student;

int main(void)
{
    int n,k=0,i;
    float avg=0;
    scanf("%d",&n);
    Student student[n];
    for (i=0; i<n; i++)
    {
        scanf("%s %d", student[i].id, &student[i].score);
        avg += student[i].score;
    }
    avg /= n;
    for (i=0; i<n; i++)
    {
        if (student[i].score >= avg){
            student[i].pass = true;
            k++;
        }else
            student[i].pass = false;
    }
    printf("%d\n",k);
    for (i=0; i<n; i++)
    {
        if (student[i].pass)
            printf("%s\n",student[i].id);
    }
    return 0;
}
   