#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

#ifndef SHAYEXCEPTION_PP
#define SHAYEXCEPTION_PP

	class Shay:public runtime_error{
		public:
			
			Shay(char*msg):runtime_error(msg){
			}//Constructor sobrecargado
	};
#endif
