#include <stdio.h>

int main(){
    int row,col;
    scanf("%d %d",&row,&col);
    char m[row][col+1];
    for(int y=0;y<row;y++)
        gets(m[y]);
    
    for(int y=0;y<row-1;y++)
    {
        for(int x=0;x<col;x++)
        {
            if(y==0){
                continue;
            }else if(m[y][x]=='.' && m[y-1][x]=='#'){
                m[y][x]='_';
            }
        }
    }

    for(int y=0;y<=row;y++)
        printf("%s\n",m[y]);
}