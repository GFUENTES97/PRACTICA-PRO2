#include "Cites.hh"
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>

using namespace std;

Cita::Cita(){
    autor = " ";
    titol = " ";
    contingut_cita = " ";
    ref.inicials = " ";
    ref.identificador = 0;
    x = 0;
    y = 0;
}


void Cita::mostra_frases_x_y(){
    istringstream iss(contingut_cita);
	string aux;
	int cont = x;
	bool final = true;
	while(iss >> aux){
		if (final){
		cout << cont << " " ;	
		final = false;		
		}
		else if(not final){
			if((aux[aux.size()-1] == '.') or (aux[aux.size()-1] == '!') or (aux[aux.size()-1] == '?'))
				{final = true;	cont++;}
		}
		
		cout << aux << " ";
		if (final) cout << endl;
	
	}
}

void Cita::afegir_titolC(string t){
    titol = t;
}

void Cita::afegir_autorC(string a){
    autor = a;
}

void Cita::afegir_contingutC(string cont, int a, int b){
    contingut_cita=cont;
    x = a;
    y = b;
}

void Cita::afegir_referencia(string ini, int num){
    ref.inicials = ini;
    ref.identificador = num;
}

void Cita::info_cita(){
//mostrar autor, titol, nfrase inicial, nfrase final
	cout << autor << " "
	     << '"' << titol << '"' << endl 
	     << x << "-" << y << endl;
// mostrar contingut
	mostra_frases_x_y();    
}

string Cita::consultar_autorC(){
    return autor;
}

string Cita::consultar_titolC(){
    return titol;
}

string Cita::consultar_contingutC(){
    return contingut_cita;
}

string Cita::consultar_inicials(){
    return ref.inicials;
}

int Cita::consultar_identificador(){
    return ref.identificador;
}

int Cita::consultar_x(){
    return x;
}

int Cita::consultar_y(){
    return y;
}

string Cita::consultar_referencia(){
  string refer;
  string add;
  refer = ref.inicials;
  ostringstream ss;
  ss << ref.identificador;
  add = ss.str();
  refer += add;
  return refer;
}

void Cita::mostra_cita(){
    
    cout << ref.inicials << ref.identificador << endl;
    mostra_frases_x_y();
    cout << autor;
    cout << titol << endl;
}
