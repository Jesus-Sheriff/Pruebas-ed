#ifndef __bolsadeletras_h__
#define __bolsadeletras_h__

#include <vector>
#include "conjuntoletras.h"


using namespace std;

class Bolsaletras{

private:
	vector<char> bolsa; // contiene todas las letras del juego (de las recopiladas del diccionario) a=1000, b=354, etc
	vector<char> letrasenjuego; // letras que tengo en mano para jugar
public:

Bolsaletras();
Bolsaletras(int elemAleatorios,Conjuntoletras &conjunto);
void setletraBolsa(const char l);
char getletraBolsa(const int x) const;
char getletraEnjuego(const int x) const;
// void letrasAleatorias(const int &numletras);
int sizeVectorenJuego();
int sizeVectorBolsa() const;
friend ostream & operator<<(ostream & os, Bolsaletras const &b);


};





#endif