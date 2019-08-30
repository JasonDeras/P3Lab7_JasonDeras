#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#ifndef LOG_CPP
#define LOG_CPP

class Log{
	
	protected:
		
		char usuario [50];
		char cmd[50];
		int n_log;
		
	public:
		
		Log(){
		}//Constructor vacio
		
		Log(string usuario, string cmd, int n_log){
			setUsuario(usuario);
			setCmd(cmd);
			this->n_log=n_log;
		}//Constructor sobrecargado
		
		string getUsuario()const{
			return this->usuario;
		}//Get del Usuario
		
		void setUsuario(string usuario1){
			
			const char *ptrusuario = usuario1.data();
			
			int n = usuario1.size();
			
			n= n < 50 ? n:49;
			
			strncpy(usuario, ptrusuario, n);
			
			usuario[n] = '\0';
			
		}//Set del usuario
		
		string getCmd()const{
			return cmd;
		}//Get del nombre del archivo
		
		void setCmd(string cmd1){
			
			const char *ptrcmd = cmd1.data();
			
			int n = cmd1.size();
			
			n = n < 50 ? n:49;
			
			strncpy(cmd, ptrcmd, n);
			
			cmd[n] = '\0';
			
		}//Get del nombre del archivo
		
		int getN_log()const{
			return n_log;
		}//Get del numero de logs
		
		void setN_log(int n_log){
			this->n_log=n_log;
		}//Set del numero de logs
		
		void print(){
			cout<<"num: "<<n_log<<", usuario: "<<usuario<<", cmd: \""<<cmd<<"\""<<endl;
		}//Metodo print
		
		~Log(){
		}//Destructor
		
};

#endif
