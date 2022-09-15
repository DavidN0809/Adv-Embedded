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


void adc(unsigned int* last){
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




   if(ADC_value <= 64 && ((*last+10) < ADC_value))
      displaynumber(0);

   else if(ADC_value <= 128 && ((*last+10) < ADC_value))
      displaynumber(1);

   else if(ADC_value <= 192 && ((*last+10) < ADC_value))
      displaynumber(2);

   else if(ADC_value <= 256 && ((*last+10) < ADC_value))
      displaynumber(3);

   else if(ADC_value <= 320 && ((*last+10) < ADC_value))
      displaynumber(4);

   else if(ADC_value <= 384 && ((*last+10) < ADC_value))
      displaynumber(5);

   else if(ADC_value <= 448 && ((*last+10) < ADC_value))
      displaynumber(6);

   else if(ADC_value <= 575 && ((*last+10) < ADC_value))
      displaynumber(7);

   else if(ADC_value <= 639 && ((*last+10) < ADC_value))
      displaynumber(8);

   else if(ADC_value <= 703 && ((*last+10) < ADC_value))
      displaynumber(9);

   else if(ADC_value <= 767 && ((*last+10) < ADC_value))
      displaynumber(10);

   else if(ADC_value <= 831 && ((*last+10) < ADC_value))
      displaynumber(11);

   else if(ADC_value <= 895 && ((*last+10) < ADC_value))
      displaynumber(12);

   else if(ADC_value <= 959 && ((*last+10) < ADC_value))
      displaynumber(13);

   else if(ADC_value <= 1023 && ((*last+10) < ADC_value))
      displaynumber(14);

   else{
      displaynumber(15);}
       *last = ADC_value;

}

//0 is on 1 is off
void main(void) {

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    P2SEL &= ~(BIT6);              // Set P2.6 & P2.7 as GPIO (Default is XIN/XOUT)
    P2SEL &= ~(BIT7);

    // Initialize 7-segment pins as Output
    P2DIR |= 0xFF;
    P1DIR |= BIT1; //Set P1.1 as output
    unsigned int* holder=0;//pass by ref value


    while(1){
    adc(holder);
        }

    }
