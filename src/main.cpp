#include <Arduino.h>
#include <msp430g2553.h>
#include "pins_energia.h"

// #define GREEN_LED 14

// void debugOnBoardLED() {
//   digitalWrite(GREEN_LED, 1);
//   digitalWrite(RED_LED, 0);
//   delay(500);
//   digitalWrite(RED_LED, 1);
//   digitalWrite(GREEN_LED, 0);
//   delay(500);
// }

void setup() {

  WDTCTL = WDTPW + WDTHOLD; // Stop WDT

  /* RED_LED is P1.0 GREEN_LED is P1.6 */
  

  /* Set RED_LED and GREEN_LED to outputs, set RED on */
  // P1DIR |= BIT0 + BIT6;
  // P1OUT &= ~(BIT0 + BIT6);
  // P1OUT |= BIT0;

  /* Configure DCOCLK to run at 1MHz */
  DCOCTL = 0;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;

  /* Configure SMCLK to div DCOCLK by 8 */
  BCSCTL2 &= ~SELS; // set SMCLK to DCOCLK
  BCSCTL2 |= DIVS_3; // div by 8
  // BCSCTL2 |= DIVS_2; // div by 4
  /* Now, SMCLK runs at 1e6/8= 125kHz */

  /* Configure TIMER_A to run on SMCLK and in Continuous Mode */
  TA0CTL = TASSEL_2 + MC_2;
  // TA0CTL = TASSEL_1 + MC_2;

  /* Configure Timer_A Capture/Compare Control 0 Register TACCTL2 as set/reset*/
  /* Want this to generate a pulse on some pin at 2Hz ? */
  TA0CCTL1 = OUTMOD_3;

  /* Configure the pulse by setting PWM period in TAOCCR1 */
  TA0CCR0 = 62500-1; // This is about 2Hz (Reset)
  TA0CCR1 = 62500-6250-1;  // Want about 10% duty cycle? (Set)

  /* Set some output pins to the set/reset function */
  // P1DIR |= BIT5;
  // P1SEL |= BIT5;
  // P1SEL2 &= ~BIT5;
  
  P1DIR |= BIT6;
  P1SEL |= BIT6;
  P1SEL2 &= ~BIT6;

}

void loop() {
  // __delay_cycles(8000000);
  // P1OUT ^= BIT0 + BIT6;
}
