# STM32F030-CMSIS-USART-lib

This project contains a library and sample code required to get working serial (RS-232) character IO via the STM32 USART.<br>
+ Note 1: The library currently only supports USART1 on the STM32F030.<br>
+ Note 2: Make sure that the USB to Serial Dongle is set for 3.3 V. **5 V from the serial dongle will destroy your microcontroller!**

## Wiring
USB to Serial Dongle Rx pin to STM32F030 pin 8 (USART1-Tx)<br>
USB to Serial Dongle Tx pin to STM32F030 pin 9 (USART1-Rx)<br>
USB to Serial Dongle Gnd pin to STM32F030 Gnd pin 15 <br>
The USB to Serial Dongle VCC pin can power the STM32F030 on pin 16 **if the output voltage of the serial dongle is 3.3 V**. 

## Setup
Open a terminal program of your choice with the following settings:<br>
       Com Port: Whatever port the USB to Serial Dongle connected to USART1 is on.<br>
Comm Parameters: 115,200 baud (default), 8 bits, no parity, 1 stop-bit<br>
<br>
Example for minicom under Linux:<br>
`minicom -b 115200 -D /dev/ttyUSB2`<br>
<br>
When the program is first run, the letter 'H' from 'Hello World!' will be output as a single
character and then the rest of the the line ('ellow World!') will be output as a string. Then
a string prompting the user for input will be output. From this point, any user input is
echoed back to the terminal. Hitting a new line (enter) will cause '<RETURN>' to be output to
the terminal.

## Contains the following routines:
+ ```void USART_putc( char c )```<br>
	Output a single character to the USART Tx pin (PA2)
+ ```void USART_puts( const char *s )```<br>
	Output a string to the USART Tx pin (PA2). Adds linefeed after string. String should be null-
  terminated (standard C string)
+ ```char USART_getc( void )```<br>
	Waits for a character on the serial port and returns the character when received.
+ ```void USART_init( uint32_t baudrate )```<br>
	Initializes USART port and Tx/Rx pins and readies the port to receive and transmit data at the specified baud rate.
