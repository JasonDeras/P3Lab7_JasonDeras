#include<iostream> 
#include<string.h> 
#include "Logger.cpp"
#include "Exception.cpp"
#ifndef CONSOLA_CPP
#define CONSOLA_CPP

using namespace std;

class Consola{
	
      private:
      	
        char usuario[50];
        Logger *logger;
              
      public:
      	
      	
        Consola(){	
		 	logger=new Logger();
	   	}//Constructor simple
	   	
		Consola(string usuario,string nombre){
			
			setUsuario(usuario);
			logger=new Logger(usuario,nombre,logger->getN());
			
		}//Segundo constructor sobrecargado
		
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
		
		void setLogger(Logger *logger){
			this->logger=logger;
		}//Fin del metodo set logger
		   
		Logger* getLogger(){
			return logger;
		}//Fin del metodo get del logger
		
		void error(){
			
			string com;
			
			while(true){
				cout<<"Ingrese un comando: ";
				cin>>com;
				int error=system((com.c_str()));
				if(error){
					throw Shay("El cmd no es correcto");
					exit(0);
				}else{
				
				}
			}
			
		}//Metodo de error en caso que el comando no se valido
		
        ~Consola(){
		}//Fin del destructor    
};
#endif
