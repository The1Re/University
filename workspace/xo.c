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
bool checkfullboard();

int main(void)
{
    int get;
    int turnplayer = 0;
    while(true)
    {
        showboard();
        if(checkwinner() || checkfullboard()){
            checkwinner() ? printf("Player%d is winner!\n",turnplayer) : printf("This game draw"); 
            break;
        }
        turnplayer = turnplayer%2+1;
        do{
            printf("Player%d. please enter your go %c : ",turnplayer,turnplayer == 1 ? player1 : player2);
            scanf("%d",&get);
            if(checkboard(get)) printf("Error cannot choice %d try again!\n",get);
        }while(checkboard(get));
        changeboard(get,turnplayer);
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
    if(board[0]==board[4]&&board[0]==board[8])
        return true;
    else if(board[2]==board[4]&&board[2]==board[6])
        return true;
    else{
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
    return false;  //not have winner
}

bool checkfullboard()
{
    for(int i=0;i<9;i++)
    {
        if(board[i]!='x' && board[i]!='o')
            return false;
    }
    return true;
}

bool checkboard(int get)
{
    if(board[get-1] == 'x' || board[get-1] == 'o')
        return true;
    return false;
}

void changeboard(int get,int turnplayer)
{
    board[get-1] = turnplayer == 1 ? player1 : player2;
}