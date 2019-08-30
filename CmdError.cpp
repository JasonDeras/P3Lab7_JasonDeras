#include <iostream>
#include <stdexcept>
#include <exception>
#include <string.h>
using namespace std;

#ifndef SHAYEXCEPTION_PP
#define SHAYEXCEPTION_PP

	class CmdError:public runtime_error{
		public:
			
			CmdError(string msg):runtime_error(msg){
			}//Constructor sobrecargado
	};
#endif
