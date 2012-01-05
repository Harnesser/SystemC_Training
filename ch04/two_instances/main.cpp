/* just a scratchpad for code */
#include "systemc.h"
#include "basic_process_ex.h"

int sc_main(int argc, char* argv[]) {
    // Elaboration
    basic_process_ex my_instance("my_instance");
    basic_process_ex another("another");
    
    // Run sim
    sc_start();
    // post proc.
    return 0;
}

