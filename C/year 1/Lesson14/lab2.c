#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char name[20];
    char sname[20];
    int age;
    char gender;
}person;

int n=5;

void print();
void findOldYoungPerson();
void gender();
void findPerson();
void printPerson();
void sort();
void memberinput();

int main()
{
    person member[5]={
        {"Herry","Potter",20,'M'},
        {"Ron","Wisley",21,'M'},
        {"John","Snow",35,'M'},
        {"Arya","Stark",15,'F'},
        {"Ariana","Grande",20,'F'}
    };
    char select[100];
    print(member);
    do{
        printf("Enter function (print,findage,gender,find,sort,input,exit) : ");
        scanf("%[^\n]",select);
        if(!strcmp(select,"exit")) break;
        if(!strcmp(select,"findage")) findOldYoungPerson(member);
        else if(!strcmp(select,"gender")) gender(member);
        else if(!strcmp(select,"print")) printPerson(member);
        else if(!strcmp(select,"find")) findPerson(member);
        else if(!strcmp(select,"sort")) sort(member);
        else if(!strcmp(select,"input")) memberinput();
        else printf("\nError Try again\n\n");
        fflush(stdin);
    }while(strcmp(select,"exit"));
    printf("End Program\n");
    return 0;
}

void print(person member[])
{
    for(int i=0;i<n;i++)
        printf("\nNo.%d\tname : %s %s\n\tage : %d  gender : %c\n",i+1,member[i].name,member[i].sname,member[i].age,member[i].gender);
    printf("\n");
    n = 5;
}

void printPerson(person member[])
{
    for(int i=0;i<n;i++)
        printf("\n\t%c. %s, %d year old.\n\tGender : %c\n",member[i].name[0],member[i].sname,member[i].age,member[i].gender);
    printf("\n");
    n = 5;
}

void findOldYoungPerson(person member[])
{
    person *p,*q;
    int max=0,min=member[0].age;
    for(int i=0;i<n;i++)
    {
        if(member[i].age>max){
            max = member[i].age;
            p = &member[i];
        }else if(member[i].age<min){
            min = member[i].age;
            q = &member[i];
        }
    }
    printf("\n");
    printf("Max = %s %s No.%d\n",p->name,p->sname,p->age);
    printf("Min = %s %s No.%d\n",q->name,q->sname,q->age);
    printf("\n");
}

void gender(person member[])
{
    int j=4;
    printf("\n");
    for(int k=1;k<=2;k++){
        if(k==1) printf("Female Male\n");
        else printf("Male\n");
        for(int i=0;i<5;i++)
        {
            if(member[i].gender=='F'&&k==1)
                printf("\tno.%d %s %s %c\n",i+1,member[i].name,member[i].sname,member[i].gender);
            else if(member[i].gender=='M'&&k!=1)
                printf("\tno.%d %s %s %c\n",i+1,member[i].name,member[i].sname,member[i].gender);
        }
    }
    printf("\n");
}

void findPerson(person member[])
{
    char input[20];
    printf("\n");
    fflush(stdin);
    printf("Enter searched name/surname : ");
    scanf("%[^\n]",input);
    input[0]=toupper(input[0]);
    for(int i=0;i<n;i++)
    {
        if(!strcmp(input,member[i].name)||!strcmp(input,member[i].sname)){
            printf("\nSearched name matches person No.%d\n%s %s\n",i+1,member[i].name,member[i].sname);
            break;
        }else if(i==4)
            printf("\nNot found person with the\nsearched name/surname\n");
    }
    printf("\n");
}

void sort(person member[])
{
    printf("\n");
    fflush(stdin);
    char input[20];
    char temp[20];
    int tempint;
    do{
    printf("Sort (name/sname/age/exit) : ");
    scanf("%s",input);
    if(!strcmp(input,"exit")) break;
    else if(!strcmp(input,"name")||!strcmp(input,"sname")||!strcmp(input,"age")){
        for(int i=0;i<n;i++)
        {
            for(int j=1+i;j<n;j++)
            {
                if(!strcmp(input,"age")){
                    if(member[i].age>member[j].age){
                        tempint = member[i].age;
                        member[j].age=member[i].age;
                        member[i].age=tempint;
                    }
                }
                else if(!strcmp(input,"name")){
                    if(member[i].name[0]>member[j].name[0]){
                        strcpy(temp,member[j].name);
                        strcpy(member[j].name,member[i].name);
                        strcpy(member[i].name,temp);
                    }
                }else{
                    if(member[i].sname[0]>member[j].sname[0]){
                        strcpy(temp,member[j].sname);
                        strcpy(member[j].sname,member[i].sname);
                        strcpy(member[i].sname,temp);
                    }
                }
            }
            if(!strcmp(input,"age"))
                printf("%d\n",member[i].age);
            else if(!strcmp(input,"name"))
                printf("%s\n",member[i].name);
            else
                printf("%s\n",member[i].sname);
        }
    }
    else printf("Error try again\n");
    }while(strcmp(input,"exit"));
    printf("End sort\n");
    printf("\n");
}

void memberinput()
{
    printf("How many member : ");
    scanf("%d",&n);
    person pinput[n];
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("No.%d name : ",i+1); scanf("%s",pinput[i].name);
        printf("sname : "); scanf("%s",pinput[i].sname);
        printf("age : "); scanf("%d",&pinput[i].age);
        fflush(stdin);
        printf("gender (M,F): "); scanf("%c",&pinput[i].gender);
    }
    printf("\n");
    print(pinput);
}
