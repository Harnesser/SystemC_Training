/* 
 * Exercise 3.2
 * 
 * Write a program to read data from a file using the unified string
 * representation and store them in an array of sc_uint<W>. Output the
 * values as SC_DEC and SC_HEX_SM.
 */

#include "systemc.h"

#include <fstream>
#include <string>

using std::string;

int main(int argc, char *argv[] )
{
	ifstream infile("numbers.data");
	if( !infile ) {
		cerr << "Unable to read file numbers.data" << endl;
		exit(1);
	}

	string first_line;
	infile>>first_line;

	cout << "First Line:" << first_line << endl;

	infile.close();
}
