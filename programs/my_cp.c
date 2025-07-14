#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc , char* argv[])
{
    if(argc != 3)
    {
        printf("PLease Enter 2 argument only to the utility\n");
        exit(-1);
    }
    char buf[BUFFER_SIZE];

    int src_fd = 0;
    int dest_fd = 0;
    int read_status = 0;
    int write_status = 0;
    src_fd = open(argv[1], O_RDONLY,  0x644);
    if(src_fd < 0)
    {
        exit(-1);
    }
    else
    {
        dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,  0644);
        if(dest_fd < 0)
        {
            exit(-1);
        }
        else
        {
            while((read_status = read(src_fd, buf, BUFFER_SIZE)) != 0)
            {
                if(read_status == -1 )
                {
                    exit(-1);
                }
                write_status =  write(dest_fd, buf, read_status);
                if(write_status == -1 )
                {
                    exit(-1);
                }
            }

        }
        printf("Done ;)\n");       
    }

}