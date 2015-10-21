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
#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

void disp_init(void);
void disp_putc(u8 c);
void disp_puts(u8 line, char *s);

#endif
/* EOF */
