/**
 * Exstina-50 - Outputs unit-test
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
#include "output.h"

void serial_menu(void);
void disp_menu  (void);
static int but_value(void);

int menu_sel;

int main(void)
{
    int c;

    hw_init();
    uart_init();
    
    hw_out_init();
    
    uart_puts("Exstina-50 - Outputs Unit Test\r\n");
    uart_crlf();
    
    disp_init();
    disp_puts(3, "Outputs Test 0.1");
    
    menu_sel = 0;
    
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
                switch(menu_sel)
                {
                    case 1:
                        out_toggle(OUT_1);
                        break;
                    case 2:
                        out_toggle(OUT_2);
                        break;
                    case 3:
                        out_toggle(OUT_3);
                        break;
                    case 4:
                        out_toggle(OUT_4);
                        break;
                }
            }
            /* Wait until all button released */
            while( but_value() )
                ;
            continue;
        }
        
        c = uart_rd();
        switch(c)
        {
            case 'a':
                uart_puts("Set ALL SSR ON\r\n");
                out_set(OUT_1, OUT_ON);
                out_set(OUT_2, OUT_ON);
                out_set(OUT_3, OUT_ON);
                out_set(OUT_4, OUT_ON);
                break;
                
            case 'n':
                uart_puts("Set ALL SSR OFF\r\n");
                out_set(OUT_1, OUT_OFF);
                out_set(OUT_2, OUT_OFF);
                out_set(OUT_3, OUT_OFF);
                out_set(OUT_4, OUT_OFF);
                break;
                
            case '1':
                uart_puts("Set SSR-1 ");
                /* Invert the output 1 state */
                out_toggle(OUT_1);
                /* Send new state to debug port */
                if (out_status(OUT_1) == OUT_ON)
                    uart_puts("ON\r\n");
                else
                    uart_puts("OFF\r\n");
                break;
                
            case '2':
                uart_puts("Set SSR-2 ");
                /* Invert the output 2 state */
                out_toggle(OUT_2);
                /* Send new state to debug port */
                if (out_status(OUT_2) == OUT_ON)
                    uart_puts("ON\r\n");
                else
                    uart_puts("OFF\r\n");
                break;
                
            case '3':
                uart_puts("Set SSR-3 ");
                /* Invert the output 3 state */
                out_toggle(OUT_3);
                /* Send new state to debug port */
                if (out_status(OUT_3) == OUT_ON)
                    uart_puts("ON\r\n");
                else
                    uart_puts("OFF\r\n");
                break;
                
            case '4':
                uart_puts("Set SSR-4 ");
                /* Invert the output 4 state */
                out_toggle(OUT_4);
                /* Send new state to debug port */
                if (out_status(OUT_4) == OUT_ON)
                    uart_puts("ON\r\n");
                else
                    uart_puts("OFF\r\n");
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
    int oval;
    
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
    oval = out_status(OUT_1);
    if (oval) strcpy(str_state +  0, " ON ");
    else      strcpy(str_state +  0, " -- ");
    /* Insert output-2 value */
    oval = out_status(OUT_2);
    if (oval) strcpy(str_state +  4, " ON ");
    else      strcpy(str_state +  4, " -- ");
    /* Insert output-3 value */
    oval = out_status(OUT_3);
    if (oval) strcpy(str_state +  8, " ON ");
    else      strcpy(str_state +  8, " -- ");
    /* Insert output-4 value */
    oval = out_status(OUT_4);
    if (oval) strcpy(str_state + 12, " ON ");
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
