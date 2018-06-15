#include "Conjunt_textos.hh"
#include "Text.hh"
#include "Cites.hh"
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>


bool Conjunt_textos::existeix_cita(int n, int m){
    Text T = itp->first;
    string aut = T.consultar_autor();
    string tit = T.consultar_titol();
    for(int i = 0; i<vecCites.size(); ++i){
        if(vecCites[i].consultar_autorC()==aut)
            if(vecCites[i].consultar_titolC()==tit)
                if(vecCites[i].consultar_x()==n)
                    if(vecCites[i].consultar_y()==m)
                        return true;
    }
    return false;
}

void Conjunt_textos::troba_text(){
  bool trobat = false;
  map<Text, vector<Cita> >::iterator it = cjt.begin();
  while(it != cjt.end() && not trobat){
    Text T = it->first;
    if(T.consultar_autor() == autor_triat){
      if(T.consultar_titol()==titol_triat){
	trobat = true;
	itp = it;
      }
    }
      ++it;
  }
  
  
}

void Conjunt_textos::triar_text(string comanda){

  string aux;
  istringstream iss(comanda);
  bool correcte = false;
  bool trobada = true;
  map<string, int> Table;
  map<Text,vector<Cita> >::iterator it = cjt.begin();
  while(not correcte && it != cjt.end()){
    Text Txt = it->first;
    while(iss >> aux && trobada){
      Table = Txt.retorna_taula();
      map<string, int>::iterator it2;   
      it2 = Table.find(aux);
      if(it2 == Table.end()){
	trobada = false;       // Si no la troba a la taula de frequencies, que la busqui a l'autor, de moment "trobada" = FALSE.
	string A, auxA;
	A = Txt.consultar_autor();
	istringstream iss2(A);
	while(iss2 >> auxA && not trobada) if(auxA == aux) trobada = 1;
	if(not trobada){
	  string T, auxT;      // Si no la troba a l'autor que la busqui al titol, "trobada" = FALSE
	  T = Txt.consultar_titol();
	  istringstream iss3(T);
	  while(iss3 >> auxT && not trobada) if(auxT == aux) trobada = 1; // Si la troba al titol, "trobada" = TRUE, i passa a evaluar la
	}                                                                 // seguent paraula, altrament "trobada" = FALSE i evalua el seguent text (++it)
      }
	
	
      }
    if(trobada) correcte = true;
    else ++it;
  }
  if(correcte){
    itp = it;
    Text T = itp->first;
    autor_triat = T.consultar_autor();
    titol_triat = T.consultar_titol();
    
  }
  else cout << "error" << endl;
}



void Conjunt_textos::esborrar_text(){
    cjt.erase(itp);
    troba_text();
}

void Conjunt_textos::afegir_text(){

    Text T;
    vector<Cita> vec;
    cjt.insert(pair<Text, vector<Cita> >(T,vec));
    troba_text();
    
}


void Conjunt_textos::afegir_cita(int x, int y){
  if(not existeix_cita(x,y)){
    Text T = itp->first;             //text triat
    map<int, string> contT = T.consultar_contingut();        //contingut del text triat
    Cita c;                    //cita creada
    string cos = " ";
    cos.erase(0);
    while(x != y){
       cos += contT[x];
       cos += " ";
       ++x;
    }
    cos += contT[y];
    c.afegir_contingutC(cos,x,y);
    string a = T.consultar_autor();
    c.afegir_autorC(a);
    string t = T.consultar_titol();
    c.afegir_titolC(t);
    istringstream iss(a);
    string aux, ini = " ";
    ini.erase(0);
    int num = 1;
    bool trobada = false;
    while(iss >> aux) ini+=aux[0];
    for(int i = vecCites.size()-1; i>=0 && not trobada; --i){
        if(vecCites[i].consultar_inicials() == ini){
            num = vecCites[i].consultar_identificador();
            trobada = true;
        }
    }
    c.afegir_referencia(ini, num);
            ///// ja tenim la cita amb tots els seus parametres
    cjt[T].push_back(c);
            ///// afegim la cita al vector de cites que corrrespon al text triat
    vecCites.push_back(c);
            ///// afegim la cita al vector de cites global
  }
}

Text Conjunt_textos::consultar_text(){
    return itp->first;
}

