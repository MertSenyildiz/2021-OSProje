#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "bash.h"

int main()
{
    pwd = getcwd(NULL,1024);
    char* input=(char*)malloc(sizeof(char)*MAXLENGHT);
    char* commands[MAXARGS];
    while(1)
    {
        showPromt();
        memset(stdin,'\0',MAXLENGHT);
        memset(input,'\0',MAXLENGHT);
        fgets(input,MAXLENGHT,stdin);
        parseCommand(input,commands);
        executeCommand(commands);
    } 
    return 0;
}
