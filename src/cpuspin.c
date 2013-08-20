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

