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

static void spi1_ios(void);
static void spi2_ios(void);

void spi_init(void)
{
	/* nothing to do ... */
}

void spi_open(u32 port)
{
	u32 cr1 = port + SPI_CR1;
	
	if (port == SPI1)
	{
		spi1_ios();
		reg_set(RCC_APB2ENR, 0x1000); /* Activate SPI1 */
	}
	else if (port == SPI2)
	{
		spi2_ios();
		reg_set(RCC_APB1ENR, 0x4000); /* Activate SPI2 */
	}
	else
		return;
	
	reg_set(cr1, 0x300); /* Set SSM (NSS soft) and SSI */
	reg_set(cr1,  0x08); /* Set BR=001 (fclk/4) */
	reg_set(cr1,  0x44); /* Set SPI Enable in master mode */
	return;
}

void spi1_cs(int en)
{
	vu32 *nss;
	
	nss = (vu32 *)GPIO_BSRR(GPIOA); /* GPIOA_BSRR */
	if (en)
		*nss = 0x00100000; // NSS = 0
	else
	{
		spi1_wait();
		*nss = 0x00000010; // NSS = 1
		spi1_flush();
	}
}

u8 spi1_rd(void)
{
	u32 value;
	
	/* Wait for RX buffer filled */
	while ((*(vu32 *)SPI1_SR & 0x01) == 0)
		;

	/* Wait until BSY is cleared */
	while (*(vu32 *)SPI1_SR & 0x80)
		;

	value = *(vu32 *)SPI1_DR;
	return value;
}

void spi1_wr(u32 data)
{
	/* Wait for TX buffer empty */
	while ((*(vu32 *)SPI1_SR & 0x02) == 0)
		;
	
	/* Write the value */
	*(vu32 *)SPI1_DR = data;
}
void spi1_wait(void)
{
  	/* Wait until BSY is cleared */
	while (*(vu32 *)SPI1_SR & 0x80)
		;
	
	/* Wait until the SCK is LOW (bsy cleared after sck rise) */
	while( (u32)*(vu32 *)(GPIOA + 0x08) & 0x20)
		;
}
void spi1_flush(void)
{
	/* Wait until BSY is cleared */
	while (*(vu32 *)SPI1_SR & 0x80)
		;
	
	/* Clean the RX buffer */
	if (*(vu32 *)SPI1_SR & 0x01)
	{
		while (*(vu32 *)SPI1_SR & 0x01)
			*(vu32 *)SPI1_DR;
		return;
	}
	return;
}

void spi2_cs(int en)
{
	vu32 *nss;
	
	nss = (vu32 *)GPIO_BSRR(GPIOB);
	
	if (en)
		*nss = 0x10000000; // NSS = 0
	else
	{
		spi2_wait();
		*nss = 0x00001000; // NSS = 1
		spi2_flush();
	}
}

u8 spi2_rd(void)
{
	u32 value;
	
	/* Wait for RX buffer filled */
	while ((*(vu32 *)SPI2_SR & 0x01) == 0)
		;
	
	/* Wait until BSY is cleared */
	while (*(vu32 *)SPI2_SR & 0x80)
		;
	
	value = *(vu32 *)SPI2_DR;
	return value;
}

void spi2_wr(u32 data)
{
	/* Wait for TX buffer empty */
	while ((*(vu32 *)SPI2_SR & 0x02) == 0)
		;
	
	/* Write the value */
	*(vu32 *)SPI2_DR = data;
}

void spi2_wait(void)
{
	/* Wait until BSY is cleared */
	while (*(vu32 *)SPI2_SR & 0x80)
		;
	
	/* Wait until the SCK is LOW (bsy cleared after sck rise) */
	while( (u32)*(vu32 *)(GPIOB + 0x08) & 0x2000)
		;
}

void spi2_flush(void)
{
	/* Wait until BSY is cleared */
	while (*(vu32 *)SPI2_SR & 0x80)
		;
	
	/* Clean the RX buffer */
	if (*(vu32 *)SPI2_SR & 0x01)
	{
		while (*(vu32 *)SPI2_SR & 0x01)
			*(vu32 *)SPI2_DR;
		return;
	}
	return;
}

static void spi1_ios(void)
{
	u32 val;
	
	reg_set(RCC_APB2ENR, 0x04); /* Activate GPIOA */
	
	/* Configure NSS pin (PA4) */
	val  = reg_rd(GPIOA);
	val &= 0xFFF0FFFF;
	val |= 0x00030000; /* output, 50MHz, push-pull */
	reg_wr(GPIOA, val);
	reg_wr(GPIO_BSRR(GPIOA), (0x01 << 4)); /* Disable SS (nss=1) */
	
	/* Configure SCK pin (PA5) */
	val  = reg_rd(GPIOA);
	val &= 0xFF0FFFFF;
	val |= 0x00B00000; /* output, 50MHz, AF, push-pull */
	reg_wr(GPIOA, val);
	
	/* Configure MOSI pin (PA7) */
	val  = reg_rd(GPIOA);
	val &= 0x0FFFFFFF;
	val |= 0xB0000000; /* output, 50MHz, AF, push-pull */
	reg_wr(GPIOA, val);
	
	/* Configure MISO pin (PA6) */
	val  = reg_rd(GPIOA);
	val &= 0xF0FFFFFF;
	val |= 0x04000000; /* input, floating */
	reg_wr(GPIOA, val);
}

static void spi2_ios(void)
{
	u32 val;

	reg_set(RCC_APB2ENR, 0x08); /* Activate PortB */
	
	/* Configure NSS pin (PB12) */
	val  = reg_rd(GPIOB + 0x04);
	val &= 0xFFF0FFFF;
	val |= 0x00030000; /* output, 50MHz, push-pull */
	reg_wr(GPIOB+0x04, val);
	reg_wr(GPIO_BSRR(GPIOB), (0x01 << 12)); /* Disable SS (nss=1) */
	
	/* Configure SCK pin (PB13) */
	val  = reg_rd(GPIOB + 0x04);
	val &= 0xFF0FFFFF;
	val |= 0x00B00000; /* output, 50MHz, AF, push-pull */
	reg_wr(GPIOB+0x04, val);
	
	/* Configure MOSI pin (PB15) */
	val  = reg_rd(GPIOB + 0x04);
	val &= 0x0FFFFFFF;
	val |= 0xB0000000; /* output, 50MHz, AF, push-pull */
	reg_wr(GPIOB+0x04, val);
	
	/* Configure MISO pin (PB14) */
	val  = reg_rd(GPIOB + 0x04);
	val &= 0xF0FFFFFF;
	val |= 0x04000000; /* input, floating */
	reg_wr(GPIOB + 0x04, val);
}
/* EOF */
