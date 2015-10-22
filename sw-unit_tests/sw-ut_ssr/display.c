/**
 * Exstina-50 - Solid State Relay unit-test
 *
 * Copyright (c) 2015 Saint-Genest Gwenael <gwen@agilack.fr>
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation. (See COPYING.GPL for details.)
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#include "display.h"
#include "uart.h"

/**
 * Initialisation of the display driver
 * 
 */
void disp_init(void)
{
    int i;
    
    uart2_init();
    
    for (i = 0; i < 0x10000; i++)
        ;
    /* Reset display state machine */
    disp_putc('\r');
    /* Clear display */
    disp_putc(0x1B);

    /* Wait a short time */
    for (i = 0; i < 0x10000; i++)
        ;
}

/**
 * Send one byte to the display
 * 
 * @param c value to send
 */
void disp_putc(u8 c)
{
	while ( (reg_rd(UART2_SR) & 0x80) != 0x80)
		;
	reg_wr(UART2_DR, c);
}

/**
 * Send a text string to the display
 * 
 * @param line : Line number where the string must be written
 * @param s    : String to write
 */
void disp_puts(u8 line, char *s)
{
    disp_putc('0' + line);
    while(*s)
    {
        disp_putc(*s);
        s++;
    }
    disp_putc('\n');
}

/* EOF */
