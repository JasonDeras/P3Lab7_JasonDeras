#include<iostream> 
#include<string.h> 
#ifndef CONSOLA_CPP
#define CONSOLA_CPP

using namespace std;

class Consola{
	
      private:
      	
        char usuario[50];
        Logger logger;
              
      public:
      	
      	
        Consola(){	 	
	   	}//Fin del primer constructor sobrecargado
        
		Consola(string usuario,Logger logger){
			
			this->setUsuario(usuario);
			this->logger=logger;
			
		}//Fin del segundo constructor sobrecargado
		
		void setUsuario(string usuario_c){
            
            const char *ptrusuario = usuario_c.data();
            
            int numeroCaracteres = usuario_c.size();
            
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            
            strncpy(usuario, ptrmarca, numeroCaracteres);
            
            usuario[numeroCaracteres] = '\0';
            
        }//Set del usuario
        
        string getUsuario() const{
            return usuario;
        }//Get del usuario
		
		void setLogger(Logger logger){
			this->logger=logger;
		}//Fin del metodo set logger
		   
		Logger getLogger(){
			return logger;
		}//Fin del metodo get del logger
		
		void print(){
            logger.print();
        }//Fin del metodo print
			    
        ~Consola(){
        	logger.print();
		}//Fin del destructor    
};
#endif
