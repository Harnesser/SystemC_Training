#include "systemc.h"

SC_MODULE(two_processes) {
    void wiper_thread(void);
    void blinker_thread(void);
    
    SC_CTOR(two_processes);
};
