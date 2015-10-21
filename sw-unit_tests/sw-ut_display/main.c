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
#include "display.h"

static int but_value(void);

int main(void)
{
    int i;
    int line_count;

    hw_init();
    uart_init();
    
    uart_puts("Exstina-50 - Display Unit Test\r\n");
    uart_crlf();
    
    disp_init();
    
    /* Show line 1 */
    disp_puts(3, "   Exstina 50   ");
    /* Wait a short time */
    for (i = 0; i < 0x10000; i++)
        ;
    /* Show line 4 */
    disp_puts(0, "Display test 0.2");
    
    line_count = 0;

    while(1)
    {
        while (but_value() == 0)
            ;
        if (but_value() & 2)
        {
            disp_puts(line_count & 0x03, "Button 0        ");
            line_count ++;
        }
        if (but_value() & 8)
        {
            disp_puts(line_count & 0x03, "Button 1        ");
            line_count ++;
        }
        while (but_value() != 0)
            ;
    }
}

static int but_value(void)
{
    int v;
    v  = reg_rd(GPIO_IDR(GPIOA));
    v &= 0x0A;
    v ^= 0x0A;
    return v;
}

/* EOF */