Cita Conjunt_textos::consultar_cita(string reff){
  for(int i=0; i<vecCites.size(); ++i){
    if(vecCites[i].consultar_referencia() == reff) return vecCites[i];
  }
}

void Conjunt_textos::textos_autor(string autor){

    vector<string> titols;
    map<Text, vector<Cita> >::iterator it = cjt.begin();
    while(it != cjt.end()){
      Text T = it->first;
        if(T.consultar_autor() == autor) 
            titols.push_back(T.consultar_titol());
        
        ++it;
    }
    //ordenar alfabeticament els titols del vector
    for(int i = 0; i<titols.size(); ++i){
        cout << titols[i] << endl;
    }
}

void Conjunt_textos::cites_text(){
    
    vector<Cita> vec = itp->second;
    ////ordenar vector de cites per referencia
    for(int i = 0; i<vec.size(); ++i){
        vec[i].mostra_cita();
    }
    
}
void afegeix_a_la_llista(Text T, list<Text> &llista){
   //// HAY QUE IMPLEMENTAR LA FUNCION PARA ORDENAR LOS TEXTOS PRIMERO POR AUTOR Y LUEGO POR TITULO    
}

void Conjunt_textos::tots_textos(){
    list<Text> llista;
    map<Text, vector<Cita> >::iterator it = cjt.begin();
    while(it != cjt.end()){
        Text T = it->first;
        afegeix_a_la_llista(T, llista);  //funció privada per ordenar els textos a una llista
        ++it;
    }
    list<Text>::iterator it2 = llista.begin();
    while(it2 != llista.end()){
      Text T2 = *it2;
        string aut = T2.consultar_autor();
        string tit =  T2.consultar_titol();
        cout << tit << " " << aut << endl;
        ++it2;
    }
}

void Conjunt_textos::tots_autors(){
    vector<infoAut> vec;
    bool repetit = false;
    int pos;
    map<Text, vector<Cita> >::iterator it = cjt.begin();
    while(it != cjt.end()){
        Text T = it->first;
        for(int i = 0; i<vec.size() && not repetit; ++i){
        
            if(T.consultar_autor() == vec[i].nom) {
                repetit = true;
                pos = i;
            }
        }
        if(repetit){
            vec[pos].n_frases += T.nombre_de_frases();
            vec[pos].n_paraules += T.nombre_de_paraules();
            vec[pos].n_textos++;
        }
        else{
            infoAut A;
            A.nom = T.consultar_autor();
            A.n_frases = T.nombre_de_frases();
            A.n_paraules = T.nombre_de_paraules();
            A.n_textos = 1;
            vec.push_back(A);
        }
        ++it;
    }
}

void Conjunt_textos::mostra_cites_autor(string aut){
    
    for(int i = 0; i<vecCites.size(); ++i){
    if(vecCites[i].consultar_autorC() == aut){
        vecCites[i].mostra_cita();
    }
    }
}

void Conjunt_textos::mostra_totes_cites(){

    // ORDENAR EL VECCITES PER REFERENCIA
    for(int i = 0; i<vecCites.size(); ++i){
        vecCites[i].mostra_cita();
    }  
}

void Conjunt_textos::eliminar_cita(string reff){
      
	for(int i = 0; i<vecCites.size(); ++i){
            if(vecCites[i].consultar_referencia() == reff) vecCites.erase(vecCites.begin()+i);      //eliminar la cita del vecCites
        }
        map<Text, vector<Cita> >::iterator it = cjt.begin();
        bool eliminada = false;
        while(it != cjt.end() && not eliminada){
            vector<Cita> vec = it->second;                          //eliminar del vector de cites del text al que correspon la cita
            for(int i= 0;i<vec.size() && not eliminada;++i){
                if(vec[i].consultar_referencia()==reff){
                    vec.erase(vec.begin()+i);
                    eliminada = true;
                }
            }
            ++it;
        }
}

void Conjunt_textos::info_text(){

    Text T = itp->first;
    cout << "Autor: " << T.consultar_autor() << endl << "Titol: " << T.consultar_titol() << endl << "Nombre de frases: " << T.nombre_de_frases() 
         << endl << "Nombre de paraules: " << T.nombre_de_paraules() << endl;
    vector<Cita> vec = itp->second;
    cout << "Cites: " << endl;
    for(int i = 0; i<vec.size();++i){
        cout << vec[i].consultar_referencia() << " " << vec[i].consultar_contingutC() << endl;
    }
    
}