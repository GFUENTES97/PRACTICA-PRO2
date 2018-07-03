//#include GFUENTES97 

#include "Text.hh"
#include <sstream>
#include <string>
#include <map>
#include <iostream>
#include <cmath>


void Text::afegeix_titol(){

  string linea;
  getline(cin,linea);
  titol = linea;
  
}

void Text::afegeix_autor(){

  string linea;
  getline(cin,linea);
  autor = linea;
  
}

void Text::afegeix_a_la_taula(string m){

  int ult = m.size() - 1;
  if((m[ult] == '.') or (m[ult] == ',') or (m[ult] == ';') or (m[ult] == ':') or (m[ult] == '!') or (m[ult] == '?'))
      m.erase(ult);
  map<string, int>::iterator it;
  it = taula.find(m);
  if(it != taula.end()){
    int aux = it->second;
    aux++;
    taula[m] = aux;
  }
  else{
    taula.insert(pair<string, int>(m,1));
  }
  
}



void Text::afegeix_contingut(){
    
  int cont = 0, cont2 = 0;
  string linea, entrada, aux;
  int i = 0;
  while(getline(cin, entrada)){
      bool final = false;
      istringstream iss(entrada);
      while(iss >> aux){
         if(final){ 
            ++i;
            contingut[i] = linea;
            linea.erase(0,linea.size());
            cont++;
            final = false;
         }
         cont2++;        // augmentar el numero de paraules
         int ult = aux.size()-1;
         if((aux[ult] == '.') or (aux[ult] == '!') or (aux[ult] == '?')){
            linea += aux;
            final = true;            
         }
         else {
            linea += aux;
            linea += " ";
         }
   }
   ++i;
   contingut[i] = linea;
   linea.erase(0,linea.size());
   cont++;    
  }
  
 nfrases = cont;                    // cont té el numero de frases del contingut
 nparaules = cont2;                 // cont2 té el numero de parules del contingut
}


int Text::frequencia_paraula(string paraula){
  
   map<string, int>::iterator it;
   it = taula.find(paraula);
   return it->second;
}

Text::Text(){
 
  afegeix_titol();
  afegeix_autor();
  afegeix_contingut();
}


string Text::consultar_titol(){
  return titol;
}  

string Text::consultar_autor(){
  return autor; 
}

map<int, string> Text::consultar_contingut(){
  return contingut;
}

int Text::nombre_de_frases(){
 return nfrases; 
}

int Text::nombre_de_paraules(){
  return nparaules;
}


void Text::mostra_contingut(){
  int cont = 1;
  map<int, string>::iterator it = contingut.begin();
  while(it!=contingut.end()){
    cout << it->first << " ";
    cout << it->second << endl;
    it++;
    
  }
}

void Text::mostra_frases_x_y(int x, int y){
 
  while(x!=y){
    cout << x << " " << contingut[x] << endl; 
       x++;
  }
  cout << y << " " << contingut[y] << endl;
}

void Text::frases_expressio(){
  
}
/////////////////////////////////////////////////

void Text::substitueix(string paraula1, string paraula2){

int fre = frequencia_paraula(paraula1);
bool esp;
int nfrase = 0;
int tamany = paraula1.size();
 while(fre>0){
 
      nfrase++;
      int caracter = 0;     // la posicio de la frase on estem
      string aux;
      string lin = contingut[nfrase];       // la frase a tractar del contingut
      istringstream iss(lin);
      while(iss >> aux && fre>0){
          esp = false;
          int ult = aux.size()-1;
          if((aux[ult] == '.') or (aux[ult] == ',') or (aux[ult] == ';') or (aux[ult] == ':') or (aux[ult] == '!') or (aux[ult] == '?')){ aux.erase(ult); esp=1;}
          
          if(aux == paraula1){
              fre--;
              lin.erase(caracter, paraula1.size());                  //
              lin.insert(caracter, paraula2);                 // substituim la paraula a la frase i la guardem al contingut
              contingut[nfrase] = lin;      //
              caracter += paraula2.size();
          }
          else{
             if(esp) caracter += aux.size() + 2;
             else caracter += aux.size() + 1;
          }
      }        
 }
}

void Text::mostra_taula_frequencies(){ 		// CAL ORDENAR

    map<string, int>::iterator it = taula.end(); --it;
    while(it != taula.begin()){
    
      cout << it->first << " " << it->second << endl;
     --it; 
    }
    it = taula.begin();
    cout << it->first << " " << it->second << endl;
}

map<string, int> Text::retorna_taula(){

  return taula;
}


/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */