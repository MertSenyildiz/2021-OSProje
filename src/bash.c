#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "bash.h"

char* pwd;
pid_t* children;

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
    while(args[token]!=NULL&&token<MAXARGS-1)
        args[++token]=strtok(NULL," ");
      
}

void addProssesId(pid_t pid)
{
    children[counter]=pid;
    counter++;
    children=realloc(children,sizeof(pid_t)*(counter+1));
}

void executeCommand(char* args[])
{
        if(args[0]==NULL)
            return;
        int i=1;
        while(args[i]!=NULL)
        {
            if(strcmp(args[i],"&")==0)
            {
                args[i]==NULL;
                runBackground(args);
                return;
            }
            i++;
        }
        if(strcmp(args[0],"exit")==0)
            builtin_exit(args);
        else if(strcmp(args[0],"cd")==0)
            builtin_cd(args);
        else if(strcmp(args[0],"showpid")==0)
            builtin_showpid(args);
        else
        {
            pid_t chpid;
            chpid=fork();
            if(chpid==0)
            {
                if(execvp(args[0],args)==-1)
                    printf("Komut icra edilemiyor");
                _exit(0);  
            }
            else if(chpid>0)
            {
                int status;
                waitpid(chpid,&status,0);   
                addProssesId(chpid);
            }
            else
            {
                perror("Hata:Fork Hatasi");
            } 
        }    
}

void runBackground(char* args[])
{
    if(args[0]==NULL)
        return;
    int chpid;
   if(strcmp(args[0],"init")==0)
    {
       chpid=fork();
       if(chpid==0)
       {
           while(1)
           {}
       }
       else if(chpid>0)
            addProssesId(chpid); 
    }
    else
    {
        chpid=fork();
       if(chpid==0)
       {
           if(execvp(args[0],args)==-1)
           {
               perror("Hata:Komut icra edilemiyor");
               kill(getpid(),SIGTERM);
           }
           kill(getpid(),SIGTERM);
       }
       else if(chpid>0)
            addProssesId(chpid); 
    }
}

void builtin_exit(char* args[])
{
    if(args[1]==NULL)
    {  
        for(int i=0;i<counter;i++)
        {
            int status;
            waitpid(children[i],&status,WNOHANG);
            kill(children[i],9);
        }
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

void builtin_showpid(char* args[])
{
    if(args[1]==NULL)
    {
        if(counter>0)
            for (int i = 0; i < counter; i++)
            {
                if(kill(children[i],0)==0)/*Sends a dummy signal to check whether child is dead or not*/
                    printf("[%d] Running\n",children[i]);
                else
                    printf("[%d] Exited\n",children[i]);
            } 
    }
    else
        printf("Too Many Arguments\n");
}

