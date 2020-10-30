#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include "../include/diccionario.h"
#include "../include/bolsadeletras.h"
#include "../include/conjuntoletras.h"

using namespace std;

int puntuaPalabra(string palabra, Conjuntoletras con){
  int puntosTotales = 0;
  for(unsigned int i = 0; i<palabra.length(); i++) {
      char c = palabra[i];
      puntosTotales += con.scoreletra(c);
  }
  return puntosTotales;
}

//
string palabraMasLarga(vector<string> palabras){
   // palabras[palabras.size()-1];
   return palabras[palabras.size()-1];
}



int main(int argc, char const *argv[]) {

  if(argc != 5){
    cout<<"Ejecución: letras diccionario1.txt salida.txt numerodeLetras8 modalidad(L o P)"<<endl;
       return 0;
  }

  ifstream fdiccionario (argv[1]);
  if (!fdiccionario){
   cout<<"No puedo abrir el fichero  "<<argv[1]<<endl;
   return 0;
  }

  ifstream fsalidatxt (argv[2]);
  if (!fsalidatxt){
   cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
   return 0;
  }


  Diccionario midiccionario;
  fdiccionario >> midiccionario;
  Conjuntoletras con;
  fsalidatxt >> con;
  // cout << con << endl;
  int longitud = atoi(argv[3]);
  Bolsaletras mibolsa(longitud,con); // genera las letras aleatorias
  string palabraJugador;
  char p[mibolsa.sizeVectorenJuego()];


if(string(argv[4]) == "L"){
    cout << endl;
    cout  <<"-------- Ha elegido jugar por Longitud ---------" <<endl;
    cout<< endl;
    cout << "Tus letras para jugar son: ";
    for (int i = 0; i < mibolsa.sizeVectorenJuego(); i++) {
      p[i] = mibolsa.getletraEnjuego(i);
      cout  <<p[i] <<" ";
    }
    cout << endl;
    cout << endl;


    cout << "Dime tu palabra: ";
    cin >> palabraJugador;

    bool esta = midiccionario.Esta(palabraJugador);

    if(esta){
      cout << "La palabra "<< palabraJugador <<" está en el diccionario con longitud " << palabraJugador.size()<<endl;

    }
    else {
      cout << "La palabra "<< palabraJugador << " no está en el diccionario"<<endl;

    }
    cout << endl;
    cout << endl;
    cout << "Palabras formadas: " <<endl;
    cout << endl;
    midiccionario.palabrasPosibles(p,mibolsa.sizeVectorenJuego());
    vector<string> misPalabras= midiccionario.getPalabrasFormadas();

    for (size_t i = 0; i < misPalabras.size(); i++) {
        cout<< " "<< misPalabras[i] << " tiene esta longitud " << misPalabras[i].size()<<endl;
    }

    cout<< endl;
    cout << "La palabra más larga es " << palabraMasLarga(misPalabras)  <<endl ;


} else if (string(argv[4])== "P") {
    cout << endl;
    cout  <<"---- Ha elegido jugar por Puntuación ----" <<endl;
    cout << endl;
    cout << "Tus letras para jugar son: ";
    for (int i = 0; i < mibolsa.sizeVectorenJuego(); i++) {
      p[i] = mibolsa.getletraEnjuego(i);
      cout  <<p[i] <<" ";
    }
    cout << endl;
    cout << endl;
    cout << "Dime tu palabra: ";
    cin >> palabraJugador;
    bool esta = midiccionario.Esta(palabraJugador);

    if(esta){
      cout << "La palabra "<< palabraJugador <<" está en el diccionario con puntuacion " << puntuaPalabra(palabraJugador,con)<<endl;

    }
    else {
      cout << "La palabra "<< palabraJugador << " no está en el diccionario"<<endl;

    }
    cout << endl;

    midiccionario.palabrasPosibles(p,mibolsa.sizeVectorenJuego());
    vector<string> misPalabras= midiccionario.getPalabrasFormadas();
    int puntuacionMayor = 0;
    string palabraMasPuntos;
    for (size_t i = 0; i < misPalabras.size(); i++) {
        int puntos = puntuaPalabra(misPalabras[i],con);
        cout<< " " << misPalabras[i] << " tiene esta puntuacion " << puntos <<endl;

        if(puntos > puntuacionMayor){
           palabraMasPuntos = misPalabras[i];
           puntuacionMayor =  puntos ;
        }
    }

    cout << endl;
    cout << "La palabra con más puntuación es " << palabraMasPuntos <<endl;

}
else {

  cout << "Elige una modalidad de juego correcta L o P (Longitud ó Puntuación)"<<endl;
}










}