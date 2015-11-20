#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <stdint.h>
#include <string>

//DEFINE available GPIOs export number
#define XIO_P0 "408"
#define XIO_P1 "409"
#define XIO_P2 "410"
#define XIO_P3 "411"
#define XIO_P4 "412"
#define XIO_P5 "413"
#define XIO_P6 "414"
#define XIO_P7 "415"


class GPIO_MINI {
private:
	int fd;

public:
	GPIO_MINI();
	int	init(char* pin);
	void 	pinMode(uint8_t pin, uint8_t output);
	uint8_t pinread(uint8_t pin);
    void    pinwrite(uint8_t pin, uint8_t value);
    void    pintoggle(uint8_t pin);
};