#include <stdio.h>

int main(){
    char name[30],grade;
    int score;
    
    printf("Input student name : ");
    scanf("%s",name);
    printf("Input student score : ");
    scanf("%d",&score);
    printf("------------------------------\n");
    printf("-CLASS PROJECT EXAMPLE RESULT-\n");
    printf("------------------------------\n");
    
    if(score >= 80)
        grade = 'A';
    else if(score >= 70)
        grade = 'B';
    else if(score >=60)
        grade = 'C';
    else
        grade = 'D';

    printf("%s's grade is %c",name,grade);
    return 0;
}