//  main.c
//  Test program for STM32F030-CMSIS-USART-lib.c Minimalist UART
//  
//  Version 1.0   7/24/2023   Updated core files and comments
//
//  ==========================================================================================
//  Hardware: STM32030xx, USB-Serial dongle
//  Software: PuTTY (or other serial terminal program)
//  Mike Shegedin, 04/2023
//
//  Summary:
//  --------
//  Set up the USART for UART (RS-232) IO with character RxTx capability.
//  Initiall output "Hello World" with first 'H' output as a character and
//  'ello World!" output as a string. Then echo any terminal input back to
//  the terminal. Indicate <Return> by displaying '<RETURN>'.
//
//  USART1_Tx = PA2, Alternate Function 1
//  USART1_Rx = PA3, Alternate Function 1
//
//  Baudrate Calculation
//  --------------------
//  Assuming the internal RC clock: f(CK) = 8 MHz
//  Mantissa = whole part of f(CK) / (16 * Baud)
//  Fraction = remainder of above * 16
//      f(CK)    Baud     Mantissa   Fraction
//      -----   -------   --------   --------
//      8 MHz     9,600      52          1
//              115,200       4          5
//              460,800       1          1
//              500,000       1          0
//
//  If calculating in program:
//      uartDiv  = freqClk / baud
//      mantissa = uartDiv / 16
//      fraction = uartDiv % 16
//
//  Steps to Set Up UART on STM32F030xx:
//  ------------------------------------
//  1. Enable GPIO Port A via RCC->AHBENR
//  2. Set PA2 and PA3 as Alternate Functions via GPIOA->MODER
//  3. Set Alternate Function 1 for PA2 and PA3 via GPIOA->AFR[0]
//  4. Enable USART1 perpheral via RCC->APB2ENR
//  5. Set Baudrate via USART1->BRR
//  6. Enable (turn on) Tx, Rx, and USART via USART1->CR1

#include "stm32f030x6.h"  // Primary CMSIS header file
#include "STM32F030-CMSIS-USART-lib.c"

int
main( void )
{
    char c; // Will be character to echo

    USART_init();

    // Send some text...
    USART_putc('H');            // Output one character 'H' to terminal
    USART_puts("ello World!");  // Output rest of 'ellow World!'

    USART_puts("Now type stuff on the terminal to be echoed...");

    while( 1 )            // Endless looop to echo anything typed into the termainal
    {                     // back out to the terminal. Echo '<RETURN>' at each CR character.
        c = USART_getc();
        USART_putc(c);
        if( c == '\r' )
            USART_puts("<RETURN>");
    }
    return 1;
} // End main.c
