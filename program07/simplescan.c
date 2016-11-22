#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/l2cap.h>

typedef struct _listBluetooths {
    char addr[19];
    char name[248];
    int option;
    struct _listBluetooths* next;
} ListBluetooths;

ListBluetooths* firstLB = NULL;
ListBluetooths* lastLB = NULL;

void addList(ListBluetooths* _lb);
void mostrar_lista(ListBluetooths* _lb);
void connectBluetooth(char *argv);
ListBluetooths* buscar_lista(ListBluetooths* _lb, int option);

int main(int argc, char **argv)
{
    ListBluetooths *lb = NULL;
    //ListBluetooths *auxlb = NULL;
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };

    dev_id = hci_get_route(NULL);
    sock = hci_open_dev( dev_id );
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    len  = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    
    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("hci_inquiry");
    int cont = 0;
    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0){
            strcpy(name, "[unknown]");
            //printf("%s  %s\n", addr, name);
            cont++;
            printf("Opción %i %s  %s\n", cont, addr, name);
            if (lb == NULL) {
                lb = malloc(sizeof(ListBluetooths));
                lb->option = cont;
                strcpy(lb->addr, addr);
                strcpy(lb->name, name);
                addList(lb);
                //connectBluetooth(lb->addr);
            } else {
                ListBluetooths *auxlb = malloc(sizeof(ListBluetooths));
                auxlb->option = cont;
                strcpy(auxlb->addr, addr);
                strcpy(auxlb->name, name);
                addList(auxlb);
                //connectBluetooth(auxlb->addr);
            }
        }
    }
    if (cont>0) {
        while(1) {
            char optionMenu[20];
            int stringToIntOption = 0;
            printf("0 para salir.\n");
            printf("Ingrese la opción.\n");
            scanf("%s", optionMenu);
            stringToIntOption = atoi(optionMenu);
            ListBluetooths *auxSearch = buscar_lista(lb, stringToIntOption);
            if (auxSearch!=NULL) {
                printf("Realizando conexión.\n");
                connectBluetooth(auxSearch->addr);
            }
            
            if (stringToIntOption==0) {
                break;
            }
        }
    } else {
        printf("No se detectaron dispositivos.\n");
    }
    
    //mostrar_lista(lb);

    free( ii );
    close( sock );
    return 0;
}

void addList(ListBluetooths* _lb) {
    _lb->next = NULL;
    if (firstLB == NULL) {
        firstLB = _lb;
        lastLB = _lb;
    } else {
        lastLB->next = _lb;
        lastLB = _lb;
    }
}


void mostrar_lista(ListBluetooths* _lb) {
    ListBluetooths *auxiliar; /* lo usamos para recorrer la lista */
    int i;
 
    i=0;
    auxiliar = _lb;
    printf("\nMostrando la lista completa:\n");
    while (auxiliar!=NULL) {
        printf( "addr: %s, name: %s\n", auxiliar->addr, auxiliar->name);
        auxiliar = auxiliar->next;
        i++;
    }
    if (i==0) {
        printf( "\nLa lista está vacía!!\n" );
    }
}

ListBluetooths* buscar_lista(ListBluetooths* _lb, int option) {
    ListBluetooths *auxiliar; /* lo usamos para recorrer la lista */
    ListBluetooths *auxiliar2 = NULL; /* Para guardar el struct que se encontro */
    int i;
 
    i=0;
    auxiliar = _lb;
    printf("\nBuscando dispositivo en la lista:\n");
    while (auxiliar!=NULL) {
        if (auxiliar->option==option) {
            auxiliar2 = auxiliar;
            printf( "addr: %s, name: %s\n", auxiliar->addr, auxiliar->name);
        }
        auxiliar = auxiliar->next;
        i++;
        
    }
    if (i==0) {
        printf( "\nLa lista está vacía!!\n" );
    }
    return auxiliar2;
}

void connectBluetooth(char *argv) {
    struct sockaddr_l2 addr = { 0 };
    int s, status;
    char *message = "hello!";
    char dest[18] = "01:23:45:67:89:AB";

    /*if(argc < 2)
    {
        fprintf(stderr, "usage: %s <bt_addr>\n", argv);
        exit(2);
    }*/

    strncpy(dest, argv, 18);

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);

    // set the connection parameters (who to connect to)
    addr.l2_family = AF_BLUETOOTH;
    addr.l2_psm = htobs(0x1001);
    str2ba( dest, &addr.l2_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
        while (1) {
            char messageAr[6];
            printf( "\nIngrese el mensaje a enviar\n" );
            scanf("%s", messageAr);
            status = write(s, messageAr, 6);
            if (status < 0) {
                break;
            }
        }
    }

    if( status < 0 ) perror("uh oh");

    close(s);
}
