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

static void hw_init_buttons(void);

void hw_init(void)
{
    /* Enable AFIO */
    reg_set(RCC_APB2ENR, 0x01);
    
    hw_init_buttons();
    
    /* Reset interrupt controller */
    reg_clr(EXTI_IMR,  0xFFFFFFFF); /* Interrupt Mask Register */
    reg_clr(EXTI_EMR,  0xFFFFFFFF); /* Event Mask Register */
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

void hw_out_init(void)
{
    u32 val;
    
    /* Activate GPIOB */
	reg_set(RCC_APB2ENR, 0x08);
	
	/* Disable JTAG/SWD to get full access to PB3 and PB4 */
	reg_set(AFIO_MAPR, 0x04000000);

    /* Set outputs default to OFF */
    reg_wr(GPIO_BSRR(GPIOB), 0x03180000);

	/* Configure OUT-1 and OUT-2 pins */
	val  = reg_rd(GPIOB);
	val &= 0xFFFF0FFF; /* Mask for OUT-1 (PB3) */
	val |= 0x00002000; /* Set PB3 as output, push-pull, 2MHz */
	val &= 0xFFF0FFFF; /* Mask for OUT-2 (PB4) */
	val |= 0x00020000; /* Set PB4 as output, push-pull, 2MHz */
	reg_wr(GPIOB, val);

	/* Configure OUT-3 and OUT-4 pins */
	val  = reg_rd(GPIOB + 4);
	val &= 0xFFFFFFF0; /* Mask for OUT-3 (PB8) */
	val |= 0x00000002; /* Set PB8 as output, push-pull, 2MHz */
	val &= 0xFFFFFF0F; /* Mask for OUT-4 (PB9) */
	val |= 0x00000020; /* Set PB9 as output, push-pull, 2MHz */
	reg_wr(GPIOB + 4, val);

    return;
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
