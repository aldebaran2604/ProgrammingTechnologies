#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
    struct sockaddr_rc addr = { 0 };
    char buffer[1];
    int s, status;
    char dest[18] = "20:15:05:19:58:58";
    int opt=0;
    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
	printf("ROVER: \n 1:atras\n2:avanzar\n3:izquierda\n4:derecha\n5:parar\n");
	while(1){
		scanf("%d",&opt);
		snprintf(buffer, 10, "%d", opt);
        	status = write(s, buffer, 1);
		usleep(1000);
	}
    }

    if( status < 0 ) perror("uh oh");

    close(s);
    return 0;
}
