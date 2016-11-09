
/**************************************************

file: demo_tx.c
purpose: simple demo that transmits characters to
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx

**************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"



int main()
{
  int i=0,/*n,*/
      cport_nr=24,        /* /dev/ttyS0 (c on windows) */
      bdrate=115200;       /* 9600 baud */

  char mode[]={'8','N','1',0},
       str[2][512];
  //unsigned char buf[4096];


  strcpy(str[0], "The quick brown fox jumped over the lazy grey dog.\n");

  strcpy(str[1], "Happy serial programming!.\n");


  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");

    return(0);
  }

  while(1)
  {
    if (i%2==0) {
        RS232_cputs(cport_nr, "A");
	printf("sent: %s\n", "A");
    } else {
        RS232_cputs(cport_nr, "B");
        printf("sent: %s\n", "B");
    }
    
    /*n = RS232_PollComport(cport_nr, buf, 4095);

    if(n > 0)
    {
      buf[n] = 0;

      for(i=0; i < n; i++)
      {
        if(buf[i] < 32) 
        {
          buf[i] = '.';
        }
      }

      printf("received %i bytes: %s\n", n, (char *)buf);
    }*/

    #ifdef _WIN32
    Sleep(10000);
    #else
    usleep(4000000);  /* sleep for 1 Second */
    #endif
    i++;

    i %= 2;
  }

  return(0);
}
