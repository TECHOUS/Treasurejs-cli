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

/**
 * handles two string commands
 * 
 * @param arguments array
 **/
void twoLengthCommand(char** arguments)
{
    const int ARG_INDEX_0 = 0;
    const int ARG_INDEX_1 = 1;

    if(strcmp(arguments[ARG_INDEX_0],"treasure")==0)
    {
        if(arguments[ARG_INDEX_1][0] == '-')            // option found
        {
            handleTreasureOption(1,arguments);
        }
        else                                            // command found
        {
            handleTreasureCommand(1,arguments);
        }
    }
    else
    {
        printf("%s: command not found\nuse: help\n",arguments[ARG_INDEX_0]);
    }
}

/**
 * handles the commands starting with treasure
 * 
 * COMMANDS:
 * treasure init
 * treasure remove 
 * treasure history
 * treasure list
 **/
void handleTreasureCommand(int index,char** arguments)
{
    char firstChar = arguments[index][0];
    switch(firstChar)
    {
        case 'i':
            if(strcmp(arguments[index],"init")==0)
            {
                treasureInitCommand();
            }
            else
            {
                printf("%s: command not found\nuse: help\n",arguments[index]);
            }
            break;
        case 'r':
            if(strcmp(arguments[index],"remove")==0)
            {
                treasureRemoveCommand();
            }
            else
            {
                printf("%s: command not found\nuse: help\n",arguments[index]);
            }
            break;
        case 'h':
            if(strcmp(arguments[index],"history")==0)
            {
                treasureHistoryCommand();
            }
            else
            {
                printf("%s: sub command not found\nuse: help\n",arguments[index]);    
            }
            break;
        case 'l':
            if(strcmp(arguments[index],"list")==0)
            {
                treasureListCommand();
            }
            else
            {
                printf("%s: sub command not found\nuse: help\n",arguments[index]);
            }
            break;
        default:
            printf("%s: command not found\nuse: help\n",arguments[index]);
            break;
    }
}

/**
 * treasure init command
 **/
void treasureInitCommand()
{
    system("git clone https://github.com/TechOUs/Treasure-js.git");
}

/**
 * remove all treasure files
 **/
void treasureRemoveCommand()
{
    system("rm -rf Treasure-js");
}

/**
 * shows treasure history
 **/
void treasureHistoryCommand()
{
    FILE *ptr;
    ptr = fopen("release_notes.md","r");
    if(ptr==NULL)
    {
        system("wget https://raw.githubusercontent.com/TechOUs/Treasure-js/master/release_notes.md");
        ptr = fopen("release_notes.md","r");
    }
    char read[100];
    while(!feof(ptr))
    {
        fgets(read,100,ptr);
        printf("%s",read);
    }
    fclose(ptr);
}

/**
 * treasure list command
 **/
void treasureListCommand()
{
    printf("All Released Versions\n\n");
    printf("5.4.0\n");
    printf("5.3.0\n");
    printf("5.2.0\n");
    printf("5.1.0\n");
    printf("5.0.0\n");
    printf("4.7.0\n");
    printf("4.6.0\n");
    printf("4.5.0\n");
    printf("4.4.0\n");
    printf("4.3.0\n");
    printf("4.2.0\n");
    printf("4.1.0\n");
    printf("4.0.0\n");
    printf("3.7.0\n");
    printf("3.6.0\n");
    printf("3.5.0\n");
    printf("3.4.0\n");
    printf("3.3.0\n");
    printf("3.2.0\n");
    printf("3.1.0\n");
    printf("3.0.0\n");
    printf("2.5.0\n");
    printf("2.4.0\n");
    printf("2.3.0\n");
    printf("2.2.0\n");
    printf("2.1.0\n");
    printf("2.0.0\n");
    printf("1.0\n\n");
}

void handleTreasureOption(int index,char** arguments)
{
    char firstChar =    arguments[index][0];
    char secondChar =   arguments[index][1];
    
    if(secondChar == '-')
    {
        handleDoubleHypenOption(index, arguments);
    }
    else
    {
        handleSingleHypenOption(index, arguments);
    }
}

void handleSingleHypenOption(int index,char** arguments)
{
    char secondChar = arguments[index][1];
}

void handleDoubleHypenOption(int index,char** arguments)
{
    char thirdChar = arguments[index][2];
    switch(thirdChar)
    {
        case 'h':
            if(strcmp(arguments[index],"--help")==0)
            {
                showAllCommands();
            }
            else
            {
                printf("%s: option not found\nuse: help\n",arguments[index]);    
            }
            break;
        default:
            printf("%s: option not found\nuse: help\n",arguments[index]);
            break;
    }
}

void threeLengthCommand(char** arguments)
{

}
