#include <msp430.h>

// Define Pin Mapping of 7-segment Display
// Segments are connected to P1.0 - P1.7


void displaynumber (volatile int number){
    P1DIR |= BIT1; //Set P1.1 as output

    // Toggle seven segment based off number
      switch (number){
      case (0):
            P2OUT =  0B00100001;
            P1OUT = 0x00;
            break;

      case (1):
        P2OUT =  0B11111101;
        P1OUT = 0x00;
          break;
      case (2):
         P2OUT =  0B11000011;
        P1OUT = 0x00;
          break;

      case (3):
         P2OUT =  0B10010001;
         P1OUT = 0x00;
          break;

      case (4):
        P2OUT =  0B00011101;
        P1OUT = 0x00;
          break;

      case (5):
        P2OUT =  0B01010001;
        P1OUT = 0xFF;
          break;

      case (6):
        P2OUT =  0B01000001;
        P1OUT = 0xFF;
          break;

      case (7):
        P2OUT =  0B11111001;
        P1OUT = 0x00;

          break;
      case (8):
        P2OUT =  0B00000001;
        P1OUT = 0x00;
          break;

      case (9):
        P2OUT =  0B00010001;
        P1OUT = 0x00;
          break;

      case (10): //A
        P2OUT =  0B00001001;
        P1OUT = 0x00;
        break;


      case (11): //B
        P2OUT =  0B01000101;
        P1OUT = 0xFF;
          break;

      case (12)://C
        P2OUT =  0B01100011;
        P1OUT = 0xFF;
          break;

      case (13)://D
        P2OUT =  0B11000101;
        P1OUT = 0x00;

          break;
      case (14)://E
        P2OUT =  0B01000011;
        P1OUT = 0xFF;
          break;

      case (15)://F
        P2OUT =  0B0001011;
        P1OUT = 0xFF;
          break;

      default:
          P2OUT ^= 0xFF;
          P1OUT = 0xFF;

          break;
      };

}


void adc(){
    //Set pin to Analog input
    P1SEL |= BIT0;
    volatile unsigned int ADC_value;
    // select channel A0
    ADC10AE0 = 0x01;
    // Select Channel A0, ADC10CLK/3
    ADC10CTL1 = INCH_0 + ADC10DIV_3;

    // Vcc & Vss as reference,
    // Sample/hold 64 cycle, mult sample, turn on
    ADC10CTL0 = ADC10SHT_3 + MSC + ADC10ON;
    //Use the ADC – Fetch values
    // Sampling and conversion start
    ADC10CTL0 |= ENC + ADC10SC;
    // Assigns the value held in ADC10MEM to the
    // integer called ADC_value
    ADC_value = ADC10MEM;

   if(ADC_value <= 64)
      displaynumber(0);

   else if(ADC_value <= 128)
      displaynumber(1);

   else if(ADC_value <= 192)
      displaynumber(2);

   else if(ADC_value <= 256)
      displaynumber(3);

   else if(ADC_value <= 320)
      displaynumber(4);

   else if(ADC_value <= 384)
      displaynumber(5);

   else if(ADC_value <= 448)
      displaynumber(6);

   else if(ADC_value <= 575)
      displaynumber(7);

   else if(ADC_value <= 639)
      displaynumber(8);

   else if(ADC_value <= 703)
      displaynumber(9);

   else if(ADC_value <= 767)
      displaynumber(10);

   else if(ADC_value <= 831)
      displaynumber(11);

   else if(ADC_value <= 895)
      displaynumber(12);

   else if(ADC_value <= 959)
      displaynumber(13);

   else if(ADC_value <= 1023)
      displaynumber(14);

   else
      displaynumber(15);

}

//0 is on 1 is off
void main(void) {

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    P2SEL &= ~(BIT6);              // Set P2.6 & P2.7 as GPIO (Default is XIN/XOUT)
    P2SEL &= ~(BIT7);

    //int number = 0;
    // Initialize 7-segment pins as Output
    P2DIR |= 0xFF;
    P1DIR |= BIT1; //Set P1.1 as output

    while(1){
    adc();
    }

    }
