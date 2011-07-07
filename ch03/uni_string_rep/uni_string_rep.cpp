/*
 * SystemC's Unified String Representations'
 */

#define SC_INCLUDE_FX
#include "systemc.h"
#include <iomanip>
#include <string>

using namespace std;
using namespace sc_dt;

int main(int argc, char *argv[] )
{
	cout << "INFO: Starting uni_string_rep" << endl;
	
	sc_numrep NR[] = {
		SC_NOBASE,
		SC_DEC,
		SC_BIN,
		SC_BIN_US,
		SC_BIN_SM,
		SC_OCT,
		SC_OCT_US,
		SC_OCT_SM,
		SC_HEX,
		SC_HEX_US,
		SC_HEX_SM,      // Signed magnitude?
		SC_CSD			// Can this really be canonical-signed-digit?
	};
		
	sc_int<5> INT[] = { -13, -3, -1, 0, 1, 3, 13 };
	sc_fixed<7,3> FXD[] = { -13.3, -2.7, -1.0, 0.0, 1.0, 3.3, 13.7 };
	sc_fixed<7,3> FSD[] = { "-13.3", "-2.7", "-1.0", "0.0", "1.0",
		"3.3", "13.7" };
		
	string q("'");
	
	for( unsigned iTC=0; iTC != 7; iTC++ )
		for( unsigned iNR=1; iNR != 12; iNR++ ) 
		{
			cout << "sc_int       " << std::setw(7) << INT[iTC] 
				 << " output as "   << std::setw(9) << NR[iNR]
				 << " = "           << std::setw(15) 
				 << q + INT[iTC].to_string(NR[iNR], true ) + q
				 << std::endl;
				 
			cout << "sc_fixed     " << std::setw(7) << FXD[iTC]
				 << " output as "   << std::setw(9) << NR[iNR]
				 << " = "           << std::setw(15) 
				 << q + FXD[iTC].to_string(NR[iNR], true ) + q
				 << std::endl;
				 
			cout << "sc_fixed str " << std::setw(7) << FSD[iTC]
				 << " output as "   << std::setw(9) << NR[iNR]
				 << " = "           << std::setw(15)
				 << q + FSD[iTC].to_string(NR[iNR], true ) + q
				 << std::endl;
		}

	// Logic stuff
	sc_lv<8> LV1;
	LV1 = 15;
	cout << " LV1= " << LV1;
	
	sc_lv<8> LV2("0101xzxz");
	cout << " LV2= " << LV2;
	cout << endl;
	
	// Fixed-point again
	sc_fixed<5,3> fix1;
	fix1 = -3.3;
	cout << " fix1 = " << fix1;
	cout << " SC_BIN = " << fix1.to_string(SC_BIN);
	cout << " SC_HEX = " << fix1.to_string(SC_HEX);
	cout << " SC_HEX = " << fix1.to_string(SC_HEX, false); // no prefix
	cout << endl;
	
	cout << "INFO: uni_string_rep COMPLETED" << endl;
	return 0;
}
