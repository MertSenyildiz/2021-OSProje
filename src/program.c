#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "bash.h"
void showPromt()
{
    char hostname[1024];
    gethostname(hostname,1024);
    printf("%s[%s%s@%s %s%s]:%sSAU> %s",WHITE,GREEN,hostname,getenv("LOGNAME"),getcwd(NULL,1024),WHITE,GREEN,WHITE);
}
int main()
{
    char* command=(char*)malloc(sizeof(char)*MAXLENGHT);
    while(1)
    {
        showPromt();
        fgets(command,MAXLENGHT,stdin);
        if(command[strlen(command)-1]=='\n')
        {
            command[strlen(command)-1]='\0';
            printf("%s\n",command);
        }
    } 
    return 0;
}
