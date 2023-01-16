#include <stdio.h>
#include <string.h>

const char files[]="abcdefgh";
const char ranks[]="87654321";

typedef struct{
    char file;
    char rank;
}pos;

int king(int currentnum[],int nextnum[])
{
    for(int y=0;y<8;y++)
    {
        if(currentnum[1]==y)
        {
            if(nextnum[1]==y||nextnum[1]==y+1||nextnum[1]==y-1)
            {
                for(int x=0;x<8;x++)
                {
                    if(currentnum[0]==x)
                    {
                        if(nextnum[0]==x||nextnum[0]==x+1||nextnum[0]==x-1)
                            return 1;
                    }
                }
            }
        }
    }
    return 0;
}


int rook(int currentnum[],int nextnum[])
{
    for(int y=0;y<8;y++)
    {
        if(currentnum[1]-y==nextnum[1]||currentnum[1]+y==nextnum[1])
        {
            for(int x=0;x<8;x++)
            {
                if(currentnum[0]-x==nextnum[0]||currentnum[1]+x==nextnum[1])
                    return 1;
            }
        }
    }
    return 0;
}

int bishop(int currentnum[],int nextnum[])
{
    //printf("c = %d %d n = %d %d\n",currentnum[1],currentnum[0],nextnum[1],nextnum[0]);
    for(int i=1;i<8;i++)
    {
        if(currentnum[1]-i==nextnum[1]&&currentnum[0]-i==nextnum[0])
            return 1;
        else if(currentnum[1]-i==nextnum[1]&&currentnum[0]+i==nextnum[0])
            return 1;
        else if(currentnum[1]+i==nextnum[1]&&currentnum[0]-i==nextnum[0])
            return 1;
        else if(currentnum[1]+i==nextnum[1]&&currentnum[0]+i==nextnum[0])
            return 1;
    }
    return 0;
}

int knight(int currentnum[],int nextnum[])
{
    for(int y=0;y<8;y++)
    {
        if(currentnum[1]==y)
        {
            if(nextnum[1]==y-1||nextnum[1]==y-2||nextnum[1]==y+1||nextnum[1]==y+2)
            {
                for(int x=0;x<8;x++)
                {
                    if(currentnum[0]==x)
                    {
                        if(nextnum[0]==x-1||nextnum[0]==x-2||nextnum[0]==x+1||nextnum[0]==x+2)
                            return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int pawn(int currentnum[],int nextnum[])
{
    if(currentnum[1]==6)
        if(currentnum[1]-2==nextnum[1]&&currentnum[0]==nextnum[0])
            return 1;
    else if(currentnum[1]-1==nextnum[1]&&currentnum[0]==nextnum[0])
        return 1;
    return 0;
}

int queen(int currentnum[],int nextnum[])
{
    if(king(currentnum,nextnum)||rook(currentnum,nextnum)||bishop(currentnum,nextnum))
        return 1;
    return 0;
}

void changepos(pos *currentpos,pos *nextpos,int currentnum[],int nextnum[])
{
    for(int i=0;i<8;i++)
    {
        if(currentpos->file==files[i])
            currentnum[0]=i;
        if(currentpos->rank==ranks[i])
            currentnum[1]=i;
        if(nextpos->file==files[i])
            nextnum[0]=i;
        if(nextpos->rank==ranks[i])
            nextnum[1]=i;
    }
}

int checkmove(char name[],pos *currentpos,pos *nextpos)
{
    char character[6][10]={"king","queen","rook","bishop","knight","pawn"};
    int currentnum[2],nextnum[2];
    int ans=0;
    changepos(currentpos,nextpos,currentnum,nextnum);
    for(int i=0;i<6;i++)
    {
        if(!strcmp(name,character[i]))
        {
            switch(i){
                case 0: ans = king(currentnum,nextnum);break;
                case 1: ans = queen(currentnum,nextnum);break;
                case 2: ans = rook(currentnum,nextnum);break;
                case 3: ans = bishop(currentnum,nextnum);break;
                case 4: ans = knight(currentnum,nextnum);break;
                case 5: ans = pawn(currentnum,nextnum);break;
            }
        }
    }
    return ans;
}


int main()
{
    char name[10];
    pos currentpos,nextpos;
    scanf("%s",name);
    fflush(stdin);
    scanf("%c %c",&currentpos.file,&currentpos.rank);
    fflush(stdin);
    scanf("%c %c",&nextpos.file,&nextpos.rank);
    fflush(stdin);
    if(checkmove(name,&currentpos,&nextpos))
        printf("%s moving to %c %c",name,nextpos.file,nextpos.rank);
    else   
        printf("%s cannot move from\n%c %c to %c %c",name,currentpos.file,currentpos.rank,nextpos.file,nextpos.rank);
    return 0;
}

