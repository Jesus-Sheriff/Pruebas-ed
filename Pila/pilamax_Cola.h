
#ifndef __PILAMAX_VD__
#define __PILAMAX_VD__

#include <iostream>
#include "cola.h"
#include <utility>


using namespace std;

typedef pair <int,int> pareja;

ostream& operator << (ostream &os, const pareja &p);


class PilaMax{

 private:

	Cola<pareja> ColaDeParejas;

 public:

	PilaMax():ColaDeParejas(){}

	PilaMax(const PilaMax &pilaorigen);

	PilaMax& operator= (const PilaMax &pilaorigen);

	bool vacia() const;

	pareja& tope ();

	void poner(const int &elemento);

	void quitar();

	int maximo();


};

#endif
