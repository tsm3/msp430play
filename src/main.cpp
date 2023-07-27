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
  /* RED_LED is P1.0 GREEN_LED is P1.6 */
  // pinMode(GREEN_LED, OUTPUT);
  // pinMode(RED_LED, OUTPUT);

  /* Set RED_LED and GREEN_LED to outputs, set RED on */
  P1DIR |= BIT0 + BIT6;
  P1OUT &= ~(BIT0 + BIT6);
  P1OUT |= BIT0;

  /* Configure DCOCLK to run at 1MHz */
  DCOCTL = CALDCO_1MHZ;

  /* Configure SMCLK to div DCOCLK by 8 */
  BCSCTL2 &= ~SELS; // set SMCLK to DCOCLK
  BCSCTL2 |= DIVS_3; // div by 8

  /* Configure TIMER_A to run on SMCLK and in Continuous Mode */
  TA0CTL = TASSEL_2 + MC_2;

  /* Configure */


}

void loop() {
  __delay_cycles(8000000);
  P1OUT ^= BIT0 + BIT6;
  
}
