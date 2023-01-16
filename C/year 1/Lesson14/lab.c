#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Hex[]="0123456789ABCDEF";

void Acronym1(char *s)
{
    char *p,temp[30];
    p = strstr(s," ");
    while(p)
    {
        strcpy(temp,p+1);
        strcpy(p,"");
        printf("%s\n",s);
        strcpy(s,temp);
        p = strstr(s," ");
        if(!p)
            printf("%s\n",s);
    }
}

void num1()
{
    char uname[30];
    printf("Enter uname : ");
    scanf("%[^\n]s",uname);
    Acronym1(uname);
}

int check(char *w)
{
    char sq[10][5]={"i","of","the","on","at","for","with","a","an","in"};
    for(int i=0;i<10;i++)
    {
        if(!strcmp(w,sq[i]))
            return 0;
    }
    return 1;
}

void Acronym2(char *s)
{
    char *p;
    p = strtok(s," ");
    while(p)
    {
        if(check(p)) printf("%c",toupper(p[0]));
        p = strtok(NULL," ");
    }
}


void num2()
{
    char uname[100];
    printf("Enter sentence : ");
    scanf("%[^\n]s",uname);
    Acronym2(uname);
}

int power(int num,int n)
{
    int sum=1;
    for(int i=1;i<=n;i++)
        sum*=num;
    return sum;
}

int isHexa(char *s)
{
    for(int i=0;i<strlen(s);i++)
    {
        for(int j=0;j<strlen(Hex);j++)
        {
            if(toupper(s[i])==Hex[j])break;
            if(j==strlen(Hex)-1)return 0;
        }
    }
    return 1;
}

void Hex2Dec(char *w)
{
    int sum=0;
    for(int i=0;i<strlen(w);i++)
    {
        for(int j=0;j<strlen(Hex);j++)
        {
            if(toupper(w[i])==Hex[j])
                sum+=j*power(16,strlen(w)-i-1);
        }
    }
    printf("%d",sum);
}

void num3()
{
    char w[16];
    printf("Enter word : ");
    scanf("%s",w);
    if(isHexa(w))
        Hex2Dec(w);
    else
        printf("Not a Hexa number");

}


int main()
{
    // num1();
    // num2();
    num3();
}