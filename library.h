#ifndef PROJECT_SYSTEME_LIBRARY_H
#define PROJECT_SYSTEME_LIBRARY_H

typedef enum {false, true} bool;

typedef struct {
    int id_horse;
    int id_player;
} square_t;

typedef struct {
    int id;
    int position;
} horse_t;

typedef  struct {
    int id;
    char name[10];
    horse_t stable[4];
    int nb_coups;
    bool has_ended;
} player_t;

/**
 * board[0] -> stable
 * board[1->56] -> race
 * board[57->62] -> stairs
 */
typedef struct {
    square_t plateau[63]
} plateau_t;

/**
 * @return a pseudo-random number between 1 and 6
 */
int diceRoll();

/**
 * display the game board
 */
void display();

/**
 * display the stats of the specified player
 */
void diplay player(int idPlayer);

/**
 * move the horse of the player of number rolled
 */
int move(idPlayer, idhorse, dice);

#endif