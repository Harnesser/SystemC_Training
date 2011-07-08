/*
 * Exercise 3.3: Speed test
 *  Explore how the datatype selected for calculations affects
 * the run time of a calculation. The calculation is squaring 
 * 100,000 random numbers.
 * 
 * Notes:
 *  Define the data type on the Makefile command line ST_DATATYPE,
 * eg, 'short' or 'sc_int<8>'
 */

#ifndef ST_DATATYPE
	#define ST_DATATYPE this_will_break
#endif

#include <cstdlib>			// for srand(), rand() (C++ book, pg 287)
#include <ctime>			// for srand() seed

#define SC_INCLUDE_FX
#include "systemc.h"

#define MAX_CALCS 1000000

int main( int argc, char *argv [] ) 
{
	// Set randomiser seed
	srand( time(NULL) );
		
	ST_DATATYPE num, num_squared;
	for( int i=0; i < MAX_CALCS; i++ ) {
		num = rand();
		num_squared = num * num;
		if( i < 10 ) {
			cout << num << " squared is " << num_squared << endl;
		}
	}
	
}


