/*******************************************************************\
* Basic utility to roll dice                                        *
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
#include <getopt.h>
#include "die.h"

// Forward Declarations //
#define CIEL_COLOR		"\x1b[32m"
#define FLOOR_COLOR		"\x1b[31m"
#define DEFAULT_COLOR	"\x1b[39m"

// Usage //
void 
usage (int error) {
    fputs("Usage: dice [options]\n\n"
          "Options:\n"
		  "  -c, --color\t\thighlight natural floors and ceilings\n"
          "  -h, --help\t\tprint this help and exit\n"
          "  -n, --number\t\tset number of dice to roll\n"
          "  -s, --sides\t\tset number of sides per die\n",
          ( error ? stderr : stdout ));
    exit(error);
}

// Main Function //
int
main (int argc, char * argv []) {
	char flag_color = 0;
    unsigned int flag_number = 1;
    unsigned int flag_sides = 6;

    static struct option os [] = {
        /* Flags */
		{ "color",	 no_argument,		  0, 'c' },
        { "help",    no_argument,         0, 'h' },
        // quiet option
        /* Switches */
        { "number",  required_argument,   0, 'n' },
        { "sides",   required_argument,   0, 's' }
    };

    for ( int i = 0, c = 0; 
          c != -1; c = getopt_long(argc, argv, "chn:s:", os, &i) ) {

        switch ( c ) {
			case 'c':
				flag_color ++;
				break;

            case 'h':
                usage(0);
                break;

            case 'n':
                sscanf(optarg, "%u", &flag_number);
                break;

            case 's':
                sscanf(optarg, "%u", &flag_sides);
                break;
        }
    }

    struct die dice [flag_number];
    srand(time(NULL));

    for ( int i = 0; i < flag_number; i ++ ) {
        dice[i].sides = flag_sides;
        die_roll(&dice[i]);
		if ( flag_color ) {
			if ( dice[i].face == 1 ) {
				printf(FLOOR_COLOR);
			} else if ( dice[i].face == flag_sides ) {
				printf(CIEL_COLOR);
			}
		}
        printf("%d ", dice[i].face);

		if ( flag_color ) { printf(DEFAULT_COLOR); };
    } printf("\n");

    return 0;
}

// vim: set ts=4 sw=4 et:
