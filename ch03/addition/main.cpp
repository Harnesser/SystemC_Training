//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DESCRIPTION
//   This example illustrates problems with data sizes and conversions.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
using std::cout;
using std::endl;

#include <systemc>
using namespace sc_dt;
const char* simulation_name = "bigint";

int sc_main(int argc, char* argv[]) 
{
  {
    cout << std::string(40,'-') << endl;
    cout << "INFO: Adding 3 shorts to produce an int" << endl;
    short a = 32767;
    short b = 32767;
    short c = 32767;
    cout << "INFO: short a = " << a << endl;
    cout << "INFO: short b = " << b << endl;
    cout << "INFO: short c = " << c << endl;
    cout << "INFO: a + b + c = " << a + b + c << " OK" << endl;
    short ssum = a + b + c;
    cout << "INFO: a + b + c = ssum = " << ssum << " OOPS" << endl;
    int csum = a + b + c;
    cout << "INFO: a + b + c = csum = " << csum << " OK" << endl;
  }
  {
    cout << std::string(40,'-') << endl;
    cout << "INFO: Adding 3 sc_ints to produce a bigger sc_int" << endl;
    sc_int<3> d(3);
    sc_int<5> e(15);
    sc_int<5> f(14);
    cout << "INFO: sc_int<3> d = " << d << endl;
    cout << "INFO: sc_int<5> e = " << e << endl;
    cout << "INFO: sc_int<5> f = " << f << endl;
    cout << "INFO: d + e + f = " << d + e + f << " OK" << endl;
    sc_int<7> sum = d + e + f;
    cout << "INFO: d + e + f = sum = " << sum << " OK" << endl;
  }
  {
    cout << std::string(40,'-') << endl;
    cout << "INFO: Adding 3 sc_ints to produce an sc_bigint" << endl;
    sc_int<64> g("0x7000000000000000");
    sc_int<64> h("0x7000000000000000");
    sc_int<64> i("0x7000000000000000");
    sc_bigint<70> bigsum;
    cout << "INFO: sc_int<3> g = " << g << endl;
    cout << "INFO: sc_int<5> h = " << h << endl;
    cout << "INFO: sc_int<5> i = " << i << endl;
    cout << "INFO: g + h + i = " << g + h + i << " OOPS" << endl;
    bigsum = g + h + i;
    cout << "INFO: g + h + i = bigsum = " << bigsum << " OOPS" << endl;
    bigsum = sc_bigint<70>(g) + h + i;
    cout << "INFO: g + h + i = bigsum = " << bigsum << " OK" << endl;
  }
  //
  cout << std::string(40,'-') << endl;
  cout << "INFO: The end" << endl;
  return 0;
}

// Portions COPYRIGHT (C) 2003-2009 ESLX Inc.----------------------   //
// Permission granted for anybody to use this example provided this   //
// acknowledgement of ESLX Inc. remains.                              //
//-----------------------------------------------------------------   //
