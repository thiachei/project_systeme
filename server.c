#include <stdio.h>
#include "library.h"


int main(int argc, char* argv[]) {

    int i, roll, nextPlayer = 0, input;

    game_t theGame;
    nextPlayer = init(&theGame);

    if (test()!=0)return 0;

    do{
        display(&theGame);
        printf("%s : ",theGame.players[nextPlayer].name);
        roll = diceRoll();
        printf(" Roll : %d\nChoose the horse : ",roll);

        scanf("%d",&input);

        //diplayPlayer(theGame.players);

    }while((nextPlayer = play(&theGame, nextPlayer, input, roll))!= -1);

    display(&theGame);

    return 0;
}