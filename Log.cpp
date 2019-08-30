#include<iostream> 
#include<string.h> 

#ifndef LOG_CPP
#define LOG_CPP

using namespace std;


class Log{
	
      private:
            
        char usuario[50];
        char cmd[50];
        int num_log;
              
      public:
      	
      	
        Log(){	 	
	   	}//Fin del primer constructor sobrecargado
        
		Log(string usuario,string cmd,int num_log){
			
			setUsuario(usuario);
			setCmd(cmd);
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
		
		void setCmd(string cmd_c){
			
			const char *ptrcmd = cmd_c.data();
            
            int numeroCaracteres = cmd_c.size();
            
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            
            strncpy(cmd, ptrcmd, numeroCaracteres);
            
            cmd[numeroCaracteres] = '\0';
			
		}//Set del nombre del commando
		   
		string getCmd() const{
            return cmd;
        }//Get del nombre del commando
		   
		void setNum_Log(int num_log){
			this->num_log=num_log;
		}//Set del numero de log   
		   
		int getNum_Log(){
			return num_log;
		}//Get del numero de log 
		
		void print(){
			cout<<"num: "<<num_log
            <<", usuario: "<<usuario
            <<", cmd: "<<cmd<<endl;
        }//Fin del metodo print
			    
        ~Log(){
		}//Fin del destructor    
};
#endif
