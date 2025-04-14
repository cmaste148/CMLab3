/*
Lab 3
Name: Cody Masterson
Date: 4/14/2024
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

    createDungeon(dungeon, TRAPS, GOLD, player);
    displayDungeon(dungeon);
    getMove(player, move);
    updateDungeon(dungeon, player, move);

    return 0;
}
