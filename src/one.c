#include "one.h"

/**
 * ONE LENGTH COMMANDS
 * - clear
 * - exit
 * - treasure
 * - help
 * - ls
 * - cd
 * - pwd
 **/
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
            handleSecondCharForC(arguments[ARG_INDEX]);
            break;
        case 'e':
            strcmp(arguments[ARG_INDEX],"exit")==0 ? exitCommand() : defaultOutput(arguments[ARG_INDEX]);
            break;
        case 'l':
            strcmp(arguments[ARG_INDEX],"ls")==0 ? lsCommand() : defaultOutput(arguments[ARG_INDEX]) ;
            break;
        case 'p':
            strcmp(arguments[ARG_INDEX],"pwd")==0 ? pwdCommand() : defaultOutput(arguments[ARG_INDEX]) ;
            break;
        case 't':
            strcmp(arguments[ARG_INDEX],"treasure")==0 ? treasurecliInfo() : defaultOutput(arguments[ARG_INDEX]);
            break;
        case 'h':
            strcmp(arguments[ARG_INDEX],"help")==0 ? showAllCommands() : defaultOutput(arguments[ARG_INDEX]);
            break;
        default:
            defaultOutput(arguments[ARG_INDEX]);
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
 * shows all the files in the folder
 **/
void lsCommand()
{
    system("ls");
}

/**
 * remove back to root directory
 **/
void cdCommand(){
    system("cd");
}

/**
 * shows the current working directory
 **/
void pwdCommand(){
    system("pwd");
}

/**
 * show the treasure info
 **/
void treasurecliInfo()
{
    printf("\nTREASURE CLI\n");
    printf("A Wikipedia for JavaScript where to can get JavaScript:\n");
    printf("*\tFree Courses links which are absolutely free for everyone.\n");
    printf("*\tFrameworks list\n");
    printf("*\tLibraries list\n");
    printf("*\tTools list\n");
    printf("*\tExtensions\n\n");
}

/**
 * display treasure cli syntax
 **/
void treasurecliSyntax()
{
    printf("SYNTAX\n");
    printf("[OTHER]\n");
    printf("treasure [OPTION]\n");
    printf("treasure [COMMAND]\n");
    printf("treasure [OPTION] [SUBOPTION]\n");
    printf("\n");
}

/**
 * display treasure cli commands
 **/
void treasurecliCommand()
{
    printf("COMMAND\n");
    printf("\tinit\n");
    printf("\tremove\n");
    printf("\thistory\n");
    printf("\tlist\n");
    printf("\n");
}

/**
 * display treasure cli option
 **/
void treasurecliOption()
{
    printf("OPTION\n");
    printf("\t-h , --help\n");
    printf("\t-v , --current-version\n");
    printf("\n");
}

void treasurecliSubOption()
{
    printf("SUB OPTION\n");
    printf("OPTION: --help\n");
    printf("\t-i , --info\t\tshow treasure suboptions\n");
    printf("\t-s , --syntax\t\tshow treasure syntax\n");
    printf("\t-c , --command\t\tshow treasure commands\n");
    printf("\t-o , --option\t\tshow treasure options\n");
    printf("\t-O , --other\t\tshow other commands\n");
    printf("\t-so , --suboption\tshow all sub options\n");
    printf("\n");
}

/**
 * display treasure cli other
 **/
void treasurecliOther()
{
    printf("OTHER\n");
    printf("\thelp\n");
    printf("\ttreasure\n");
    printf("\tclear\n");
    printf("\texit\n");
    printf("\tls\n");
    printf("\tcd\n");
    printf("\tpwd\n");
    printf("\n");
}

/**
 * show all commands
 **/
void showAllCommands()
{
    treasurecliInfo();
    treasurecliSyntax();
    treasurecliCommand();
    treasurecliOption();
    treasurecliSubOption(); 
    treasurecliOther();   
}


/**
 * this function handles the command:
 *      - d
 * c
 *      - lear
 **/
void handleSecondCharForC(char* command){
    char secondChar = command[1];
    switch(secondChar){
        case 'd':
            strcmp(command,"cd")==0 ? cdCommand() : defaultOutput(command);
            break;
        case 'l':
            strcmp(command,"clear")==0 ? clearCommand() : defaultOutput(command);
            break;
        default:
            defaultOutput(command);
            break;
    }
}