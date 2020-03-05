#include "two.h"

/**
 * TWO LENGTH COMMANDS
 * 
 * - treasure init
 * - treasure remove 
 * - treasure history
 * - treasure list
 * treasure website
 * - treasure license
 * 
 * treasure -h
 * treasure -help
 * treasure -v
 * treasure --current-version
 **/
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
 * treasure website
 * treasure license
 **/
void handleTreasureCommand(int index,char** arguments)
{
    char firstChar = arguments[index][0];
    switch(firstChar)
    {
        case 'i':
            strcmp(arguments[index],"init")==0 ? treasureInitCommand() : defaultOutput(arguments[index]);
            break;
        case 'r':
            strcmp(arguments[index],"remove")==0 ? treasureRemoveCommand() : defaultOutput(arguments[index]);
            break;
        case 'h':
            strcmp(arguments[index],"history")==0 ? treasureHistoryCommand() : defaultOutput(arguments[index]);
            break;
        case 'l':
            if(strcmp(arguments[index],"list")==0){
                treasureListCommand();
            }else if(strcmp(arguments[index],"license")==0){
                treasureLicenseCommand();
            }else{
                defaultOutput(arguments[index]);
            }
            // strcmp(arguments[index],"list")==0 ? treasureListCommand() : defaultOutput(arguments[index]);
            // strcmp(arguments[index],"license")==0 ? treasureLicenseCommand() : defaultOutput(arguments[index]);
            break;
        case 'w':
            strcmp(arguments[index], "website")==0 ? treasureWebsiteCommand() : defaultOutput(arguments[index]);
            break;
        default:
            defaultOutput(arguments[index]);
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
        bool endFlag = false;
        bool print = false;
        if(read[0]>=48 && read[0]<=57){
            continue;
        }
        for(int i=0;i<strlen(read);i++){
            if(read[i]==']'){
                print=false;
                endFlag = true;
            }
            if(print){
                if(read[i]>=48 && read[i]<=57){
                    printf("%s%c%s",BLGREEN, read[i], RESET);
                }else{
                    printf("%c", read[i]);
                }
            }
            if(read[i]=='*'){
                break;
            }
            else if(read[i]=='['){
                print = true;
            } 
        }
        if(endFlag){
            printf("\n");
        }
    }
    fclose(ptr);
}

void treasureLicenseCommand(){
    FILE *ptr;
    ptr = fopen("LICENSE","r");
    if(ptr==NULL)
    {
        system("wget https://raw.githubusercontent.com/TechOUs/Treasure-js/master/LICENSE");
        ptr = fopen("LICENSE","r");
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
 * this functions displays the treasure website information
 **/
void treasureWebsiteCommand(){
    printf("Open: ");
    printf("http://treasurejs.tk\n\n");
}

/**
 * handle the treasure options command
 * 
 * @param index
 * @param arguments array
 **/
void handleTreasureOption(int index,char** arguments)
{
    char firstChar  =   arguments[index][0];
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

/**
 * handle single hyphen option
 * 
 * @param index
 * @param arguments
 **/
void handleSingleHypenOption(int index,char** arguments)
{
    char secondChar = arguments[index][1];
    switch(secondChar)
    {
        case 'v':
            strcmp(arguments[index], "-v")==0 ? showCurrentVersion() : defaultOutput(arguments[index]); 
            break;
        default:
            defaultOutput(arguments[index]);
    }
}

/**
 * handle double hyphen option
 * 
 * @param index
 * @param arguments
 **/
void handleDoubleHypenOption(int index,char** arguments)
{
    char thirdChar = arguments[index][2];
    switch(thirdChar)
    {
        case 'c':
            strcmp(arguments[index], "--current-version")==0 ? showCurrentVersion() :  defaultOutput(arguments[index]);
            break;
        case 'h':
            strcmp(arguments[index],"--help")==0 ? showAllCommands() : defaultOutput(arguments[index]);
            break;
        default:
            defaultOutput(arguments[index]);
            break;
    }
}

/**
 * shows the current version
 **/
void showCurrentVersion()
{
    FILE *ptr;
    ptr = fopen("release_notes.md","r");
    if(ptr==NULL)
    {
        system("wget https://raw.githubusercontent.com/TechOUs/Treasure-js/master/release_notes.md");
        ptr = fopen("release_notes.md","r");
    }
    printf("%sCurrent Version: ",BYELLOW);
    char read[100];
    while(!feof(ptr))
    {
        fgets(read,100,ptr);
        bool endFlag = false;
        bool print = false;

        for(int i=0;i<strlen(read);i++){
            if(read[i]==']'){
                print=false;
                endFlag = true;
            }
            if(print){
                if((read[i]>=48 && read[i]<=57) || read[i]=='.'){
                    printf("%c", read[i]);
                }
            }
            if(read[i]=='*'){
                break;
            }
            else if(read[i]=='['){
                print = true;
            } 
        }
        if(endFlag){
            printf("%s\n\n", RESET);
            break;
        }
    }
    fclose(ptr);
}