#ifndef BASH_H
#define BASH_H

#define BLACK "\x1B[1;30m"
#define RED "\x1B[1;31m"
#define GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define BLUE "\x1B[1;34m"
#define PURPLE "\x1B[1;35m"
#define CYAN "\x1B[1;36m"
#define WHITE "\x1B[1;37m"

#define MAXLENGHT 80
#define MAXARGS 10

extern char* pwd;
extern pid_t* children;
static int counter;

void showPromt();
void parseCommand(char* text,char* args[]);
void executeCommand(char* args[]);
void runBackground(char* args[]);
void addProcessId(pid_t pid);
void builtin_exit(char* args[]);
void builtin_cd(char* args[]);
void builtin_showpid(char* args[]);
void backgroundSignalHandler(int signo);
#endif