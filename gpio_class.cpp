#include "gpio_class.h"
#include <stdlib.h>


GPIO_MINI :: GPIO_MINI ()
{}

int GPIO_MINI::init(char* pin)
{
	char buf;
	size_t nbytes;
	int fd,err;
	//nbytes = strlen(buf);
//open gpio file and see if can be read and writen
	if ((fd = open("/sys/class/gpio/export", O_WRONLY) ) < 0 ) {
		printf("Can't open /sys/class/gpio/export\n");
		return -1;
	}
// Now export the pin
	if ((err = write(fd, pin ,3 )) < 0) {
	//OR lenght written < expected length
		printf("Can't create gpio %d\n", pin);
		return -1;
	}
	close(fd);
 
}

void 	pinMode(uint8_t pin, uint8_t output)
{

}
	
uint8_t pinread(uint8_t pin)
{

	return 0;
}

void    pinwrite(uint8_t pin, uint8_t value)
{

}
    
void    pintoggle(uint8_t pin)
{

}

int main() {

	GPIO_MINI P0;
	P0.init(XIO_P0);
	printf("OK!\n");
	return 0;
}