#ifndef TicTacToe_h
#define TicTacToe_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*Holds the game board 3x3 as an array[9] 
along with keeping track of whos turn, and the winner*/
struct game
{
    char board[9];
    int turn;
    char winner;
};

typedef struct game Game;

/*Fills the board with blanks, sets the turn to 0 and the winner to blank*/
int init_game(Game *game);

int printBoard(Game *game);

int place_mark(Game *game, int row, char col);

int check_win(Game *game);

#endif