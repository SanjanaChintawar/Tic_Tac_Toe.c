#include <stdio.h>

void board();
int winner();
void system();

char boardxo[]={'0','1','2','3','4','5','6','7','8','9'};

void main(){
    int player=1,input,status=-1;
    board();
   

    while (status==-1)
    {
        player=(player%2==0) ? 2 : 1;
        char mark=(player==1) ? 'X' :'O';
        printf("Player 1 = X \t Player 2 = O\n");
        printf("Enter Number For Player %d :\n",player);
        scanf("%d",&input);
    if(input<1 || input>9){
        printf("invalid input");
    }

    boardxo[input]=mark;
    board();

    int check=winner();

    if(check==1){
        printf("Player %d Won....!!!!",player);
        printf("\nThanks For Playing");
        return;
    }else if(check==0){
        printf("draw");
        return;
    }

    player++;
    }
    
    
}

void board(){
    system("cls");
    printf("\n\n");
    printf("Welcome To Tic Tac Toe\n\n");
    printf("|      |     |      |\n");
    printf("|   %c  |  %c  |  %c   |\n",boardxo[1],boardxo[2],boardxo[3]);
    printf("| _____|_____|_____ |\n");
    printf("|      |     |      |\n");
    printf("|   %c  |  %c  |  %c   |\n",boardxo[4],boardxo[5],boardxo[6]);
    printf("| _____|_____|_____ |\n");
    printf("|      |     |      |\n");
    printf("|   %c  |  %c  |  %c   |\n",boardxo[7],boardxo[8],boardxo[9]);
    printf("|      |     |      |\n");
    printf("\n\n");
}


int winner(){

    if(boardxo[1]==boardxo[2] && boardxo[2]==boardxo[3]){
        return 1;
    }
    if(boardxo[1]==boardxo[4] && boardxo[4]==boardxo[7]){
        return 1;
    }
    if(boardxo[7]==boardxo[8] && boardxo[8]==boardxo[9]){
        return 1;
    }
    if(boardxo[3]==boardxo[6] && boardxo[6]==boardxo[9]){
        return 1;
    }
    if(boardxo[1]==boardxo[5] && boardxo[5]==boardxo[9]){
        return 1;
    }
    if(boardxo[3]==boardxo[5] && boardxo[5]==boardxo[7]){
        return 1;
    }
    if(boardxo[2]==boardxo[5] && boardxo[5]==boardxo[8]){
        return 1;
    }
    if(boardxo[4]==boardxo[5] && boardxo[5]==boardxo[6]){
        return 1;
    }

    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(boardxo[i]=='X' || boardxo[i]=='O'){
            count++;
        }
    }
    
    if(count==9){
        return 0;
    }
    return -1;
}