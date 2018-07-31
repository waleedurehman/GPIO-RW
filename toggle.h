//toggle.h


#ifndef toggle
#define toggle
#include <stdbool.h>

#define BCM2708_PERI_BASE   0x3F000000
#define GPIO_BASE           (BCM2708_PERI_BASE + 0x200000) /* GPIO controller */


void setup_io();
bool readGPIO(int pin);
void setGPIO(int pin);
void clrGPIO(int pin);




#endif
