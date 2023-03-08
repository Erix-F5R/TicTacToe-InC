#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TicTacToe.h"


int main()
{
    char replay = 'r';
    Game new_game;

    while (replay == 'r')
    {

        init_game(&new_game);
        system("clear");
        printBoard(&new_game);

        // Game Engine
        int input_row;
        char input_col;

        while (check_win(&new_game) == 0)
        {

            //scanf is a bit delicate to bad inputs
            scanf("%d%c", &input_row, &input_col);
            place_mark(&new_game, input_row, input_col);
            system("clear");
            printBoard(&new_game);
        }

        system("clear");
        printBoard(&new_game);

        //Scanf is consuming the \n
        scanf(" %c", &replay);
    }

    return 0;
}