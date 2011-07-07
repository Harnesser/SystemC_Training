#include "systemc.h"

SC_MODULE(Hello_SystemC) {
	
	SC_CTOR(Hello_SystemC)
	{
		SC_THREAD(main_thread);
	}
	
	void main_thread(void)
	{
		SC_REPORT_INFO("Marty/thing", " Hello SystemC World!");
	}
};

int sc_main(int sc_argc, char* sc_argv[])
{
	// Hello_SystemC instance
	Hello_SystemC HelloWorld_i("HelloWorld_i");
	
	sc_start(); // invoke the simulator
	
	return 0;
}

		
