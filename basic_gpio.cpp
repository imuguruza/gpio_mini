#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */

int main()
{
    int fd;
 
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) return -1;
 
    write(fd, "408", 3); // TODO: Check return value
    close(fd);
 
    fd = open("/sys/class/gpio/gpio408/direction", O_RDWR);
    if (fd < 0) return -1;
 
    write(fd, "out", 4);
    close(fd);
 
    fd = open("/sys/class/gpio/gpio408/value", O_RDWR);
    if (fd < 0) return -1;
    
    for(int i=0; i< 1000000000; i++)
    {//Generate pulses
        write(fd,"1", 2);
        write(fd,"0", 2);
    }

    fd = open("sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) return -1;
    
    write(fd, "408", 3); // TODO: Check return value
    close(fd);
    return 0;
}