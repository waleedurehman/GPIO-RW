//libtoggle.c
//libtoggle.c

#include "toggle.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdbool.h>

#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)

#define INP_GPIO(pin) *(gpio+((pin)/10)) &= ~(7<<(((pin)%10)*3))
#define OUT_GPIO(pin) *(gpio+((pin)/10)) |=  (1<<(((pin)%10)*3))

#define GPIO_SET *(gpio+7)  // sets   bits which are 1 ignores bits which are 0
#define GPIO_CLR *(gpio+10) // clears bits which are 1 ignores bits which are 0

#define GET_GPIO(pin) (*(gpio+13)&(1<<pin)) // 0 if LOW, (1<<pin) if HIGH

int  mem_fd;
void *gpio_map;

// I/O access
volatile unsigned *gpio;


void setup_io()
{
  /* open /dev/mem */
  if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
    printf("can't open /dev/mem \n");
    exit(-1);
  }

  /* mmap GPIO */
  gpio_map = mmap(
    NULL,             //Any adddress in our space will do
    BLOCK_SIZE,       //Map length
    PROT_READ|PROT_WRITE,// Enable reading & writting to mapped memory
    MAP_SHARED,       //Shared with other processes
    mem_fd,           //File to map
    GPIO_BASE         //Offset to GPIO peripheral
  );

  close(mem_fd); //No need to keep mem_fd open after mmap

  if (gpio_map == MAP_FAILED) {
    printf("mmap error %d\n", (int)gpio_map);//errno also set!
    exit(-1);
  }

  // Always use volatile pointer!
  gpio = (volatile unsigned *)gpio_map;

} // setup_io

bool readGPIO(int pin)
{
  if (GET_GPIO(pin)) // !=0 <-> bit is 1 <- port is HIGH=3.3V
	  return(1);
  else // port is LOW=0V
    return(0);
}

void setGPIO(int pin)
{
	INP_GPIO(pin); //must use INP_GPIO before using OUT_GPIO
  OUT_GPIO(pin);

	GPIO_SET = 1<<pin;
}

void clrGPIO(int pin)
{
	INP_GPIO(pin); //must use INP_GPIO before using OUT_GPIO
  OUT_GPIO(pin);

  GPIO_CLR = 1<<pin;
}	


