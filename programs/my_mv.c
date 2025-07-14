#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
    if (argc >3)
    {
        exit(-1);
    }
    else{
        int status = rename(argv[1],argv[2]);
        if(status == 0)
        {
            printf("Done\n");
        }
        else{
            exit(-1);
        }
    }

    return 0;
}