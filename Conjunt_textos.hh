//#include GFUENTES97 

/** @file Conjunt_textos.hh
    @brief Especificació de la clase Conjunt_textos
*/

#ifndef CONJ_TEXT_HH
#define CONJ_TEXT_HH


#include "Text.hh"
#include "Cites.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#include <list>
#endif

using namespace std;

struct infoAut{
    string nom;
    int n_frases;
    int n_paraules;
    int n_textos;
};




/** @class Conjunt_textos
    @brief Representa un conjunt de textos amb cites
*/

class Conjunt_textos{


private:
  
string titol_triat, autor_triat;
infoAut InfoAutor;
vector<Cita> vecCites;
map<Text, vector<Cita> > cjt;       // conjunt de textos
map<Text, vector<Cita> >::iterator itp;   // iterador que apunta al text triat
void afegeix_a_la_llista(Text T, list<Text> &llista);
bool existeix_cita(int n, int m); // comprova si existeix una cita abans d'afegirla
void troba_text();

public:

//Constructores
    
/** @brief Creador de Conjunt de textos
    \pre Cert
    \post Crea un conjunt de textos buit
 */
Conjunt_textos(); //  ******ES NECESARIA???******


//Destructores

/** @brief Elimina un text
    \pre Hi ha un text triat
    \post El text queda eliminat, pero no les seves cites
 */
void esborrar_text();


//Modificadores i consultores

/** @brief Tria un text del conjunt.
    \pre Hi ha un unic text que compleix els requeriments de la comanda.
    \post Queda un text triat (del conjunt).
 */
void triar_text(string comanda);

/** @brief Afegeix un text al conjunt.
    \pre Cert.
 *  \post el text queda afegit al conjunt.
 */
void afegir_text();


/** @brief Afegeix una cita al conjunt.
    \pre Hi ha un text triat i 0<=x<=y<=nfrases del text triat.
    \post afegeix al sistema una cita basada en les frases que van de la x-esima a la y-esima del contingut de l'ultim text triat.
*/
void afegir_cita(int x, int y);


/** @brief Retorna el text triat.
    \pre Hi ha un text triat.
    \post Retorna el text triat del parametre implicit.
*/
Text consultar_text();

/** @brief Retorna la cita que correspon a la referencia
    \pre Hi ha una cita amb aquesta referencia.
    \post retorna la cita demanada.
 */
Cita consultar_cita(string reff);

/** @brief Mostra els textos d'un determinat autor.
    \pre L'autor té algun text.
    \post mostra tots els textos de l'autor (només el titol) ordenats alfabèticament.
*/
void textos_autor(string autor);

/** @brief Mostra tots els textos del conjunt.
    \pre Hi ha algun text al conjunt.
    \post mostra tots els textos del conjunt(nomes el titol i l'autor) orenats per autor i després per titol.
*/
void tots_textos();

/** @brief Mostra tots els autors del conjunt.
    \pre El conjunt no es buit.
    \post mostra tots els autors indicant el nombre de textos que tenen, el nombre de frases i paraules del contingut.
*/
void tots_autors();

/** @brief Mostra les cites d'un determinat autor.
    \pre Hi ha cites d'aquest autor.
    \post mostra les cites de l'autor (la seva referencia, el contingut i el titol).
*/
void mostra_cites_autor(string aut);

/** @brief Mostra totes les cites d'un text determinat.
    \pre Hi ha un text triat.
    \post mostra totes les cites de l'ultim text triat (la referencia, el contingut, l'autor i el titol) ordenades per referencia.
*/
void cites_text();


/** @brief consulta la informació del text triat.
    \pre Cert.
    \post mostra la informacio del text triat: autor, titol, nombre de frases, nombre de paraules i cites.
 */
void info_text();


/** @brief Mostra totes les cites del conjunt.
    \pre Cert.
    \post mostra totes les cites del conjunt (referencia, contingut, autor i titol) ordenades per referencia.
*/
void mostra_totes_cites();

/** @brief Elimina la cita que correspon a la referencia.
    \pre Existeix la cita amb aquesta referencia.
    \post Aquesta cita queda eliminada del conjunt.
*/
void eliminar_cita(string reff);

};
#endif


/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */