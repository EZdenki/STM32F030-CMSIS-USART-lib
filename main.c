//  ==========================================================================================
//  main.c for STM32F030-CMSIS-USART-lib.c
//  ------------------------------------------------------------------------------------------
//  Test program for STM32F030-CMSIS-USART-lib.c Minimalist UART
//  ------------------------------------------------------------------------------------------
//  https://github.com/EZdenki/STM32F030-CMSIS-USART-lib
//  Released under the MIT License
//  Copyright (c) 2023
//  Mike Shegedin, EZdenki.com
//    Version 1.2   28 Aug 2023   Added USART port parameter to USART_init and added
//                                USART_puti, USART_puth, and USART_pollc routines.
//    Version 1.1   16 Aug 2023   Added baud rate as parameter to USART_init.
//    Version 1.0   24 Jul 2023   Updated core files and comments
//  ------------------------------------------------------------------------------------------
//  Target Devices: STM32F030xx and a USB-Serial dongle
//  Software: PuTTY for Windows or Linux (or any other serial terminal program)
//  ------------------------------------------------------------------------------------------
//  Hardware Setup:
//    USART1_Tx = PA2 (pin 8)
//    USART1_Rx = PA3 (pin 9)
//  ------------------------------------------------------------------------------------------
//  Functional Summary:
//    Set up the USART for UART (RS-232) IO with character RxTx capability.
//    Initially output "Hello World" with first 'H' output as a character and 'ello World!"
//    output as a string. Then echo any terminal input back to the terminal.
//    Indicate <Return> by displaying '<RETURN>'.
//
//  See STM32F030-CMSIS-USART-lib.c for details on how to set up USART.
//  ==========================================================================================

#include "stm32f030x6.h"  // Primary CMSIS header file
#include "STM32F030-CMSIS-USART-lib.c"

int
main( void )
{
    char c; // Will be character to echo

    USART_init( USART1, 115200 );

    // Send some text...
    USART_putc('H');              // Output one character 'H' to terminal
    USART_puts("ello World!/n");  // Output rest of 'ellow World!'

    USART_puts("Now type stuff on the terminal to be echoed...\n");

    while( 1 )            // Endless looop to echo anything typed into the termainal
    {                     // back out to the terminal. Echo '<RETURN>' at each CR character.
        c = USART_getc();
        USART_putc(c);
        if( c == '\r' )
            USART_puts("<RETURN>\n");
    }
    return 1;
} // End main.c
