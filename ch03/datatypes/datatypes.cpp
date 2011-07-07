#define SC_INCLUDE_FX
#include "systemc.h"

#include <string>
#include <bitset>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::bitset;
using std::setw;

using namespace sc_dt;

int main(int argc, char* argv[]) 
{
	cout << "INFO: Starting datatypes" << endl;
	
	// Efficient native C++ datatypes
	int spark_offset;     			// 4 bytes
	unsigned repairs = 0;			// 4 bytes? 
	unsigned long mileage;			// 4 bytes? WTF?
	short int speedometer;			// 2 bytes
	float temperature;				// 4 byte floating point
	double time_of_last_request; 	// 8 byte floating point
	string license_plate;   
	
	const bool WARNING_LIGHT = true;
	enum Compass {SW,W,NW,N,NE,E,SE,S,nDir};
	bitset<nDir> obstacle; // bitset? 
	
	for( int heading=SW; heading < nDir; heading++ ) {
		cout << "Heading " << heading << " ";
		switch(heading) {
		case SW: cout << "SW"; break;
		case  W: cout << " W"; break;
		case NW: cout << "SW"; break;
		case  N: cout << " W"; break;
		case NE: cout << "SW"; break;
		case  E: cout << " W"; break;
		case SE: cout << "SW"; break;
		case  S: cout << " W"; break;
		}	
	cout << endl;
	}
	
	if( int(temperature) % 2 == 1 )
		license_plate = "Odd Temp";
		
	obstacle.set(NW);
	obstacle.set(E);
	unsigned long obstacles = obstacle.to_ulong();
	
	// SystemC integer data types
	sc_int<5>			seat_position = 3;	// 5-bit wide signed bus
	sc_uint<13>			days_SLOC(4000);    // 13-bit unsigned bus
	sc_biguint<40>		rev_SLOC;			// slow bigints for >32 bits
	
	// SystemC boolean and mulit-value data types
	// Note: sc_bit and sc_bv are probably better implemented with 
	//       bool and bitset
	bool		alarm(false);
	//sc_bit	alarm(false);
	sc_bv<23>	system_status;
	sc_logic	alarm_control;
	sc_lv<2391>	scan_chain;
	
	cout << "scan chain len = " << setw(10) << scan_chain.length() << endl;
	cout << "days_SLOC len  = " << setw(10) << days_SLOC.length() << endl;
	
	
	
}	
