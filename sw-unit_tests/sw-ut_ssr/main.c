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
#include "display.h"

void serial_menu(void);
void disp_menu  (void);
static int but_value(void);

int menu_sel;
int out1, out2, out3, out4;

int main(void)
{
    int c;
    int v;

    hw_init();
    uart_init();
    
    hw_out_init();
    
    uart_puts("Exstina-50 - Solid State Relay (SSR) Unit Test\r\n");
    uart_crlf();
    
    disp_init();
    disp_puts(3, "SSR UnitTest 0.1");
    
    menu_sel = 0;
    out1 = 0; out2 = 0; out3 = 0; out4 = 0;
    
    while(1)
    {
        serial_menu();
        disp_menu();
        while ( ( ! uart_isready()) && (but_value() == 0) )
            ;
        
        if (but_value() != 0)
        {
            /* If left button has been pressed */
            if (but_value() & 2)
            {
                menu_sel++;
                if (menu_sel == 5)
                    menu_sel = 1;
            }
            /* If right button has been pressed  */
            else if (but_value() & 8)
            {
                if (menu_sel == 1)
                {
                    if (out1)
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x00080000);
                        out1 = 0;
                    }
                    else
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x00000008);
                        out1 = 1;
                    }
                }
                /* If currently selected output is 2 */
                if (menu_sel == 2)
                {
                    if (out2)
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x00100000);
                        out2 = 0;
                    }
                    else
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x00000010);
                        out2 = 1;
                    }
                }
                /* If currently selected output is 3 */
                if (menu_sel == 3)
                {
                    if (out3)
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x01000000);
                        out3 = 0;
                    }
                    else
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x00000100);
                        out3 = 1;
                    }
                }
                /* If currently selected output is 4 */
                if (menu_sel == 4)
                {
                    if (out4)
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x02000000);
                        out4 = 0;
                    }
                    else
                    {
                        reg_wr(GPIO_BSRR(GPIOB), 0x00000200);
                        out4 = 1;
                    }
                }
            }
            while( but_value() )
                ;
            continue;
        }
        
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
                    out1 = 0;
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000008);
                    uart_puts("ON\r\n");
                    out1 = 1;
                }
                break;
            case '2':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-2 ");
                if (v & 0x10)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00100000);
                    uart_puts("OFF\r\n");
                    out2 = 0;
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000010);
                    uart_puts("ON\r\n");
                    out2 = 1;
                }
                break;
            case '3':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-3 ");
                if (v & 0x0100)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x01000000);
                    uart_puts("OFF\r\n");
                    out3 = 0;
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000100);
                    uart_puts("ON\r\n");
                    out3 = 1;
                }
                break;
            case '4':
                v = reg_rd( GPIO_ODR(GPIOB) );
                uart_puts("Set SSR-4 ");
                if (v & 0x0200)
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x02000000);
                    uart_puts("OFF\r\n");
                    out4 = 0;
                }
                else
                {
                    reg_wr(GPIO_BSRR(GPIOB), 0x00000200);
                    uart_puts("ON\r\n");
                    out4 = 1;
                }
                break;
            default:
                uart_puts("Unknown command\r\n");
        }
    }
}

void serial_menu(void)
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

void disp_menu(void)
{
    char str_labels[17];
    char str_state[17];
    
    /* Insert output-1 label */
    if (menu_sel == 1) strcpy(str_labels +  0, "OUT1");
    else               strcpy(str_labels +  0, " O1 ");
    /* Insert output-2 label */
    if (menu_sel == 2) strcpy(str_labels +  4, "OUT2");
    else               strcpy(str_labels +  4, " O2 ");
    /* Insert output-3 label */
    if (menu_sel == 3) strcpy(str_labels +  8, "OUT3");
    else               strcpy(str_labels +  8, " O3 ");
    /* Insert output-4 label */
    if (menu_sel == 4) strcpy(str_labels + 12, "OUT4");
    else               strcpy(str_labels + 12, " O4 ");

    /* Insert output-1 value */
    if (out1) strcpy(str_state +  0, " ON ");
    else      strcpy(str_state +  0, " -- ");
    /* Insert output-2 value */
    if (out2) strcpy(str_state +  4, " ON ");
    else      strcpy(str_state +  4, " -- ");
    /* Insert output-3 value */
    if (out3) strcpy(str_state +  8, " ON ");
    else      strcpy(str_state +  8, " -- ");
    /* Insert output-4 value */
    if (out4) strcpy(str_state + 12, " ON ");
    else      strcpy(str_state + 12, " -- ");
    
    /* Update the labels line on display */
    disp_puts(1, str_labels);
    disp_puts(0, str_state);
}

static int but_value(void)
{
    int v;
    v  = reg_rd(GPIO_IDR(GPIOA));
    v &= 0x0A;
    v ^= 0x0A;
    return v;
}

char *strcpy(char *dest, const char *src)
{
    char *dsave = dest;
        while(*src)
        {
                *dest = *src;
                src++;
                dest++;
        }
        *dest = 0;
        return dsave;
}
/* EOF */
