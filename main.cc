//#include GFUENTES97 

#include "Conjunt_textos.hh"
#include "Text.hh"
#include "Cites.hh"

#ifndef NO_DIAGRAM
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#endif

using namespace std;

int main(){
 
string entrada, op, opaux, p1,p2; //entrada, operador, operador aux, paraula1, paraula2...
int n,m;
Conjunt_textos conj;


while(getline(cin,entrada)){
    istringstream iss(entrada);
    iss >> op;
    if(op != "sortir"){

    if(op == "afegir"){
        iss >> opaux; // opaux == "text" o "cita"
        if(opaux == "text") conj.afegir_text();
        else if(opaux == "cita"){
            iss >> n >> m;
            conj.afegir_cita(n,m);
            }
        }
    
    
    else if(op == "triar") {
        iss >> opaux; // opaux == "text"    
        string comanda;
        getline(cin,comanda);
        conj.triar_text(comanda);
        
    }
    
    else if(op == "eliminar"){
        iss >> opaux; // opaux == "text" o "cita"
        if(opaux == "text") conj.esborrar_text();
        else if(opaux == "cita"){
            iss >> opaux; //opaux == referencia
            conj.eliminar_cita(opaux);
        }
    }
    
    else if(op == "substitueix"){
    
        iss >> p1 >> opaux >> p2; // opaux == "per"
        conj.consultar_text().substitueix(p1,p2);
    }
    
    else if(op == "textos"){
        iss >> opaux; // opaux == "<autor>"      
        conj.textos_autor(opaux);
    }
    
    else if(op == "tots"){
        iss >> opaux;
        if(opaux == "textos") conj.tots_textos();
        else if(opaux == "autors") conj.tots_autors();
    }
    
    else if(op == "info"){
        iss >> opaux; //opaux == " ?" o "cita"
        if(opaux == " ?")conj.info_text();
        else if(opaux == "cita"){
        iss >> opaux; // opaux == referencia
        conj.consultar_cita(opaux).info_cita();            
        }
    }
    
    else if(op == "autor"){
        iss >> opaux; //opaux = " ?"
        cout << conj.consultar_text().consultar_autor() <<endl;
    }
    
    else if(op == "contingut"){
        iss >> opaux; //opaux == " ?"
        conj.consultar_text().mostra_contingut();
    }
    
    else if(op == "frases"){
        if(iss >> n >> n){
        conj.consultar_text().mostra_frases_x_y(n,m);
        }
        else{
        conj.consultar_text().frases_expressio();
        }
    }
    
    else if(op == "nombre"){
        iss >> opaux >> opaux;
        if(opaux == "frases")cout << conj.consultar_text().nombre_de_frases() << endl ; 
        else if(opaux == "paraules") cout<< conj.consultar_text().nombre_de_paraules() << endl;
    }
    
    else if(op == "taula"){
        iss >> opaux >> opaux; // "de" "frequencies"
        conj.consultar_text().mostra_taula_frequencies();
    }
    
    else if(op == "cites"){ //mostra cites de l'ultim text triat
        iss >> opaux; //opaux == "<autor>" o " ?"
        if(opaux == " ?") conj.cites_text();
        else if(opaux == "autor"){
	  string aut;
	  iss >> aut;
	  while(iss >> opaux) aut += " " + opaux;
	  conj.mostra_cites_autor(aut);
	}
      
    }
    
    else if(op == "totes"){
    iss >> opaux >> opaux; // opaux == "cites" " ?"
    conj.mostra_totes_cites();
    }
    
    
}
else break;
}   
    
}


/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:49:52
 * 
 */