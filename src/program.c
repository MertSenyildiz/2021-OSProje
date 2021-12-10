#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "bash.h"

void initProcesses();

int main()
{
    /*All signals are ignored except KILL STOP and SIGCHLD signals*/
    struct sigaction act;
    act.sa_handler=SIG_IGN;
    for(int i=1;i<=31;i++)
    {
        if(i!=SIGCHLD)
            sigaction(i,&act,NULL);
    }

    children=(pid_t*)malloc(sizeof(pid_t)*1);

    for(int i=0;i<5;i++)
        initProcesses();

    char* input=(char*)malloc(sizeof(char)*MAXLENGHT);
    char* commands[MAXARGS];
    pwd = getcwd(NULL,1024);
    
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
void initProcesses()
{
    char* init="init";
    char* arg[MAXARGS];
    parseCommand(init,arg);
    runBackground(arg);
}