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
#include "hardware.h"
#include "main.h"
#include "uart.h"

void show_menu(void);

int main(void)
{
    int c;
    int v;

    hw_init();
    uart_init();
    
    hw_out_init();
    
    uart_puts("Exstina-50 - Solid State Relay (SSR) Unit Test\r\n");
    uart_crlf();
    
    while(1)
    {
        show_menu();
        while( ! uart_isready())
            ;
        c = uart_rd();
        switch(c)
        {
            case 'a':
                uart_puts("Set ALL SSR ON\r\n");
                reg_wr(GPIO_BSRR(GPIOB), 0x00000318);
                break;
            case 'n':
                uart_puts("Set ALL SSR OFF\r\n");
                reg_wr(GPIO_BSRR(GPIOB), 0x03180000);
                break;
            case '1':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-1 ");
                if (v & 0x08)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00080000);
                    uart_puts("OFF\r\n");
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000008);
                    uart_puts("ON\r\n");
                }
                break;
            case '2':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-2 ");
                if (v & 0x10)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00100000);
                    uart_puts("OFF\r\n");
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000010);
                    uart_puts("ON\r\n");
                }
                break;
            case '3':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-3 ");
                if (v & 0x0100)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x01000000);
                    uart_puts("OFF\r\n");
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000100);
                    uart_puts("ON\r\n");
                }
                break;
            case '4':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-4 ");
                if (v & 0x0200)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x02000000);
                    uart_puts("OFF\r\n");
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000200);
                    uart_puts("ON\r\n");
                }
                break;
            default:
                uart_puts("Unknown command\r\n");
        }
    }
}

void show_menu(void)
{
    uart_puts("Use this kays to control relays :\r\n");
    uart_puts(" '1' : toggle the state of Relay 1\r\n");
    uart_puts(" '2' : toggle the state of Relay 2\r\n");
    uart_puts(" '3' : toggle the state of Relay 3\r\n");
    uart_puts(" '4' : toggle the state of Relay 4\r\n");
    uart_puts(" 'a' : set all to ON\r\n");
    uart_puts(" 'n' : set all to OFF\r\n");
    uart_puts("\r\n >");
}
/* EOF */
