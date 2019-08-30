#include <iostream>
#include <stdexcept>
#include <vector>
#include <exception>
#include "Consola.cpp"
#include "Exception.cpp"
#include <stdexcept>
#include <exception>

using namespace std;

	int main(){
	string usuario;
	cout<<"Ingrese el usaurio: ";
	cin>>usuario;
	Consola *x=new Consola(usuario,"./logs.bin");
	
	try{
		x->error();
		x=NULL;
		delete x;
	}catch(Shay &e){
		cout<<e.what()<<endl;
	}
	system("pause");
	return 0;
	}//Fin del main
