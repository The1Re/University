#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *repeat(char *dest,char *cha,int size)
{
    *dest = '\0';
    for(int i=0;i<size;i++)
        strcat(dest,cha);
    return dest;
}

int main()
{
    int f[26]={0};
    char c,cha[2]="";
    char dest[100]="";
    printf("F = "); 
    scanf("%s",cha);
    fflush(stdin);
    FILE *data = fopen("book.txt","r");
    while((c = fgetc(data))!=EOF)
    {
        if(isalpha(c))
            f[toupper(c)-'A']++;
    }

    for(int i=0;i<26;i++)
        if(f[i]!=0)
            printf("%c = %d\t| %s\n",'A'+i,f[i],repeat(dest,cha,f[i]));
}