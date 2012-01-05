#ifndef BASIC_PROCESS_EX_H
#define BASIC_PROCESS_EX_H

#include "systemc.h"
SC_MODULE(basic_process_ex) {
    SC_HAS_PROCESS(basic_process_ex);
    basic_process_ex(sc_module_name instname)
    : sc_module(instname)
    {
        SC_THREAD(my_thread_process);
    }
    void my_thread_process(void);
};

#endif
