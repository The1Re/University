#include <stdio.h>

int row,col;

void makeboard();
void changeboard();
void printboard();
void correctline();
void iscorrectline();

int main()
{
    int input;
    printf("Enter rows and colunm : ");
    scanf("%d %d",&row,&col);
    char m[row][col];
    makeboard(m);
    while(1)
    {
        printf("Enter the column : ");
        scanf("%d",&input);
        if(input<0||input>col-2){
            printf("Enter the column (0-%d) : ",col-2);
            scanf("%d",&input);
        }
        if(m[0][input]=='x'||m[0][input+1]=='x') break;
        changeboard(m,input);
        iscorrectline(m);
        printboard(m);
    }
    printf("Game end >> cannot input in %d\n",input);    
}

void makeboard(char m[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            m[i][j]='_';
    }
    return ;
}

void printboard(char m[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            printf("%c",m[i][j]);
        printf("\n");
    }
    return ;
}

void changeboard(char m[row][col],int x)
{
    for(int y=1;y<row;y++)
    {
        if(y==row-1){
            m[y][x]='x';
            m[y][x+1]='x';
            m[y-1][x]='x';
            m[y-1][x+1]='x';
        }else{
            if(m[y+1][x]=='x'||m[y+1][x+1]=='x')
            {
                m[y][x]='x';
                m[y][x+1]='x';
                m[y-1][x]='x';
                m[y-1][x+1]='x';
                break;
            }
        }
    }
    return ;
}

void correctline(char m[row][col],int start)
{
    for(int y=start+1;y>=0;y--)
    {
        for(int x=0;x<col;x++)
        {
            if(y>=2)
                m[y][x]=m[y-2][x];
            else
                m[y][x]='_';
        }
    }
    return ;
}

void iscorrectline(char m[row][col])
{
    int check=0;
    for(int y=row-1;y>=0;y--)
    {
        for(int x=0;x<col;x++)
        {
            if(m[y][x]=='_'){
                check=0;   
                break;
            }
            else if(x==col-1){
                check++;
            }
        }
        if(check==2){
            correctline(m,y);
            break;
        }
    }
    return ;
}