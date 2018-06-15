/** @file Text.hh
    @brief Especificació de la clase Text
*/

#ifndef TEXT_HH
#define TEXT_HH

//#include "Cites.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <map>
#endif


using namespace std;

/** @class Text
    @brief Representa un Text
*/    

class Text{

private:

int nfrases;
int nparaules;
string autor;
string titol;
string frase;
map<int, string> contingut;
map<string, int> taula;

void afegeix_titol();
void afegeix_autor();
void afegeix_contingut();
int frequencia_paraula(string paraula);
void afegeix_a_la_taula(string m);

public:
    
    //Constructores
    
/** @brief Creador de Text.
    \pre Cert.
    \post Crea un text buit.
 */
Text();

    //Consultores


/** @brief consulta el titol d'un text.
    \pre Cert.
    \post mostra el titol d'aquest text.
 */
string consultar_titol();


/** @brief consulta l'autor d'un text.
    \pre Cert.
    \post mostra l'autor d'aquest text.
 */
string consultar_autor();

// retorna el contingut del text
map<int, string> consultar_contingut();


/** @brief mostra el nombre de frases del contingut.
    \pre Cert.
    \post Retorna el nombre de frases del contingut del text.
 */
int nombre_de_frases();

/** @brief mostra el nombre de paraules del contingut.
    \pre Cert.
    \post Retorna el nombre de paraules del contingut del text.
 */
int nombre_de_paraules();


/** @brief mostra el contingut del text.
    \pre Cert.map<int, string> retorna_taula();
    \post mostra el contingut del text, amb les seves frases numerades a partir de l'1.
 */
void mostra_contingut();

/** @brief mostra determinades frases del text.
    \pre 0 <= x <= y <= nfrases.
    \post mostra les frases de la x-èsima a la y-èsima numerades.
 */
void mostra_frases_x_y(int x, int y);


/** @brief mostra les frases del contingut que compleixin l'expressió.
    \pre Cert.
    \post mostra les frases del contingut del text que compleixen l'expressió.
 */
void frases_expressio();

/** @brief substitueix la <b>paraula1</b> per <b>paraula2</b> al contingut.
    \pre paraula1 es troba al contingut.
    \post canvia totes les aparicions de <paraula1> per <paraula2> en el contingut.
 */
void substitueix(string paraula1, string paraula2);

/** @brief mostra la taula de frequencies.
    \pre Cert.
    \post mostra totes les paraules del contingut ordenades decreixentment per frequencia, en cas d'empat les paraules s'ordenen creixentment primer per llargada i després alfabeticament.
 */
void mostra_taula_frequencies();

/** @brief retorna la taula de frequencies.
    \pre Cert.
    \post retorna la taula de frequencies.
 */
map<string, int> retorna_taula();

};
#endif
