#include <stdio.h>
#include <string.h>

const char chk[]="MDCLXVI";

int switchrm(char c)
{
    int sum;
    switch(c){
        case 'M':sum = 1000;break;
        case 'D':sum = 500;break;
        case 'C':sum = 100;break;
        case 'L':sum = 50;break;
        case 'X':sum = 10;break;
        case 'V':sum = 5;break;
        case 'I':sum = 1;break;
    }
    return sum;
}

int chkRoman(char *p)
{
    for(int i=0;i<strlen(p);i++)
    {
        for(int j=0;j<strlen(chk);j++){
            if(p[i]==chk[j]) break;
            if(j==strlen(chk)-1) return 0;
        }
    }
    return 1;
}

int convertRoman(char *p)
{
    int sum=0;
    for(int i=0;i<strlen(p);i++)
    {
        for(int j=0;j<strlen(chk);j++)
        {
            if(p[i]==chk[j]){
                if(switchrm(p[i])>=switchrm(p[i+1])) 
                    sum+=switchrm(p[i]);
                else{
                    sum+=switchrm(p[i+1])-switchrm(p[i]);
                    i++;
                }
            }
        }
    }
    return sum;
}

int main()
{
    char rnum[14];
    printf("Enter Roman number : ");
    scanf("%s",rnum);
    if(chkRoman(rnum))
        printf("%s = %d",rnum,convertRoman(rnum));
    else
        printf("Error!! Roman number has incorrect character");
}