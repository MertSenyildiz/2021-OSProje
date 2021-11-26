#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "bash.h"
int main()
{
    char* input=(char*)malloc(sizeof(char)*MAXLENGHT);
    char* commands[MAXARGS];
    while(1)
    {
        showPromt();
        memset(stdin,'\0',MAXLENGHT);
        memset(input,'\0',MAXLENGHT);
        fgets(input,MAXLENGHT,stdin);
        if(input[strlen(input)-1]=='\n')
        {
            input[strlen(input)-1]='\0';
        }
        //fflush(stdout);
        parseCommand(input,commands);
        executeCommand(commands);
    } 
    return 0;
}
