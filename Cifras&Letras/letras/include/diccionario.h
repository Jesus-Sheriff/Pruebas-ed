#ifndef __Diccionario_h__
#define __Diccionario_h__
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Diccionario{

	private:
	set<string> datos;
	vector<string> palabrasFormadas;

	bool ifIterativo(int *indexs,int n,int ref);
	void variacionSR(char datos[],int n, int r,int *index,int i);

	public:
	/**
	@brief Construye un diccionario vacío.
	**/
	Diccionario();
	/**
	@brief Devuelve el numero de palabras en el diccionario
	**/
	int size() const;
	/**
	@brief Obtiene todas las palabras en el diccionario de un longitud dada
	@param longitud: la longitud de las palabras de salida
	@return un vector con las palabras de
	longitud especifica en el parametro de entrada
	**/
	vector<string> PalabrasLongitud(int longitud);
	/**
	// @brief Indica si una palabra está en el diccionario o no
	// @param palabra: la palabra que se quiere buscar
	// @return true si la palabra esta en el diccionario. False en caso contrario
	// **/


	void insertar(const string &palabra);
	//
	bool Esta(string palabra);
	/**
	@brief Lee de un flujo de entrada un diccionario
	@param is:flujo de entrada
	@param D: el objeto donde se realiza la lectura.
	@return el flujo de entrada
	**/
	friend istream & operator>>(istream & is,Diccionario &D);
	/**
	@brief Escribe en un flujo de salida un diccionario
	@param os:flujo de salida
	@param D: el objeto diccionario que se escribe
	@return el flujo de salida
	**/
	friend ostream & operator<<(ostream & os, Diccionario	&D);
	int FrecLetra(const char & letra);
  void palabrasPosibles(char datos[],int n);
	vector<string> getPalabrasFormadas();


	class iterator{

	private:
	set<string>::iterator it;

	public:
	iterator(){};
	string operator *(){
	 return *it;
	}
	iterator & operator ++(){
		++it;
	}
	bool operator ==(const iterator &i){
		return i.it==it;
	}
	bool operator !=(const iterator &i){
		 return i.it!=it;
	}
	friend class Diccionario;
	};

	iterator begin(){
			iterator i;
			i.it=datos.begin();
			return i;
}
	iterator end(){
			iterator i;
			i.it=datos.end();
			return i;
}
 };
#endif
