#include<stdio.h>
#include<math.h>

struct studen{
    char name[5];
    int score;
};

void main ()
{
    int number,i,p,name,score;
    float avg = 0;
    printf("enter number:");
    scanf("%d",&number);
    struct studen student[number];

    for (i = 0; i < number; i++)
    {
        printf("Enter name and score :");
        scanf("%s %d",&student[i].name,&student[i].score);
        avg += student[i].score;
    }
    avg /= number;
    for (i = 0; i < number; i++)
    {
        if(student[i].score >= avg){
            p++;
        }
    }
    printf("%d\n",p);
    for (i = 0; i < number; i++)
    {
        if(student[i].score >= avg){
            printf("%s \n",student[i].name);
        }
    }
}