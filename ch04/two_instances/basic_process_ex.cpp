#include "basic_process_ex.h"
#include <iostream>
using std::cout;
using std::endl;

// Constructor
SC_HAS_PROCESS(basic_process_ex);
basic_process_ex::basic_process_ex(sc_module_name name)
    : sc_module(name)
{
    // Channel Allocations
    // Submodule Allocations
    // Connectivity
    // Process Registrations
    SC_THREAD(my_thread_process);
   
};

//
// Process Implementations
//
void basic_process_ex::my_thread_process(void) {
    cout << "my_thread_process() executed within" 
         << name() // sc_module instance name
         << endl;
}


//
// Helper Implementations
//
