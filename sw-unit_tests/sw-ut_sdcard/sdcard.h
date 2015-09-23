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
#ifndef SDCARD_H
#define SDCARD_H

#define CMD00  0 /* GO_IDLE_STATE     */
#define CMD08  8 /* SEND_IF_COND      */
#define CMD17 17 /* READ_SINGLE_BLOCK */
#define CMD58 58 /* READ_OCR          */
#define CMD59 59 /* CRC_ON_OFF        */

int sd_init(void);
int sd_read(u32 address, u8 *buf);

#endif
