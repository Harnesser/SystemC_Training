#include "systemc.h"

SC_MODULE(missing_event)
{
    SC_CTOR(missing_event) {
        SC_THREAD(B_thread);
        SC_THREAD(A_thread);
        SC_THREAD(C_thread);
    }
    
    void A_thread(void) {
        a_event.notify();
        cout << "A sent a_event!" << endl;
    }
    
    void B_thread(void) {
        wait(a_event);
        cout << "B got a_event!" << endl;
    }
    
    void C_thread(void) {
        wait(a_event);
        cout << "C got a_event!" << endl;
    }
    
    sc_event a_event;
    
};

int sc_main( int sc_argc, char *argv[] )
{
    missing_event U0("U0");
    sc_start();
    return 0;  
}


