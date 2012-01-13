#include "systemc.h"
#include "countdown.h"

int sc_main( int sc_argc, char *sc_argv[] )
{
    // Elaboration
    countdown U0("U0");
    
    // Simulation
    sc_start();
    
    // Cleanup
    return 0;    
}
