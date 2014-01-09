#include <stdio.h>
#include <stdlib.h>

#define MEGABYTE 1024*1024

int main(int argc, char *argv[])
{
    void *myblock = NULL;
    int count = 0;

    while(1)
    {
        myblock = (void *) malloc(MEGABYTE);
        if (!myblock) break;
        memset(myblock,1,
                    MEGABYTE);
        printf("Currently  allocatinn  %d  MB\n",++count);
        usleep(20000);
    }
    exit(0);

}

