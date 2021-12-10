#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "bash.h"

int main()
{
    /*All signals are ignored except KILL and Stop signals*/
    struct sigaction act;
    act.sa_handler=SIG_IGN;
    for(int i=1;i<=31;i++)
    {
        sigaction(i,&act,NULL);
    }
    pwd = getcwd(NULL,1024);
    children=(pid_t*)malloc(sizeof(pid_t)*1);
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
