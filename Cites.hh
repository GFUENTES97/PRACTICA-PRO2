//#include GFUENTES97 

/** @file Cites.hh
    @brief Especificació de la clase Cites
*/
#ifndef CITES_HH
#define CITES_HH
//#include "Text.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <string>
#endif


using namespace std;

struct referencia{
    string inicials;
    int identificador;
};


/** @class Cita
    @brief Representa una cita
*/

class Cita{


    
private:

string autor, titol, contingut_cita;

referencia ref;

int x,y; // numero de frase inicial (x) i numero de frase final (y)

/** @brief mostra contingut de la cita
    \pre Cert.
    \post mostra de la frase inicial a la final d'aquesta cita.
 */
void mostra_frases_x_y();


public:
    
    //Constructores
    
/** @brief Creador de Cita.
    \pre Cert.
    \post Crea una cita .
*/
Cita();
//Modificadores

void afegir_titolC(string t);
void afegir_autorC(string a);  
void afegir_contingutC(string cont, int a, int b);  // també s'afegeix x y
void afegir_referencia(string ini, int num);

 //Consultores

/** @brief Mostra la informació d'una cita.
    \pre Cert.
    \post mostra la informació de la cita (autor, títol, número de la frase
    inicial y final, contingut de la cita).
*/
void info_cita();


/** @brief consulta l'autor de la cita.
    \pre Cert.
    \post retorna l'autor d'aquesta cita.
 */
string consultar_autorC();

string consultar_referencia(); //retorna la referencia

/** @brief consulta el titol del text d'on prové la cita.
    \pre Cert.
    \post retorna el titol del text de la cita.
 */
string consultar_titolC();
 

/** @brief consulta el contingut de la cita.
    \pre Cert.
    \post mostra el contingut d'aquesta cita.
 */
string consultar_contingutC();


/** @brief consulta la referencia de la cita.
    \pre Cert.
    \post retorna la referencia d'aquesta cita.
 */
string consultar_inicials();

int consultar_identificador();
int consultar_x();
int consultar_y();


///mostra referencia, contingut, autor i titol , si b = true, mostra l'autor, sino no.
void mostra_cita();

};
#endif


/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */