#include "player.h"


player_t* initPlayer(player_t* newPlayer){
    printf("\nHi there new player\nWhat is you name ? : \n");
    scanf("%s",newPlayer->name);
    int j;
    newPlayer->has_ended = false;
    newPlayer->id = -1;
    newPlayer->nb_coups=0;
    for (j = 0; j < NB_HORSE_BY_PLAYER; ++j) {
        newPlayer->stable[j].id = j;
        newPlayer->stable[j].position = -1;
    }

    return newPlayer;
}