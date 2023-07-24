# STM32F103xx-Simple-UART

This project contains the code required to get working serial (RS-232) character IO via the STM32 USART.<br>
<br>
Wiring<br>
USB to Serial Dongle Rx pin to STM32F030xx pin 8 (USART1-Tx)<br>
USB to Serial Dongle Tx pin to STM32F030xx pin 9 (USART1-Rx)<br>
USB to Serial Dongle Gnd pin to STM32F030xx Gnd pin 15 <br>
<br>
Setup<br>
Open a terminal program of your choice with the following settings:<br>
       Com Port: Whatever port the USB to Serial Dongle connected to USART1 is on.<br>
Comm Parameters: 115,200 baud, 8 bits, no parity, 1 stop-bit<br>
<br>
Example for minicom under Linux:<br>
`minicom -b 115200 -D /dev/ttyUSB2`<br>
<br>
When the program is first run, the letter 'H' from 'Hello World!' will be output as a single
character and then the rest of the the line ('ellow World!') will be output as a string. Then
a string prompting the user for input will be output. From this point, any user input is
echoed back to the terminal. Hitting a new line (enter) will cause '<RETURN>' to be output to
the terminal.<br>
## Contains the following routines:
+ ```void USART_putc( char c )```<br>
	Output a single character to the USART Tx pin (PA2)
+ ```void USART_puts( const char *s )```<br>
	Output a string to the USART Tx pin (PA2). Adds linefeed after string. String should be null-
  terminated (standard C string)
+ ```char USART_getc( void )```<br>
	Waits for a character on the serial port and returns the character when received.
+ ```void USART_init( void )```<br>
	Initializes USART port and Tx/Rx pins and readies the port to receive and transmit data.
