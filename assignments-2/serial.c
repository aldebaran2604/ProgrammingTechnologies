#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>

#define BAUDRATE B115200
#define MODEMDEVICE "/dev/ttyACM0"
#define _POSIX_SOURCE 1 /* POSIX compliant source */

int main()
{
    int fd,c, res;
    struct termios oldtio,newtio;
    char buf[20];
    
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
    if (fd <0)
        perror(MODEMDEVICE);
    
    tcgetattr(fd,&oldtio); /* save current port settings */
    
    //bzero(&newtio,
    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 1;
    newtio.c_cc[VMIN] = 19;
    
    tcsetattr(fd,TCSANOW,&newtio);
    write(fd, "1", 1);
    while (1) {
        /* loop for input */
        res = read(fd,buf,19);
        /* returns after n chars have been input */
        buf[res]=0;
        /* so we can printf... */
        printf(": %s\n", buf);
        //tcflush(fd, TCIFLUSH);
    }
    
    tcsetattr(fd,TCSANOW,&oldtio);
    return 0;
}