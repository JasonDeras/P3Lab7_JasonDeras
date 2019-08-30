#include <iostream>
#include <stdexcept>
#include <vector>
#include <exception>
#include "Consola.cpp"
#include "Exception.cpp"

using namespace std;

	int main(){
	string usuario;
	cout<<"Ingrese el usaurio: ";
	cin>>usuario;
	Consola x=new Consola(usuario,"./logs.bin");
	
	
	
	system("pause");
	return 0;
	}//Fin del main
