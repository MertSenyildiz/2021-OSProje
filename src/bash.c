#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bash.h"

void init(char* pwd)
{
    char mrb[1024];
    gethostname(mrb,1023);
    printf("\033[0;32m%s  %s: Sau>\033[0;37m ",mrb,pwd);
}