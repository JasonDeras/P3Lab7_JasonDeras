#include<iostream> 
#include<string.h> 
#include<bits/stdc++.h>
#include<string.h>
#include<fstream>
#include "Log.cpp"

#ifndef LOGGER_CPP
#define LOGGER_CPP

using namespace std;


class Logger{
	
      private:
            
        char usuario[50];
        char nom_archivo[50];
        int num_log;
        vector<Log>logs;
		  
      public:
      	
      	
        Logger(){	 	
	   	}//Fin del primer constructor sobrecargado
        
		Logger(string usuario,string nom_archivo,int num_log){
			
			setUsuario(usuario);
			setNom_Archivo(nom_archivo);
			this->num_log=num_log;
			
		}//Fin del constructor sobrecargado
		
		void setUsuario(string usuario_c){
            
            const char *ptrusuario = usuario_c.data();
            
            int numeroCaracteres = usuario_c.size();
            
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            
            strncpy(usuario, ptrusuario, numeroCaracteres);
            
            usuario[numeroCaracteres] = '\0';
            
        }//Set del usuario
        
        string getUsuario() const{
            return usuario;
        }//Get del usuario
		
		void setNom_Archivo(string nom_archivo_c){
			
			const char *ptrnom_archivo = nom_archivo_c.data();
            
            int numeroCaracteres = nom_archivo_c.size();
            
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            
            strncpy(nom_archivo, ptrnom_archivo, numeroCaracteres);
            
            nom_archivo[numeroCaracteres] = '\0';
			
		}//Set del nombre del archivo
		   
		string getNom_Archivo() const{
            return nom_archivo;
        }//Get del nombre del archivo
		   
		void setNum_Log(int num_log){
			this->num_log=num_log;
		}//Set del numero de log   
		   
		int getNum_Log(){
			return num_log;
		}//Get del numero de log 
		
		void addLog(Log log){
            logs.push_back(log);
		}//Agrega un log al vector
            
        vector<Log> getLogs(){
            return this->logs;
        }//Get del vector de los logs 

		void remLog(int p){
            logs.erase(logs.begin()+p);
        }//Remueve un solo log
        
		void print(){
			
        	for(int i=0;i<logs.size();i++){
        		logs.at(i).print();
			}//Fin del for de impresion de los logs 
		   
        }//Fin del metodo print
			    
        ~Logger(){
		}//Fin del destructor    
};
#endif
