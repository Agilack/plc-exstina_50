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
#ifndef __HARDWARE_H
#define __HARDWARE_H

#define UART2 ((u32)0x40004400)
#define AFIO  ((u32)0x40010000)
#define EXTI  ((u32)0x40010400)
#define GPIOA ((u32)0x40010800)
#define GPIOB ((u32)0x40010C00)
#define GPIOC ((u32)0x40011000)
#define UART1 ((u32)0x40013800)
#define RCC   ((u32)0x40021000)

#define RCC_CR      RCC
#define RCC_CFGR    (RCC + 0x04)
#define RCC_CIR     (RCC + 0x08)
#define RCC_AHBENR  (RCC + 0x14)
#define RCC_APB2ENR (RCC + 0x18)
#define RCC_APB1ENR (RCC + 0x1C)

#define GPIO_CRL(port)  port
#define GPIO_CRH(port)  (port+0x04)
#define GPIO_IDR(port)  (port+0x08)
#define GPIO_ODR(port)  (port+0x0c)
#define GPIO_BSRR(port) (port+0x10)

#define AFIO_MAPR       (AFIO + 0x04)
#define AFIO_EXTI_CR1   (AFIO + 0x08)
#define AFIO_EXTI_CR2   (AFIO + 0x0C)
#define AFIO_EXTI_CR3   (AFIO + 0x10)
#define AFIO_EXTI_CR4   (AFIO + 0x14)

#define EXTI_IMR   (EXTI  + 0x00)
#define EXTI_EMR   (EXTI  + 0x04)
#define EXTI_RTSR  (EXTI  + 0x08)
#define EXTI_FTSR  (EXTI  + 0x0C)
#define EXTI_PR    (EXTI  + 0x14)

#define UART_SR    (UART1 + 0x00)
#define UART_DR    (UART1 + 0x04)
#define UART_BRR   (UART1 + 0x08)
#define UART_CR1   (UART1 + 0x0C)

#define UART2_SR   (UART2 + 0x00)
#define UART2_DR   (UART2 + 0x04)
#define UART2_BRR  (UART2 + 0x08)
#define UART2_CR1  (UART2 + 0x0C)

#include "types.h"

void hw_init(void);
void hw_out_init(void);

/* Low level register functions */
void reg_wr (u32 reg, u32 value);
u32  reg_rd (u32 reg);
void reg_set(u32 reg, u32 value);
void reg_clr(u32 reg, u32 value);

#endif
