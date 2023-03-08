#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TicTacToe.h"

char XorO[2] = {'X', 'O'};

int init_game(Game *game)
{

    game->turn = 0;
    game->winner = ' ';

    for (int i = 0; i < 9; i++)
    {

        game->board[i] = ' ';
    }

    return 0;
}

int printBoard(Game *game)
{

    char *header = " \n\n\txoxoxoxoxoxoxoxoxoxoxoxo\n\toxoxox TIC TAC TOE xoxox\n\txoxoxoxoxoxoxoxoxoxoxoxo\n\n\tTo exit game press CTRL-C\n\n";
    char *whos_turn = "\tCurrently Player %c's turn\n\tEnter your next move's coordinate( ex. 1a):\n\n";

    char *declare_winner = "\tGAME OVER - Player %c has won!\n\tTo replay enter r\n\tTo quit enter q\n\n";
    char *declare_tie = "\tGAME OVER - Tie Game\n\tTo play again enter: r\n\n";

    char *board_template[9] = {"\t  :    |   |\n\t 1:  %c",
                               " | %c",
                               " | %c",
                               "\n\t..: ___|___|___\n\t  :    |   |\n\t 2:  %c",
                               " | %c",
                               " | %c",
                               "\n\t..: ___|___|___\n\t  :    |   |\n\t 3:  %c",
                               " | %c",
                               " | %c\n\t  :    |   |\n\t  :............\n\t     a : b : c\n"};

    printf("%s", header);
    if (game->winner == ' ')
    {
        printf(whos_turn, XorO[game->turn % 2]);
    }
    else if (game->winner == 'T')
    {
        printf("%s", declare_tie);
    }
    else
    {
        printf(declare_winner, game->winner);
    }

    for (int i = 0; i < 9; i++)
    {
        printf(board_template[i], game->board[i]);
    }

    return 0;
}

int place_mark(Game *game, int row, char col)
{

    int index = 0;

    // rows are  0, 3 ,6
    // cols are 0, 1 , 2
    int r = (row - 1) * 3;
    int c = tolower(col) - 97;
    
    index = r + c;

    //Bad input handling
    if(row < 1|| row > 3){
        return 1;
    }

    if(tolower(col) < 97 || tolower(col) > 99 ){
        return 1;
    }

    // Check if index is full
    if (game->board[index] != ' ')
    {
        return 1;
    }



    // Update board with X or O, then incr turn
    game->board[index] = XorO[game->turn % 2];
    game->turn++;

    return 0;
}

int check_win(Game *game)
{

    // Check if turn == max spaces in board
    if (game->turn == 9)
    {
        game->winner = 'T';
        return 1;
    }

    // Row Win
    for (int r = 0; r < 9; r += 3)
    {

        if (game->board[r] != ' ' && game->board[r] == game->board[r + 1] && game->board[r] == game->board[r + 2])
        {
            game->winner = XorO[(game->turn - 1) % 2];
            return 1;
        }
    }

    // Col Win
    for (int c = 0; c < 3; c++)
    {

        if (game->board[c] != ' ' && game->board[c] == game->board[c + 3] && game->board[c] == game->board[c + 6])
        {
            game->winner = XorO[(game->turn - 1) % 2];
            return 1;
        }
    }

    // Diagonal Win
    // Check 4 first
    if (game->board[4] != ' ' && game->board[0] == game->board[4] && game->board[0] == game->board[8])
    {
        game->winner = XorO[(game->turn - 1) % 2];
        return 1;
    }
    else if (game->board[4] != ' ' && game->board[2] == game->board[4] && game->board[2] == game->board[6])
    {
        game->winner = XorO[(game->turn - 1) % 2];
        return 1;
    }

    return 0;
}
