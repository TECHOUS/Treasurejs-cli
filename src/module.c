#include "module.h"

/**
 * main function for cli
 **/
void Main()
{
    while(true)
    {
        printCliToken();

        char clistring[100];
        scanf("%[^\t\n]s",clistring);
        while(getchar()!='\n');

        int argc = countArguments(clistring);
        char **arguments = parseArguments(clistring,argc);

        handleCommands(arguments,argc);
    }
}

/**
 * function for printing the cli token
 **/
void printCliToken()
{
    const char CLI[2] = "#";
    printf("%s ",CLI);
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
char** parseArguments(char* clistring,int argc)
{            
    bool parseflag=false;                                               // flag for parsing the string
    register int i=0,j=0,k=0;                                           // register values for looping
    char copy[30];                                                      // string needed for parsing
    char **argv = (char**)malloc(sizeof(char *)*argc);                  // storing the arguments

    while(i<(strlen(clistring)+1))                                           // string parsing anf storing
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
        else                                                            // if other char found
        {
            if(!parseflag)                                              // if flag gets false then change to true
            {
                parseflag=true;
            }
            copy[j] = clistring[i];                                     // storing the characters
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
            printf(": command not found\nUse command: treasure for getting the list of available commands\n");
    }
}