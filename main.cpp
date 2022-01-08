#include <iostream>
#include "Command.h"
#include <exception>
/* run this program using the console pauser or add your own getch, system("pause") or input 

loop */


int main(int argc, char** argv) {
	using std::endl;
	using std::cout; 
	Command::show();
	while(true) {
		
		try {
			Command::run();
		} catch(const char * str) {
			cout<<str<<endl<<endl;
			Command::show(); 
		}
	
	}


	return 0;
}

