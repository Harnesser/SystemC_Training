#include "systemc.h"

SC_MODULE(ordered_events) {

    SC_CTOR(ordered_events) {
        SC_THREAD(B_thread);
        SC_THREAD(A_thread);
        SC_THREAD(C_thread);
    };
    
    void A_thread() 
    {
        while(true){
            a_event.notify(SC_ZERO_TIME);
            cout << "A sent a_event!" << endl;
            wait(c_event);
            cout << "A got c_event!" << endl;           
        }
    }
    
    void B_thread() {
        while(true) {
            b_event.notify(SC_ZERO_TIME);
            cout << "B sent b_event!" << endl;
            wait(a_event);
            cout << "B got a_event!" << endl;
        }
    }
    
    void C_thread() {
        c_event.notify(SC_ZERO_TIME);
        cout << "C sent c_event!" << endl;
        wait(b_event);
        cout << "C got b_event!" << endl;
        }
    }
   
    sc_event a_event, b_event, c_event;    
};

