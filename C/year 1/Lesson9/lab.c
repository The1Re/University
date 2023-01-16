#include <stdio.h>
#include <string.h>


int main()
{   char msg[300],temp[300];
    char *p; 
    printf("Enter sentence : ");
    scanf("%[^\n]s",msg);
    p = strstr(msg,"happy");
    while(p)
    {
        strcpy(temp,p+5);
        strcpy(p+5," :)");
        strcat(msg,temp);
        p++;
        p = strstr(p,"happy");
    }
    printf("%s",msg);
}