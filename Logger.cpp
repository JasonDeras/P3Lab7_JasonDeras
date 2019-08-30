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
        vector<Log*>logs;
		
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
		
		void addLog(Log *log){
            logs.push_back(log);
		}//Agrega un log al vector
            
        vector<Log*> getLogs(){
            return this->logs;
        }//Get del vector de los logs 

		void remLog(int p){
            logs.erase(logs.begin()+p);
        }//Remueve un solo log
        
        int getN(){
            return logs.size();
        }//Retorna el el tamaño del arreglo
        
        void Escribir(){
        	
			string usuario;
        	string cmd;
        	int num_log;
        	
			fstream escribir(nom_archivo,ios::out|ios::binary|ios::app);
		
			if(!escribir){
				cout<<"Problema con apertura del archivo\n";
				system("pause");
				return ;
			}//Mira si el archivo se puede abrir
			escribir.seekp(0,ios::end);	
			for(int i=0;i<logs.size();i++){
				usuario=logs.at(i)->getUsuario();
				cmd=logs.at(i)->getCmd();
				num_log=i;
				Log log(usuario,cmd,num_log);
				escribir.write(reinterpret_cast<char*>(&log),sizeof(log));
			}
			escribir.close();
			
		}//Fin del metodo escribir
	
		void Cargar(){
		
			system("cls");
		
			ifstream leer(nom_archivo,ios::in|ios::binary);
			Log l;
			int cont=0;
		
			if(!leer){
				cout<<"Problema con la apertura del arhcivo\n";
				system("pause");
				return ;
			}//Mira si el archivo se puede abrir
		
			leer.seekg(0,ios::beg);
		
			while(!leer.eof()){
			
				if(cont==0){
					cont++;
				}else{
					cout<<endl;
					l.print();
					cout<<endl;
				}
				leer.read(reinterpret_cast<char*>(&l),sizeof(l));
			}//Fin del while que lee el archivo
		
			leer.close();
			system("pause");
		
		}//Fin del metodo de cargar
			    
        ~Logger(){
		}//Fin del destructor    
};
#endif
