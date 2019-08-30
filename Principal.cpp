#include <iostream>
#include "CmdError.cpp"
#include "Consola.cpp"

using namespace std;

int main(){
	
	string usuario;
	cout<<"Usuario: ";
	cin>>usuario;
	
	Consola* cons = new Consola(usuario, "logs.bin");
	
	try{
		cons->cmd();
	}
	catch(CmdError &e){
		cout<<e.what();
	}//Fin del try catch
	
	delete cons;
	return 0;
	
}//fin main

