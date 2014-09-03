#ifndef __DIE_H__
#define __DIE_H__

/*******************************************************************\
* Basic struct and function for modeling a die (coin, etc.)         *
* Copyright (C) 2013-2014, Sam Stuewe                               *
*                                                                   *
* This program is free software; you can redistribute it and/or     *
* modify it under the terms of the GNU General Public License       *
* as published by the Free Software Foundation; either version 2    *
* of the License, or (at your option) any later version.            *
*                                                                   *
* This program is distributed in the hope that it will be useful,   *
* but WITHOUT ANY WARRANTY; without even the implied warranty of    *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      *
* GNU General Public License for more details.                      *
*                                                                   *
* You should have received a copy of the GNU General Public License *
* along with this program; if not, write to the Free Software       *
* Foundation, Inc., 51 Franklin Street, Fifth Floor,                *
* Boston, MA  02110-1301, USA.                                      *
\*******************************************************************/

// Libraries //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Forward Declarations //
struct die {
    unsigned int sides;
    unsigned int face;
};

void
die_roll (struct die * die) {

    unsigned int r;

    do {
        r = rand();
    } while ( r >= die->sides );

    die->face = r + 1;
}

#endif // __DIE_H__
// vim: set ts=4 sw=4 et:
