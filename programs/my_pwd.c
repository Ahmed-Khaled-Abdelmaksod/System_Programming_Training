#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define CWD_SIZE 1024

int main(int argc,char* argv[])
{
    char cwd[CWD_SIZE];
    
    char* buffer_address = getcwd(cwd, CWD_SIZE);
    if(buffer_address == NULL)
    {
        exit(-1);
    }
    else
    {
        printf("%s\n",buffer_address);
    }
    return 0;

}