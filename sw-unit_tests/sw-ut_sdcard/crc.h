/**
 * Exstina-50 - SDCARD unit-test
 *
 * Saint-Genest Gwenael <gwen@agilack.fr>
 * Based on sdcard example by Domen Puncer, Visionect, d.o.o.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation. (See COPYING.GPL for details.)
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef CRC_H
#define CRC_H

#include "hardware.h"

u16 crc16(const u8 *p, int len);
u8  crc7 (const u8 *p, int len);
u8  crc7_one(u8 t, u8 data);

#endif
