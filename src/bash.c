#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "bash.h"
char* pwd;
void showPromt()
{
    char hostname[1024];
    gethostname(hostname,1024);
    printf("%s[%s%s@%s %s%s]:%sSAU> %s",WHITE,GREEN,hostname,getenv("LOGNAME"),pwd,WHITE,GREEN,WHITE);
}

void parseCommand(char* input,char* args[])
{
    if(input[strlen(input)-1]=='\n')
        input[strlen(input)-1]='\0';
    args[0]=strtok(input," ");
    int token=0;
    while(args[token]!=NULL&&token<9)
        args[++token]=strtok(NULL," ");
      
}

void executeCommand(char* args[])
{
        if(args[0]==NULL)
            return;
        if(strcmp(args[0],"exit")==0)
            builtin_exit(args);
        else if(strcmp(args[0],"cd")==0)
            builtin_cd(args);
        else
        {
            pid_t chpid;
            chpid=fork();
            if(chpid==0)
            {

                if(execvp(args[0],args)==-1)
                    perror("Hata:Komut icra edilemiyor");
                _exit(0);  
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
}

void builtin_exit(char* args[])
{
    if(args[1]==NULL)
    {
        printf("%s\n",args[0]);
        _exit(0);
    }
    else
        printf("Too Many Arguments\n");
}

void builtin_cd(char*args[])
{
    if(args[1]==NULL)
    {
        printf("Not Enough Argument\n");
        return;
    }
    if(chdir(args[1])!=0 || args[2]!=NULL)
    {
        perror("Hata");
        return;
    }
    pwd=getcwd(NULL,1024);
}

