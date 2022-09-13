// ECGR 4101 - Advanced embeded systems
// Project Group 3
// Joshua Ayers || David Nichols

// HW 1 -
// Get the MSP-430G2552 to flash its led in one second periods

#include <msp430.h>


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;        // stop watchdog timer
    P1DIR |= 0x01;                    // configure P1.0 as output

    volatile unsigned int i;        // volatile to prevent optimization
    volatile unsigned int j;

    while(1)
    {
        //
        P1OUT ^= 0x01;                // toggle P1.0
        for(i=4; i>0; i--){for(j=0; j<14000;j++);};     // delay
    }
}
