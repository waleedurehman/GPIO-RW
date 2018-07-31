//toggle.c

#include "toggle.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
  
  if (argc==1)
  {
    printf("./toggle --help        ....show USAGE INFO\n");
    return(1);
  }

  int pin;
  int state=2;
  int readflag;
  int setflag;
  
  char argument1[6]="NULL";
  char argument3[6]="NULL";
  char argument5[2]="";

  if (argc==2)
    strcpy(argument1,argv[1]);
  else if(argc>2 && argc<=5)
  {
    if(argc==3)
    {
      printf("\nInvalid Arguments Entered\n");
      printf("/.toggle --help       ....show usage info\n");
      return(1);
    }
    strcpy(argument1,argv[1]);
    pin=atoi(argv[2]);
    if(pin!=17 && pin!=22 && pin!=27)
    {
      printf("Pins Available: 17,22,27\n");
      return(1);
    } 
    strcpy(argument3,argv[3]);
    if(argc==5)
      strcpy(argument5,argv[4]);
      //state=atoi(argv[4]);
  }
     

  if(!strcmp(argument1,"--help"))
  {
    printf("\nUSAGE INFO:\n\n");
    printf("Pins Available: 17, 22 ,27\n");
    printf("./toggle --pin [pin number] --read        ....reads the pin number\n");
    printf("./toggle --pin [pin number] --set [state] ....sets the pin to 1 or 0\n");
    return (0);
  }
  else if(!strcmp(argument1,"--pin"))
    if(!strcmp(argument3,"--read"))
    { 
      if(argc>4)
      {
        printf("\nInvalid Arguments Entered\n");
        printf("/.toggle --help       ....show usage info\n");
        return(1);
      }
      readflag=1;
    }
    else if(!strcmp(argument3,"--set"))
    {  
      if(!strcmp(argument5,"1")||!strcmp(argument5,"0"))
      {
        state=atoi(argv[4]);
        setflag=1;
      }
      else
      {
        printf("\nInvalid Arguments Entered\n");
	printf("/.toggle --help       ....show usage info\n");
        return(1);
      }
    } 
    else
    {
      printf("\nInvalid Arguments Entered\n");
      printf("/.toggle --help       ....show usage info\n");
      return (1);
    }
    else
    {
      printf("\nInvalid Arguments Entered\n");
      printf("/.toggle --help       ....show usage info\n");
      return(1);
    }

  setup_io();
  //READ GPIO
  if(readflag==1)
  { 
    state=readGPIO(pin);
    //if (verbose)
    //  printf("Pin %d is set to :", pin);

    printf("%d\n", state);
  }

  //SET GPIO
  if(setflag==1)
  {
    if(state==1)
      setGPIO(pin);
    else
      clrGPIO(pin);
  }
  return(0);
}
