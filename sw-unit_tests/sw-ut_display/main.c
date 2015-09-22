/**
 * Exstina-50 - Display unit-test
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
#include "hardware.h"
#include "main.h"
#include "uart.h"

static void disp_putc(u8 c);
static void disp_puts(u8 line, char *s);

int main(void)
{
    u8  c;
    int i;
    
    hw_init();
    uart_init();
    
    uart_puts("Exstina-50 - Display Unit Test\r\n");
    uart_crlf();
    
    for (i = 0; i < 0x10000; i++)
        ;
    /* Reset display state machine */
    disp_putc('\r');
    /* Clear display */
    disp_putc(0x1B);
    
    /* Wait a short time */
    for (i = 0; i < 0x10000; i++)
        ;
    /* Show line 1 */
    disp_puts(3, "   Exstina 50   ");
    /* Wait a short time */
    for (i = 0; i < 0x10000; i++)
        ;
    /* Show line 4 */
    disp_puts(0, "Display test 0.1");
    
    while(1)
    {
        while ( ! uart_isready())
            ;
        c = uart_rd();
        if (c == '0')
            disp_putc('\n');
        if (c == '1')
            disp_puts(3, "/o\\o/o\\o/");
        if (c == '2')
            disp_puts(2, " Display Unit-test");
        if (c == '4')
            disp_puts(0, "Hello World !");
    }
}

static void disp_puts(u8 line, char *s)
{
    disp_putc('0' + line);
    while(*s)
    {
        disp_putc(*s);
        s++;
    }
    disp_putc('\n');
}

static void disp_putc(u8 c)
{
	while ( (reg_rd(UART2_SR) & 0x80) != 0x80)
		;
	reg_wr(UART2_DR, c);
}

/* EOF */
