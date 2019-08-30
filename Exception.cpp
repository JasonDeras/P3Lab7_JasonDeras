#include <iostream>
#include <stdexcept>
#include <exception>
#include <string.h>
using namespace std;

#ifndef SHAYEXCEPTION_PP
#define SHAYEXCEPTION_PP

	class Shay:public runtime_error{
		public:
			
			Shay(string msg):runtime_error(msg){
			}//Constructor sobrecargado
	};
#endif
