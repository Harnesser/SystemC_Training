#include "two_processes.h"
#include "systemc.h"

#include <iostream>

// Constructor
SC_HAS_PROCESS(two_processes);
two_processes::two_processes(sc_module_name name) 
    : sc_module(name)
{
    SC_THREAD(wiper_thread);
    SC_THREAD(blinker_thread);
};


void two_processes::wiper_thread(void)
{
    while(true) {
        cout << "\\\\" << endl;        
        wait(500, SC_MS);
        cout << "//" << endl;
        wait(500, SC_MS); 
    }
};

void two_processes::blinker_thread(void)
{
    while(true) {
        cout << "*" << endl;
        wait(300, SC_MS);
    }
};


