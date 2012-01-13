#include "systemc.h"
#include "two_processes.h"

int sc_main( int sc_argc, char *sc_argv[] )
{
    two_processes car("car");
    sc_start(2000, SC_MS);
    return 0;    
};
