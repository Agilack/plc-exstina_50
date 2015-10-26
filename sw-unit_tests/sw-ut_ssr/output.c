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
#include "output.h"

/**
 * Get the current state of an output
 * 
 * @param int Output ID
 * @return int Current state of output
 */
int out_status(int n)
{
    int v;
    int status = OUT_UNDEF;
    
    v = reg_rd( GPIO_ODR(GPIOB) );
    
    switch(n)
    {
        case OUT_1:
            if (v & 0x08)
                status = OUT_ON;
            else
                status = OUT_OFF;
            break;

        case OUT_2:
            if (v & 0x10)
                status = OUT_ON;
            else
                status = OUT_OFF;
            break;

        case OUT_3:
            if (v & 0x100)
                status = OUT_ON;
            else
                status = OUT_OFF;
            break;

        case OUT_4:
            if (v & 0x200)
                status = OUT_ON;
            else
                status = OUT_OFF;
            break;
    }
    return status;
}

/**
 * Change the state of a specific output
 * 
 * @param int Output ID
 * @param int New state/value for the output
 */
void out_set(int n, int state)
{
    switch(n)
    {
        case OUT_1:
            if (state == OUT_ON)
                reg_wr(GPIO_BSRR(GPIOB), 0x00000008);
            else
                reg_wr(GPIO_BSRR(GPIOB), 0x00080000);
            break;
        
        case OUT_2:
            if (state == OUT_ON)
                reg_wr(GPIO_BSRR(GPIOB), 0x00000010);
            else
                reg_wr(GPIO_BSRR(GPIOB), 0x00100000);
            break;
        
        case OUT_3:
            if (state == OUT_ON)
                reg_wr(GPIO_BSRR(GPIOB), 0x00000100);
            else
                reg_wr(GPIO_BSRR(GPIOB), 0x01000000);
            break;
        
        case OUT_4:
            if (state == OUT_ON)
                reg_wr(GPIO_BSRR(GPIOB), 0x00000200);
            else
                reg_wr(GPIO_BSRR(GPIOB), 0x02000000);
            break;
    }
}

/**
 * Invert the state of a specific output
 * 
 * @param int Output ID
 */
void out_toggle(int n)
{
    int state;
    
    state = out_status(n);
    
    if (state == OUT_ON)
        out_set(n, OUT_OFF);
    else
        out_set(n, OUT_ON);
}

/* EOF */
