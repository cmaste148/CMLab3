//
// Created by L00711689 on 4/14/2025.
//

#ifndef CMLAB3_HPP
#define CMLAB3_HPP

#include <string>

// Constants
const int MAX_SIZE = 8;
const int TRAPS = 3;
const int GOLD = 2;

// Required Functions
void createDungeon(char[][MAX_SIZE], int, int, int[]);
void displayDungeon(const char[][MAX_SIZE]);
void getMove(const int[], int[]);
bool checkMove(const char[][MAX_SIZE], int[], char);
void updateDungeon(char[][MAX_SIZE], const int[], const int[]);
bool playAgain();

// General Functions
int getNumber(std::string, int, int);
bool yesNo(std::string);
int randRange(int, int);

#endif //CMLAB3_HPP
