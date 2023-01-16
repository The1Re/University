#include <stdio.h>
#include <stdbool.h>

const int QUESTION_NUMBER = 10;
const char CORRECT_ANS[] = {'a','c','c','b','c','c','d','a','b','a'};
static int n;

void getStudentAnswer(char answerArray[]);
void checkAnswer(char answerArray[],bool resultArray[]);
void displayResult(int studentNumber,bool resultArray[]);
void sumAnswer(bool resultArray[],int *sum);

int main()
{
    printf("Please enter the numeber of the student : ");
    scanf("%d",&n);
    char studentAnswer[n][QUESTION_NUMBER];
    bool resultAnswer[n][QUESTION_NUMBER];
    for(int i=0;i<n;i++){
        printf("Answer of student %d : ",i+1);
        getStudentAnswer(studentAnswer[i]);
        checkAnswer(studentAnswer[i],resultAnswer[i]);
        displayResult(i+1,resultAnswer[i]);
    }
    printf("End program\n");
    
    return 0;
}

void getStudentAnswer(char answerArrey[])
{
        scanf("%s",answerArrey);
        return;
}

void checkAnswer(char answerArray[],bool resultArrey[])
{
    for(int i=0;i<QUESTION_NUMBER;i++)
    {
        for(int j=0;j<QUESTION_NUMBER;j++)
        {
            if(answerArray[i]==CORRECT_ANS[i])
                resultArrey[i]=true;
            else  
                resultArrey[i]=false;
        }
    }
    return;
}

void displayResult(int studentNumber,bool resultArray[])
{
    int sum=0;
    sumAnswer(resultArray,&sum);
    printf("Student %d got %d/%d\n",studentNumber,sum,QUESTION_NUMBER);
    if(sum==QUESTION_NUMBER)
        printf("No wrong answer");
    else{
        printf("Wrong answer in question : ");
        for(int i=0;i<QUESTION_NUMBER;i++)
        {
            if(!resultArray[i])
                printf("%d ",i+1);
        }
    }
    printf("\n");
    return;
}

void sumAnswer(bool resultAnswer[],int *sum)
{
    for(int i=0;i<QUESTION_NUMBER;i++)
    {
        if(resultAnswer[i])
            (*sum)++;
    }
    return;
}