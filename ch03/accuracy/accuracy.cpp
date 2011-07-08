/*
 * Exercise 3.4: Accuracy
 * 
 *  Write a program to explore data accuracy of fixed-point numbers
 * for an application needing to add two sine waves with amplitudes of
 * 14 and 22, where the larger of the two is also 2.5 times the 
 * frequency of the smaller.  There are 512 samples over the longest 
 * period.  Assume you are limited to 12 bits for both the input and
 * the output.  Try different modes. HINT: Start modelling using double.
 * Progress to using sc_fixed.
 */

#define SC_INCLUDE_FX
#include "systemc.h"

int main(int argc, char *argv[] )
{
	cout << "Hello!" << endl;
}
