
#include <iostream>
#include "pilamax_Cola.h"
#include "cola.h"
#include <utility>

using namespace std;

ostream& operator << (ostream &os, const pareja &p){

  os << "(" << p.first << "," << p.second << ")";
  return os;

}

PilaMax::PilaMax(const PilaMax &pilaorigen):ColaDeParejas(pilaorigen.ColaDeParejas){}
// PilaMax::PilaMax(const PilaMax &pilaorigen){

//  ColaDeParejas(pilaorigen);

// }

bool PilaMax::vacia() const{
  return ColaDeParejas.vacia();
}


pareja& PilaMax:: tope(){
  return ColaDeParejas.frente();
}


void PilaMax:: poner(const int &elemento){
    pareja p;
    p.first = elemento;
   
  int mayor;
  if (!PilaMax::vacia())
  {
    //con el if ya no fallaria
    //esto falla si tope accede a tope.second la primera vez, porque no hay elementos
    if(elemento> PilaMax::tope().second){
      mayor = elemento;
    }
    else{
      mayor = PilaMax::tope().second;
    }
    p.second = mayor;
  
  }
  else
  {
     p.second = elemento;
  }
  
  
  


  

  PilaMax aux(*this); //metemos pila actual en una auxiliar
  //ahora ponemos la pareja actual en la pila actual
  ColaDeParejas.poner(p);

  int num = ColaDeParejas.num_elementos()-1;
  for (int i = 0; i < num; i++)
  {
    ColaDeParejas.quitar();
  }
  for (int i = 0; i < num; i++)
  {
    ColaDeParejas.poner(aux.tope()); 
    aux.quitar();
  }
}


void PilaMax:: quitar(){

  ColaDeParejas.quitar();
}

int PilaMax:: maximo() {
  int n =0;
  if ( ColaDeParejas.vacia())
  {
    return n;
  }
  n=PilaMax::tope().second;
  return n;
  
  
}
