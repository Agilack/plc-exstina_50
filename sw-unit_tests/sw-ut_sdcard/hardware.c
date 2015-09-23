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

#ifdef USE_HSE
static void hw_setup_clock(void);
#endif

void hw_init(void)
{
#ifdef USE_HSE
    hw_setup_clock();
#endif
    
    /* Enable AFIO */
    reg_set(RCC_APB2ENR, 0x01);
    
    /* Reset interrupt controller */
    reg_clr(EXTI_IMR,  0xFFFFFFFF); /* Interrupt Mask Register */
    reg_clr(EXTI_EMR,  0xFFFFFFFF); /* Event Mask Register */
}

#ifdef USE_HSE
static void hw_setup_clock(void)
{
    /* Activate HSE */
    reg_set(RCC_CR, 0x00010001);
    /* Wait the activation complete */
    while ((reg_rd(RCC_CR) & 0x00020000) == 0)
        ;

    /* Configure PLL */
    reg_set(RCC_CFGR, 0x001D2400); /* pll=72Mhz,APB1=36Mhz,APB2=36Mhz,AHB=72Mhz */
    reg_set(RCC_CR,   0x01000000); /* enable the pll */
    /* wait for it to come on */
    while ((reg_rd(RCC_CR) & 0x03000000) == 0)
        ;

    /* Set SYSCLK as PLL */
    reg_set(RCC_CFGR, 0x00000002);
    /* Wait until switch complete */
    while ((reg_rd(RCC_CFGR) & 0x00000008) == 0)
        ;

    return;
}
#endif

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
