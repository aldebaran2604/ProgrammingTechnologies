#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 16000000
#endif
#define UART_BAUD_RATE 115200

void uart_init()
{
    uint16_t ubbr = F_CPU/((UART_BAUD_RATE)*16L) - 1;
    // asynchronous 8N1
    UCSR0C= 3<<UCSZ00;
    // set baud rate
    UBRR0L = ubbr; // low byte
    UBRR0H = (ubbr >> 8); // high byte
    // enable rx and tx
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}

static unsigned char uart_read_char(void)
{
    while( !(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void uart_write_char(char c)
{
    while (!(UCSR0A & (1<<UDRE0))); // wait until buffer is ready
    UDR0 = c;
}

void uart_write_string(char *c)
{
    while (*c != '\0') {
        uart_write_char(*c);
        c++;
    }
}

int main(void)
{
    uart_init();
    unsigned char byte;
    
    byte = uart_read_char();
    if (byte == '1') {
        while (1) {
            uart_write_string("Hello from Arduino!\n");
        }
    }
}