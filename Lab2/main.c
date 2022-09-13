// ECGR 4101
// Joshua Ayers
// David Nichols
// Fall 2022

// ECGR 4101 - Lab 2 external button pausing blinking LED


#include <msp430.h>

#define SW  BIT3                    // Switch -> P1.3
#define LED BIT4                    // Red LED -> P1.4

void main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
       P1DIR&=~SW; //Set P1.0 as input
       P1REN|=SW; //Enable pullup/pulldown resistors for P1.3
       P1OUT|=SW; //Set P1.0 to have pull up resistors

       P1DIR|=LED; //Set P1.3 as output
       P1OUT&=~LED; //Initially turn off the LED

    while(1)
    {

        P1OUT ^= LED;           // Toggle LED
        __delay_cycles(1000000);  // Wait 20ms to debounce

        if(!(P1IN & SW))            // If SW is Pressed
        {
            __delay_cycles(20000);  // Wait 20ms to debounce
            while(!(P1IN & SW));    // Wait till SW Released
            P1OUT ^= LED;           // Toggle LED
        }
    }
}
