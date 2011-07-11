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
 *
 * NOTES:
 *  I'm thinking of generating the sinewaves using doubles, then
 * converting them to sc_fixed, and printing both out to a file in
 * CSV format so I can have a peek in soffice? Or compute the errors?
 * I'm not 100% sure what I'm to be doing here... not sure what
 * this exercise is getting at.
 */

#define SC_INCLUDE_FX
#include "systemc.h"

#include <cmath>
#include <fstream>

#define NUM_POINTS 512
double amp_1 = 14;
double freq_1 = 345;
double amp_2 = 22;
double freq_2 = 2.5 * freq_1;
double t_delta = ( 1.0 / freq_1 ) / NUM_POINTS;

sc_fixed<12,6> wave_1[NUM_POINTS];
sc_fixed<12,6> wave_2[NUM_POINTS];
sc_fixed<12,6> wave_out[NUM_POINTS];

template <class T> void gen_wave( T wave[], double freq, double amp);
void write_csv();


int main(int argc, char *argv[] )
{
	gen_wave(wave_1, amp_1, freq_1);
	gen_wave(wave_2, amp_2, freq_2);
	
	for(int i=0; i<NUM_POINTS; i++) {
		wave_out[i] = wave_1[i] + wave_2[i];
	}
	
	write_csv();
}


template <class T> void gen_wave( T wave[], double amp, double freq)
{
	for(int i=0; i<NUM_POINTS; i++ ) {
		wave[i] = amp * sin( 2.0 * M_PI * freq * (t_delta * i ));
	}
}


void write_csv()
{
	ofstream outfile("numbers.data");
	for(int i=0; i<NUM_POINTS; i++ ) {
		outfile << wave_1[i] << "," 
			<< wave_2[i] << "," << wave_out[i] << endl;
	}
	outfile.close();
}
