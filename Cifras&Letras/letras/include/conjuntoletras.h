#ifndef __conjuntoletras_h__
#define __conjuntoletras_h__
#include <set>
#include <string>
#include <vector>

using namespace std;

class Letra{

private:
	char letra;
	int puntos;
	int repe;

public:
	Letra();
	Letra(const char &p);
	Letra(const char & l, const int &puntos,const int &repeticiones);


	int  repeticiones() const;
	void setletra(char l);
	char getletra() const;
	int getpuntos() const;
	int getrepe() const;
	bool operator==(Letra l)const;

//operadores de lectura y escritura, que lea los tres campos y pueda activar la funcion
// escribir o leer la letra.
};

class Conjuntoletras {

/*
Class conjunto de letras  que luego usara la bolsa de letras constará
de un unico miembro, (el miembro lo elegimos nosotros(set de letra) y
metodo para obtener el tamaño, metodos para obtener las palabras de mejores
 puntuaciones.(esto es trivial solo es usar la letra)

*/
private:
 vector<Letra> conjunto;


public:


Conjuntoletras();
vector<Letra> getletras() const;
int scoreletra(char letra);
void setletra(Letra l);
int size() const;
Letra operator[] (const int x) const;
friend ostream & operator<<(ostream & os, Conjuntoletras const &conjunto);
friend istream & operator>>(istream & is, Conjuntoletras &conjunto);


};

#endif
