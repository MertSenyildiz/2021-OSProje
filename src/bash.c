#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "bash.h"

void showPromt()
{
    char hostname[1024];
    gethostname(hostname,1024);
    printf("%s[%s%s@%s %s%s]:%sSAU> %s",WHITE,GREEN,hostname,getenv("LOGNAME"),getcwd(NULL,1024),WHITE,GREEN,WHITE);
}

void parseCommand(char* input,char* args[])
{
    args[0]=strtok(input," ");
    int token=0;
    while(args[token]!=NULL&&token<9)
        args[++token]=strtok(NULL," ");
           
}

void executeCommand(char* args[])
{
    pid_t chpid;
    chpid=fork();
    if(chpid==0)
    {

        if(execvp(args[0],args)==-1)
            perror("Hata:Komut icra edilemiyor");
        exit(0);  
    }
    else if(chpid>0)
    {
        int status;
        waitpid(chpid,&status,0);
        if(status!=0)
            printf("Child prosseste bir problem oldu\n");
    }
    else
    {
        perror("Hata:Fork Hatasi");
    }
        
}
