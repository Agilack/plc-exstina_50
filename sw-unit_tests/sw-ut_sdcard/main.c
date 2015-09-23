/**
 * Exstina-50 - SDCARD unit-test
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
#include "spi.h"
#include "uart.h"

int sd_init(void);
int sd_read(u32 address, u8 *buf);

int main(void)
{
    int c;
    
    hw_init();
    uart_init();
    
	uart_puts("Exstina-50 - SDCARD Unit Test\r\n");
    
    spi_open(SPI2);
	
	uart_puts(" - Try to init SDCARD ... ");
    c = sd_init();
    if (c)
        while(1)
            ;
    uart_puts("done.\r\n");
    
    uart_puts(" - Try to read first sector ...\r\n");
    sd_read(0, (u8 *)0x00);

	while(1);
}
/* EOF */
