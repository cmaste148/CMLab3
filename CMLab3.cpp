//
// Created by L00711689 on 4/14/2025.
//

#include "CMLab3.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Required Functions

void createDungeon(char dungeon[][MAX_SIZE], int traps, int gold, int player[])
{

    // Create empty dungeon
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            dungeon[i][j] = '.';
        }
    }

    // Add traps
    for (int t = 0; t < TRAPS; t++)
    {
        int x = randRange(0, MAX_SIZE - 1);
        int y = randRange(0, MAX_SIZE - 1);

        if (dungeon[x][y] == '.')
        {
            dungeon[x][y] = 'T';
        }
        else
        {
            t--;
        }
    }

    // Add gold
    for (int g = 0; g < GOLD; g++)
    {
        int x = randRange(0, MAX_SIZE - 1);
        int y = randRange(0, MAX_SIZE - 1);

        if (dungeon[x][y] == '.')
        {
            dungeon[x][y] = 'G';
        }
        else
        {
            g--;
        }
    }

    // Add player
    bool placed;
    do
    {

        int x = randRange(0, MAX_SIZE - 1);
        int y = randRange(0, MAX_SIZE - 1);

        if (dungeon[x][y] == '.')
        {
            dungeon[x][y] = 'P';
            player[0] = x; player[1] = y;
            placed = true;
        }
        else
        {
            placed = false;
        }
    } while (!placed);

    // Add exit
    bool escape;
    do
    {

        int x = randRange(0, MAX_SIZE - 1);
        int y = randRange(0, MAX_SIZE - 1);

        if (dungeon[x][y] == '.')
        {
            dungeon[x][y] = 'E';
            escape = true;
        }
        else
        {
            escape = false;
        }
    } while (!escape);
}

void displayDungeon(const char dungeon[][MAX_SIZE])
{
    std::cout << "_|________|_" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << " |";
        for (int j = 0; j< MAX_SIZE; j++)
        {
            std::cout << dungeon[i][j];
        }
        std::cout << "|" <<std::endl;
    }
    std::cout << "_|________|_" << std::endl;
}

void getMove(const int player[], int move[])
{
    std::cout << "*WASD*" << std::endl;
    char input;
    bool moved;
    do
    {
        std::cin >> input;
        input = std::toupper(input);
        switch(input)
        {
            case 'W':
            {
                if (player[0] > 0)
                {
                    move[0] = player[0] - 1;
                    move[1] = player[1];
                    moved = true;
                }
                else
                {
                    std::cout << "Path is blocked" << std::endl;
                    moved = false;
                }
                break;
            }
            case 'A':
            {
                if (player[1] > 0)
                {
                    move[1] = player[1] - 1;
                    move[0] = player[0];
                    moved = true;
                }
                else
                {
                    std::cout << "Path is blocked" << std::endl;
                    moved = false;
                }
                break;
            }
            case 'S':
            {
                if (player[0] < MAX_SIZE - 1)
                {
                    move[0] = player[0] + 1;
                    move[1] = player[1];
                    moved = true;
                }
                else
                {
                    std::cout << "Path is blocked" << std::endl;
                    moved = false;
                }
                break;
            }
            case 'D':
            {
                if (player[1] < MAX_SIZE - 1)
                {
                    move[1] = player[1] + 1;
                    move[0] = player[0];
                    moved = true;
                }
                else
                {
                    std::cout << "Path is blocked" << std::endl;
                    moved = false;
                }
                break;
            }
            default:
            {
                std::cout << "Invalid Input" << std::endl;
                moved = false;
            }

        }

    } while (!moved);
}

bool checkMove(const char dungeon[][MAX_SIZE], const int move[], char item)
{
    if (dungeon[move[0]][move[1]] == item)
    {
        return true;
    }

    return false;
}

void updateDungeon(char dungeon[][MAX_SIZE], int oldPlayer[], const int newPLayer[])
{
    dungeon[oldPlayer[0]][oldPlayer[1]] = '.';
    dungeon[newPLayer[0]][newPLayer[1]] = 'P';
    oldPlayer[0] = newPLayer[0];
    oldPlayer[1] = newPLayer[1];
}

bool playAgain()
{
    return yesNo("Would you like to play again? (y/n): ");
}

// General Functions

int getNumber(std::string message, int min, int max)
{
    bool flag;
    int input;
    std::cout << message << std::endl;

    do
    {
        std::cin >> input;
        if (input >= min && input <= max && std::cin.fail() == false)
        {
            flag = false;
        }
        else
        {
            flag = true;
            std::cout << "Please try again" << std::endl;
        }

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

    } while (flag);
    return input;
}

bool yesNo(const std::string message)
{
    std::string answer;
    bool flag;
    bool again = false;
    std::cout << message << std::endl;
    do
    {
        std::cin >> answer;
        if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes")
        {
            flag = false;
            again = true;
        }
        else if (answer == "N" || answer == "n" || answer == "No" || answer == "no")
        {
            flag = false;
            again = false;
        }
        else
        {
            std::cout << "Not valid answer, please enter y or n: " << std::endl;
            flag = true;
        }
    } while (flag);
    return again;
}

int randRange(int min, int max)
{
    // Seed randNum
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    return rand() % (max - min + 1) + min;
}
