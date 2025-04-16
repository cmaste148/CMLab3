/*
Lab 3
Name: Cody Masterson
Date: 4/16/2024
IDE: Clion
Version: 1.0
Description: Dungeon crawl game using a 2-dimension array
*/

#include <iostream>
#include "CMLab3.hpp"

int main()
{
    char dungeon[MAX_SIZE][MAX_SIZE];
    int player[2];
    int move[2];
    bool exited;
    do
    {
        createDungeon(dungeon, TRAPS, GOLD, player);
        do
        {
            displayDungeon(dungeon);
            getMove(player, move);
            if (checkMove(dungeon, move, 'G'))
            {
                updateDungeon(dungeon, player, move);
                std::cout << "You got some gold" << std::endl;
                exited = false;
            }
            else if ( checkMove(dungeon, move, 'T'))
            {
                std::cout << "You have died in a trap" << std::endl;
                exited = true;
            }
            else if (checkMove(dungeon, move, 'E'))
            {
                std::cout << "You have success fully escaped the dungeon" << std::endl;
                exited = true;
            }
            else
            {
                updateDungeon(dungeon, player, move);
                exited = false;
            }

        } while(!exited);
    } while(playAgain());


    return 0;
}
