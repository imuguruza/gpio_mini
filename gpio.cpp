#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */

int main()
{
    int fd, err;
 
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1){
        printf("Unable to export GPIO\n");
        return -1;  
    } 
 
    err = write(fd, "408", 3); // TODO: Check return value
    if (err == -1){
        printf("Unable to create GPIO\n");
        return -1;  
    } 
    close(fd);
 
    fd = open("/sys/class/gpio/gpio408/direction", O_RDWR);
    if (fd == -1){
        printf("Unable to open direction n");
        return -1;  
    } 
 
    err = write(fd, "out", 4);
    if (err == -1){
        printf("Unable to set as out GPIO\n");
        return -1;  
    }
    close(fd);
 
    fd = open("/sys/class/gpio/gpio408/value", O_RDWR);
    if (fd == -1){
        printf("Unable to open GPIO for writing\n");
        return -1;  
    }
    
    for(int i=0; i< 1000; i++)
    {//Generate pulses
        err = write(fd,"1", 2);
        if (err == -1){
            printf("Unable to write GPIO\n");
            return -1;  
        }
        err = write(fd,"0", 2);
        if (err == -1){
            printf("Unable to write GPIO\n");
            return -1;  
        }
    }

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1) {
        printf("Unable to unexport GPIO %d\n", fd);
        return -1;
    }
    
    err = write(fd, "408", 3); // TODO: Check return value
    if (err == -1){
        printf("Error\n");
    }
    close(fd);
    printf("Finished\n");
    return 0;
}