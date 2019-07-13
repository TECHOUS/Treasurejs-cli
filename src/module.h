#include "main.h"

void Main();
void printCliToken();

int countArguments(char*);

char** parseArguments(char*,int);
void handleCommands(char**,int);

void oneLengthCommand(char**);
void twoLengthCommand(char**);
void threeLengthCommand(char**);

void handleTreasureCommand(int,char**);
void handleTreasureOption(int,char**);
void handleSingleHypenOption(int,char**);
void handleDoubleHypenOption(int,char**);

// COMMANDS
void clearCommand();
void exitCommand();
void showAllCommands();

void treasureInitCommand();
void treasureRemoveCommand();
void treasureHistoryCommand();
void treasureListCommand();