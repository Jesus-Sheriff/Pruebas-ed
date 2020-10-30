#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "../include/conjuntoletras.h"
#include "../include/diccionario.h"
//#include "bolsadeletras.h"


using namespace std;

float calculaPuntos(int frecletra, int letrasTotales){
  float  puntos = 1;
  int corte = letrasTotales/10;
  if(frecletra < (corte)){
        puntos = 10;
  }else if (frecletra  < (corte*2)){
        puntos = 9;
  }else if (frecletra  < (corte*3)){
        puntos = 8;
  }else if (frecletra  < (corte*4)){
        puntos = 7;
  }else if (frecletra  < (corte*5)){
        puntos = 6;
  }else if (frecletra  < (corte*6)){
        puntos = 5;
  }else if (frecletra  < (corte*7)){
        puntos = 4;
  }else if (frecletra  < (corte*8)){
        puntos = 3;
  }else if (frecletra  < (corte*9)){
        puntos = 2;
  }
  else{
        puntos = 1;
  }

  return puntos;

}




int main(int argc, char const *argv[]) {

  if(argc != 4){
    cout<<"Ejecución: cantidadletras diccionario.txt letras.txt salida.txt"<<endl;
       return 0;
  }

  ifstream f1 (argv[1]);
  if (!f1){
   cout<<"No puedo abrir el fichero  "<<argv[1]<<endl;
   return 0;
  }

  ifstream f2 (argv[2]);
  if (!f2){
   cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
   return 0;
  }

  ofstream fsalida(argv[3]);

  Conjuntoletras con;
  Diccionario midic;


  f1 >> midic;
  cout << midic;
  // f2 >> con;
  // cout << con;


// Leemos la letras de fichero letras.txt y lo metemos en un conjunto
// Esto lo hacemos porque el operador entrada de conjunto esta hecho para que lea salida.txt
    char letra;

      while(!f2.eof()){
          f2 >> letra;
          Letra l(tolower(letra));
          con.setletra(l);
      }
// Salida de la lectura de conjunto (muestra todas las letras leidas de letras.txt)
for (size_t i = 0; i < con.size(); i++) {
    cout  << con[i].getletra() <<endl;
}



  int frecletraActual = 0;
  //int numtotalLetras = 0;
  int frecletraMasRepetida = 0;

for (int i = 0; i < con.size(); i++) {
  frecletraActual = midic.FrecLetra(con[i].getletra());
  if(frecletraActual > frecletraMasRepetida){
    frecletraMasRepetida = frecletraActual;
  }
}
// cout <<  "Numero total de letras " << numtotalLetras <<endl;
for (int i = 0; i < con.size(); i++) {
    frecletraActual = midic.FrecLetra(con[i].getletra());
    //cout << frecletraActual << "La letra es "<< con[i].getletra() << endl;

    cout << "La letra: "<< con[i].getletra() << " se repite " << frecletraActual << " tiene estos puntos: " << calculaPuntos(frecletraActual,frecletraMasRepetida) <<endl;
}

for (int i = 0; i < con.size(); i++) {

    frecletraActual = midic.FrecLetra(con[i].getletra());
    fsalida << con[i].getletra() << " " << frecletraActual << " " << calculaPuntos(frecletraActual,frecletraMasRepetida) <<endl;

}

// calculaPuntos(5,100);
// calculaPuntos(90,100);

}
