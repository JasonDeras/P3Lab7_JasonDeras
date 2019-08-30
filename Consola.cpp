#include <iostream>
#include <string>
#include <string.h>
#include "CmdError.cpp"
#include "Logger.cpp"
#include <direct.h>

using namespace std;

#ifndef CONSOLA_CPP
#define CONSOLA_CPP

class Consola{
	
	protected:
		
		string usuario;
		Logger* logger;
		int num;
		string n_archvo;
		
	public:
		
		Consola(){
		}//constructor simple
		
		Consola(string usuario, string n_archvo){
			this->usuario=usuario;
			logger = new Logger(usuario, n_archvo, logger->getN());
		}//Constructor sobrecargado
		
		int error(){
			
			Log* logs;
			string com;
			
			while (true) {
				
				int val = 0;
				cout<<"Ingrese el cmd: ";
				cin>>com;
				
				if(com == "cls"){
					logs = new Log(usuario,com,logger->getN());
					logger->addLog(logs);
					logger->Escribir();
					system("pause");
				}//IF que valida si el comando inresado es cls
				
				if(com == "exit"){
					logs = new Log(usuario,com,logger->getN());
					logger->addLog(logs);
					logger->Escribir();
					exit(0);
					system("pause");
				}//Valida si el comando ingresado es exit
				
				if (com == "listar") {
					logger->Cargar();
				} else if (com.size() > 3 && com.substr(0, 3) == "cd ") {
					val = _chdir(com.substr(3, com.size()).c_str());
				} else {
					val = system(com.c_str());
				}//Los if de listar el archivo binario
				
				logs = new Log(usuario,com,logger->getN());
				logger->addLog(logs);
				logger->Escribir();
				
				if (val) {
					logger->clear(logger->getLogs());
					delete logger;
					throw CmdError("Comando de cmd no es valido");
					exit(0);
				}//Si da error lo cierra
			}//While repetitivo
			
		}//Fin del metodo de los comandos erroneo
		
		~Consola(){
		}//Destructor
};

#endif
