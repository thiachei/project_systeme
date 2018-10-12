#ifndef PROJECT_SYSTEME_LIBRARY_H
#define PROJECT_SYSTEME_LIBRARY_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NB_PLAYER 4
#define NB_HORSE_BY_PLAYER 4
#define NB_SQUARE_BOARD 80
#define NB_STAIRS_BY_PLAYER 6
#define NB_SQUARE_BY_PLAYER 14



//#############################
//--------- STRUCTURES --------
//#############################
typedef enum {false, true} bool;

typedef struct {
    int errCode;
    char *childFuncName;
    char *funcName;
    char msg[100];
}error_t;



typedef struct {
    int id_horse;
    int id_player;
} square_t;

/**
 * position = -1 -> stable
 * position = -2 -> end
 */
typedef struct {
    int id;
    int position;//useless now but compulsory not to have to store the all board
    //TODO : isStairsReady : bool to avoid the horse bumps back in the stairs begining
} horse_t;

typedef  struct {
    int id;
    char* name;
    horse_t stable[NB_HORSE_BY_PLAYER];
    int nb_coups;
    bool has_ended;
} player_t;

/**
 * board[0->55] -> race
 * board[56->61] -> stairs
 */
typedef struct {
    square_t board[NB_SQUARE_BOARD];
    player_t players[NB_PLAYER];
    bool has_ended;
} game_t;



int displayError(error_t* error);

void initPlayers(player_t *players);

int nextStair(int position, int stairsEntrancePosition, int firstStair);

int goToSquare (game_t *theGame, int idPlayer, int idHorse, int newPosition);

/**
 *
 * @param game
 * @param position
 * @param dice
 * @param stairsEntrancePosition
 * @return the next position
 */
int isThereObstacle(game_t *game, int position, int dice, int stairsEntrancePosition);

/**
 * initialyze the board (and the players for now
 * @param theGame
 * @return the id of the nest player
 */
int init (game_t* theGame);

/**
 * @return a pseudo-random number between 1 and 6
 */
int diceRoll();

/**
 * display the game board
 */
void display(game_t* board);

/**
 * display the stats of the specified player
 */
void diplayPlayer(player_t* player);

/**
 * playthe roll for the horse of the player.
 * @return the id of next player or -1 if end
 */
int play(game_t* theGame ,int idPlayer, int idHorse, int dice);

int test();

#endif