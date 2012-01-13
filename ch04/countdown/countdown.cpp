#include "countdown.h"
#include "systemc.h"

// Constructor
SC_HAS_PROCESS(countdown);
countdown::countdown(sc_module_name name)
    : sc_module(name) 
{
    SC_THREAD(process);
};

// Main Process
void countdown::process(void)
{
    char *stages[] = { "GO!!!", "Set", "Ready" };
    
    for(int i=3; i>0; i-- ) {
        printf("%d : %s\n", i, stages[i-1]);
    }
    
}


