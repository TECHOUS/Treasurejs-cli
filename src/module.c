#include "module.h"

/**
 * function is the brain for this cli
 **/
void Main()
{
    welcomeMessage();
    while(true)
    {
        printCliToken();                                    // prints the default character for the shell

        char clistring[100];
        scanf("%[^\t\n]s", clistring);                      // get a command string
        while(getchar()!='\n');

        int argc = countArguments(clistring);               // count the total arguments in the entered command
        char **arguments = parseArguments(clistring,argc);  // parse the command into arguments array

        handleCommands(arguments,argc);                     // handles the command action
    }
}

void welcomeMessage(){
    printf("%s",BDCYAN);
    printf("  __________    __________    __________     __________     __________     ___    ___    __________    __________     \n");
    printf(" /___   ___/|  /  ____   /|  / ________/|   /  ____   /|   /  _______/|   /  /   /  /|  /  ____   /|  / ________/|    \n");
    printf(" |__/  / __|/ /  /___/  / / / /________|/  /  /   /  / /  /  /_______|/  /  /   /  / / /  /___/  / / / /________|/    \n");
    printf("   /  / /    /  ___   _/ / / _____/|      /  /___/  / /  /______   /|   /  /   /  / / /  ___   _/ / / _____/|         \n");
    printf("  /  / /    /  / \\ \\  \\_/ / /_____|/_    /  ____   / /  _|_____/  / /  /  /___/  / / /  / \\ \\  \\_/ / /_____|/_  \n");
    printf(" /__/ /    /__/ / \\ \\__\\ /__________/|  /__/|  /__/ /  /_________/ /  /_________/ / /__/ / \\ \\__\\ /__________/| \n");
    printf(" |__|/     |__|/   \\|__| |__________|/  |__|/  |__|/   |_________|/   |_________|/  |__|/   \\|__| |__________|/     \n");
    printf("\n");

    printf("\t\t\t       __________      ___           ____________  \n");
    printf("\t\t\t      /  _______/|    /  /|         /____   ____/| \n");
    printf("\t\t\t     /  / ______|/   /  / /         |___/  / ___|/ \n");
    printf("\t\t\t    /  / /          /  / /             /  / /      \n");
    printf("\t\t\t   /  /_/_____     /  /_/_____    ____/  /_/_      \n");
    printf("\t\t\t  /__________/|   /__________/|  /__________/|     \n");
    printf("\t\t\t  |__________|/   |__________|/  |__________|/     \n");

    printf("%s\n", RESET);
}

/**
 * function prints the cli default token for the shell
 **/
void printCliToken()
{
    printf("%s%s %s", $TCOLOR ,$TCLI, RESET);
}

/**
 * function to count arguments in the input string
 * 
 * @param clistring input string
 * 
 * @return argument count
 **/
int countArguments(char* clistring)
{
    bool parseFlag = false;
    register int i=0;
    int argc = 0;
    while(clistring[i]!='\0')                                           // traversing and counting the arguments
    {
        if(clistring[i]==' ' || clistring[i]=='\n')
        {
            if(parseFlag)
            {
                parseFlag=false;
                argc++;
            }
        }
        else
        {
            if(!parseFlag)
            {
                parseFlag=true;
            }
        }
        i++;
    }
    argc++;
    return argc;
}

/**
 * function to parse arguments
 * @param clistring input string
 * @return string array
 **/
char** parseArguments(char* clistring, int argc)
{            
    bool parseflag=false;                                                   // flag for parsing the string
    register int i=0,j=0,k=0;                                               // register values for looping
    char copy[30];                                                          // string needed for parsing
    char **argv = (char**)malloc(sizeof(char *)*argc);                      // storing the arguments

    while(i<(strlen(clistring)+1))                                          // string parsing anf storing
    {
        if(clistring[i]==' ' || clistring[i]=='\n' || clistring[i]=='\0')   // if character found while parsing
        {
            if(parseflag)                                                   // if flag is true change to false as string gets end
            {
                parseflag=false;
                copy[j]='\0';

                int len = strlen(copy);
                //allocating memory
                argv[k] = (char*)malloc(sizeof(char)*(len+1));
                strcpy(argv[k],copy);

                k++;
                j=0;
            }
        }
        else                                                                // if other char found
        {
            if(!parseflag)                                                  // if flag gets false then change to true
            {
                parseflag=true;
            }
            copy[j] = clistring[i];                                         // storing the characters
            j++;
        }
        i++;
    }
    return argv;
}

/**
 * handles the commands according to the count of the arguments
 * 
 * @param arguments array
 * @param argc for argument count
 **/
void handleCommands(char** arguments,int argc)
{
    switch(argc)
    {
        case 0:
            return;
        case 1:
            oneLengthCommand(arguments);
            break;
        case 2:
            twoLengthCommand(arguments);
            break;
        // case 3:
        //     threeLengthCommand(arguments);
        //     break;
        default:
            for(register int i=0;i<argc;i++)
            {
                printf("%s ",arguments[i]);
            }
            defaultOutput("");
    }
}

/**
 * show default output for the incorrect command
 **/
void defaultOutput(char* command)
{
    printf("%s: command not found\n",command);
    printf("use: help for using other commands\n");
}