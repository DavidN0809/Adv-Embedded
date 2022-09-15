# Issues with Lab
## Issue 1
XIN was always driving high, believe to be issue with MSP430 board due to testing working code on another MSP430 and the issue is gone.
```
Work around for this was using Pin 1.3 to drive the segment B. 
## Issue 2
Due to ADC needing Pin 1 as input and the 7 segment needing Pin 1 as output.
```
Work around for this was to declare Pin 1 as input in ADC function and then redeclare pin 1 as output in display function.
