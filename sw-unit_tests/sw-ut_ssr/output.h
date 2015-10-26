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
#ifndef OUTPUT_H
#define OUTPUT_H

#define OUT_OFF    0
#define OUT_ON     1
#define OUT_UNDEF -1

#define OUT_1   1
#define OUT_2   2
#define OUT_3   3
#define OUT_4   4

int  out_status(int n);
void out_set   (int n, int state);
void out_toggle(int n);

#endif
