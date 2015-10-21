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

static void hw_init_buttons(void);

void hw_init(void)
{
    /* Enable AFIO */
    reg_set(RCC_APB2ENR, 0x01);
    
    hw_init_buttons();
}

static void hw_init_buttons(void)
{
    u32 val;
    
    /* Activate GPIOA */
	reg_set(RCC_APB2ENR,   0x04);

	/* Configure input GPIOs */
	val  = reg_rd(GPIOA);
	val &= 0xFFFFFF0F; /* Mask for PA1 (SW0) */
	val |= 0x00000040; /* Config for PA1 (input, floating) */
	val &= 0xFFFF0FFF; /* Mask for PA3 (SW1) */
	val |= 0x00004000; /* Config for PA1 (input, floating) */
	reg_wr(GPIOA, val);

}

u32 reg_rd(u32 reg)
{
	return ( *(volatile u32 *)reg );
}
void reg_wr(u32 reg, u32 value)
{
	*(volatile u32 *)reg = value;
}
void reg_set(u32 reg, u32 value)
{
	*(volatile u32 *)reg = ( *(volatile u32 *)reg | value );
}
void reg_clr(u32 reg, u32 value)
{
	*(volatile u32 *)reg = ( *(volatile u32 *)reg & ~value );
}
/* EOF */
