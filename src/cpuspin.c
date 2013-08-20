/* Copyright (c) 2013, Vrai Stacey
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSIZE 1024

void fillbuffer ( int * buffer, size_t numvals )
{
    size_t idx;
    for ( idx = 0; idx < numvals; ++idx )
        buffer [ idx ] = rand ( );
}

void usage ( )
{
    fprintf ( stderr,
        "Usage: cpuspin seconds\n\n"
        "Will max out a single CPU for the specified number of seconds.\n"
        "Performs division and sqrt calculations over a non-repeated set\n"
        "of random numbers.\n" );
    exit ( 1 );
}

int main ( int argc, char * argv [ ] )
{
    int buffer [ BUFSIZE ];
    int seconds;
    time_t endtime;
    double current, last;
    size_t idx;

    if ( argc != 2 || *argv [ 1 ] == '-' )
        usage ( );

    if ( ( seconds = atoi ( argv [ 1 ] ) ) < 1 )
    {
        fprintf (
            stderr,
            "Seconds value must be a positive, non-zero integer.\n\n" );
        usage ( );
    }

    srand ( ( endtime = time ( 0 ) + seconds ) );
    while ( endtime > time ( 0 ) )
    {
        fillbuffer ( buffer, BUFSIZE );

        last = ( double ) buffer [ 0 ];
        for ( idx = 1; idx < BUFSIZE; ++idx, last = current )
        {
            current = buffer [ idx ];
            buffer [ idx ] = sqrt ( current / last );
        }
    }

    return 0;
}

