/* 
 * Exercise 3.2
 * 
 * Write a program to read data from a file using the unified string
 * representation and store them in an array of sc_uint<W>. Output the
 * values as SC_DEC and SC_HEX_SM.
 */

// How much data?
// Just integers?

#include "systemc.h"

#include <fstream>
#include <string>

using std::string;

#define ARRAY_SIZE 10
#define INT_SIZE 12

int main(int argc, char *argv[] )
{
	sc_uint<INT_SIZE> numbers [ARRAY_SIZE];
	
	// Read numbers from a file.
	ifstream infile("numbers.data");
	if( !infile ) {
		cerr << "Unable to read file numbers.data" << endl;
		exit(1);
	}

	int i = 0;
	for( i=0; i < ARRAY_SIZE; i++ ) {
		infile >> numbers[i];
	}
	infile.close();
	
	// Print out what we've got
	cout << "Read  " << i << " numbers." << endl;
	while( --i >= 0 ) {
		cout << "  [" << i << "]"
			<< " " << numbers[i].to_string(SC_DEC)
			<< " " << numbers[i].to_string(SC_HEX_SM)
			<< endl;
	}

}
