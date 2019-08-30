#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include "Log.cpp"
using namespace std;

#ifndef LOGGER_CPP
#define LOGGER_CPP

class Logger{
	
	protected:
		
		char usuario [50];
		char n_archivo[50];
		int n_log;
		vector <Log*> logs;
		
	public:
		
		Logger(){
		}//fin constructor vacio
		
		Logger(string usuario, string n_archivo, int n_log){
			setUsuario(usuario);
			setN_Archivo(n_archivo);
			this->n_log=n_log;
		}//fin constructor sobrecargado
		
		string getUser()const{
			return this->usuario;
		}//Get del Usuario
		
		void setUsuario(string usuario1){
			
			const char *ptrusuario = usuario1.data();
			
			int n = usuario1.size();
			
			n= n < 50 ? n:49;
			
			strncpy(usuario, ptrusuario, n);
			
			usuario[n] = '\0';
			
		}//Set del usuario
		
		string getN_archivo()const{
			return n_archivo;
		}//Get del nombre del archivo
		
		void setN_Archivo(string n_archivo1){
			
			const char *ptrn_archivo = n_archivo1.data();
			
			int n = n_archivo1.size();
			
			n = n < 50 ? n:49;
			
			strncpy(n_archivo, ptrn_archivo, n);
			
			n_archivo[n] = '\0';
			
		}//Get del nombre del archivo
		
		int getN_log()const{
			return n_log;
		}//Get del numero de logs
		
		void setN_log(int n_log){
			this->n_log=n_log;
		}//Set del numero de logs
		
		vector <Log*> getLogs(){
			return this->logs;
		}//Get del vector de logs
		
		void addLog(Log* l){
			logs.push_back(l);
		}//Agrega un solo nodo de log
		
		int getN(){
			logs.size();
		}//Retorna el tamño del vector de logs
		
		void setVectLogs( vector <Log*> logs){
			this->logs=logs;
		}//Set del vector de logs
		
		void Escribir(){//inicio metodo escribir
		
			fstream escribir(n_archivo, ios::out | ios::binary | ios::app);
			
			if(!escribir){//inicio if problemas
				cout<<"Problemas con apertura de archivo \n";
				system("pause");
				return ;
			}//IF si tuvo problemas al abrir el archivo
			
			string usuario;
			string cmd;
			int n_log;
			
			for(int i=0; i<getN(); i++){//inicio for escribe
				usuario = logs.at(i)->getUsuario();
				cmd = logs.at(i)->getCmd();
				n_log = i;
				Log log(usuario,cmd,n_log);
				
				escribir.seekp(0, ios::end);
				escribir.write(reinterpret_cast<char*>(&log), sizeof(log));
				
				escribir.close();
			}//fin for escribe
		}//fin metodo escribir
		
		void Cargar(){//inicio metodo listar
			Log x;
			ifstream leer(n_archivo, ios::in | ios::binary);
			
			if(!leer){//inicio if problemas
				cout<<"Problemas con la apertura del archivo\n";
				system("pause");
				return ;
			}//fin if problemas
			
			leer.seekg(0, ios::beg);
			
			leer.read(reinterpret_cast<char*>(&x), sizeof(x));
			
			while(!leer.eof()){//inicio while
			
				leer.read(reinterpret_cast<char*>(&x), sizeof(x));
				
				cout<<endl;
				x.print();
				cout<<endl;
				leer.read(reinterpret_cast<char*>(&x), sizeof(x));
				
			}//fin while
			
			leer.close();
		}//fin metodo listar
		
		void clear(vector<Log*> x){
			x.clear();
			if(!x.empty()){
				x.clear();
			}//Se asegura que esta vacio
		}//Metodo que limpiar el vector de logs

		
		~Logger(){
		}//Destructor
};

#endif
