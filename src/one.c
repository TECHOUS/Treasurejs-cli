#include "one.h"

/**
 * handles single length commands
 * 
 * @param arguments
 **/
void oneLengthCommand(char** arguments)
{
    const int ARG_INDEX = 0;
    char firstChar = arguments[ARG_INDEX][0];
    
    switch (firstChar)
    {
        case 'c':
            if(strcmp(arguments[ARG_INDEX],"clear")==0)
            {
                clearCommand();
            }
            else
            {
                
            }
            break;
        case 'e':
            if(strcmp(arguments[ARG_INDEX],"exit")==0)
            {
                exitCommand();
            }
            else
            {

            }
            break;
        case 't':
            if(strcmp(arguments[ARG_INDEX],"treasure")==0)
            {
                showAllCommands();
            }
            else
            {

            }
            break;
        case 'h':
            if(strcmp(arguments[ARG_INDEX],"help")==0)
            {
                showAllCommands();
            }
            else
            {

            }
            break;
        default:
            printf("%s: command not found\nuse: help\n",arguments[ARG_INDEX]);
            break;
    }
}

/**
 * clears the terminal
 **/
void clearCommand()
{
    system("clear");
}

/**
 * exits the application
 **/
void exitCommand()
{
    exit(0);
}

/**
 * show all commands
 **/
void showAllCommands()
{
    printf("\nTREASURE CLI\n");
    printf("A Wikipedia for JavaScript where to can get JavaScript:\n");
    printf("*\tFree Courses links which are absolutely free for everyone.\n");
    printf("*\tFrameworks list\n");
    printf("*\tLibraries list\n");
    printf("*\tTools list\n");
    printf("*\tExtensions\n\n");

    printf("SYNTAX\n");
    printf("treasure [OPTION]\n");
    printf("treasure [COMMAND]\n\n");
    printf("COMMAND\n");
    printf("\tinit\n");
    printf("\tremove\n");
    printf("\thistory\n");

    printf("\n");
    
    printf("OPTION\n");
    printf("\t--help\n");

    printf("\n");

    printf("OTHER\n");
    printf("\tclear\n");
    printf("\texit\n");
    
    printf("\n");
}