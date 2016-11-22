#include <avr/io.h>
#include <util/delay.h>
 
#define BLINK_DELAY_MS 9000
 
int main (void)
{
 /* set pin 5 of PORTB for output*/
    DDRB |= _BV(DDB4);
    DDRB |= _BV(DDB3);
    DDRB |= _BV(DDB2);
    
    DDRB |= _BV(DDB1);
    DDRB |= _BV(DDB0);
 
    while(1) {
        /* set pin 5 high to turn led on */
        PORTB |= _BV(PORTB4);
        PORTB |= _BV(PORTB0);
        _delay_ms(BLINK_DELAY_MS);
        PORTB &= ~_BV(PORTB4);
        
        PORTB |= _BV(PORTB3);
        _delay_ms(BLINK_DELAY_MS);
        PORTB &= ~_BV(PORTB3);
        PORTB &= ~_BV(PORTB0);
        
        PORTB |= _BV(PORTB2);
        PORTB |= _BV(PORTB1);
        _delay_ms(BLINK_DELAY_MS);
        PORTB &= ~_BV(PORTB2);
        PORTB &= ~_BV(PORTB1);
 
        /* set pin 5 low to turn led off */
        //PORTB &= ~_BV(PORTB5);
        //_delay_ms(BLINK_DELAY_MS);
    }
}
