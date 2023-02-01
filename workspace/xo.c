#include <stdio.h>
#include <stdbool.h>
#define line "---+---+---"

const char player1 = 'x',player2 = 'o';

char board[] = {
    '1','2','3',
    '4','5','6',
    '7','8','9'
};

void showboard();
void changeboard();
bool checkboard();
bool checkwinner();

int main(void)
{
    int get;
    int turnplayer = 0;
    while(true)
    {
        showboard();
        checkwinner();
        turnplayer = turnplayer%2+1;
        printf("Player%d. please enter your go %c : ",turnplayer,turnplayer == 1 ? player1 : player2);
        scanf("%d",&get);

    }    
    return 0;
}

void showboard()
{
    printf("\n");
    for(int i=0;i<9;i+=3)
    {
        printf(" %c | %c | %c \n",board[i],board[i+1],board[i+2]);
        if(i<6) printf("%s\n",line);
    }
    printf("\n");
}

bool checkwinner()
{
    for(int i=0;i<9;i+=3)   //check liner
    {
        if(board[i]==board[i+1]&&board[i]==board[i+2])
            return true;
    }
    for(int i=0;i<3;i++)    //check horizol
    {
        if(board[i]==board[i+3]&&board[i]==board[i+6])
            return true;
    }
    
}

bool checkboard(int get)
{
    if(board[get-1] == 'x' || board[get-1] == 'o')
        return false;
    return true;
}

void changeboard(int get)
{

}