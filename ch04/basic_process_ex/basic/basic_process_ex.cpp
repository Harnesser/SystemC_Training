#include "basic_process_ex.h"
#include <iostream>
using std::cout;
using std::endl;

void basic_process_ex::my_thread_process(void) {
    cout << "my_thread_process() executed within" 
         << name() // sc_module instance name
         << endl;
}
