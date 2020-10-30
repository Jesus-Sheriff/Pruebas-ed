#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <fstream>
#include "../include/bolsadeletras.h"
#include "../include/conjuntoletras.h"


Bolsaletras::Bolsaletras()
{
    bolsa.clear();
    letrasenjuego.clear();
}

Bolsaletras::Bolsaletras(int elemAleatorios,Conjuntoletras &conjunto)
{
    bolsa.clear();
    letrasenjuego.clear();
    // Creamos un vector de vocales para que al menos siempre meta una vocal
    vector<char> vocales{'a','e','i','o','u'};

   if(conjunto.size() > 0){

    for (int i = 0; i < conjunto.size(); i++) {
      bolsa.push_back(conjunto[i].getletra());
    }
    srand(time(0));
    for (int i = 0; i < elemAleatorios-1; i++)
    {
        int aleatorio = rand() % bolsa.size();
        char l = tolower(bolsa[aleatorio]);
        letrasenjuego.push_back(l);
    }
      int aleatorioVocal = rand() % vocales.size();
      letrasenjuego.push_back(vocales[aleatorioVocal]);
 }
}



void Bolsaletras::setletraBolsa(const char l)
{
    bolsa.push_back(l);
}
char Bolsaletras::getletraBolsa(const int x) const
{
    if (x < bolsa.size())
    {
        return bolsa[x];
    }
}

// void Bolsaletras::letrasAleatorias(const int &numletras)
// {
//     letrasenjuego.clear();
//     srand(time(0));
//     for (int i = 0; i < numletras; i++)
//     {
//         int aleatorio = rand() % bolsa.size();
//         char l = tolower(bolsa[aleatorio]);
//         letrasenjuego.push_back(l);
//     }
// }

int Bolsaletras::sizeVectorenJuego(){
    return letrasenjuego.size();
}
char Bolsaletras::getletraEnjuego(const int x) const{
    return letrasenjuego[x];
}

int Bolsaletras::sizeVectorBolsa() const{
    return bolsa.size();
}

ostream & operator<<(ostream & os, Bolsaletras const &b){
  for (int i = 0; i < b.sizeVectorBolsa(); i++)
  {
    os << b.getletraBolsa(i) << " " ;
  }
  os << endl;
  return os;

}


// int main(int argc, char const *argv[])
// {
//     ifstream f1 (argv[1]);
//     if (!f1){
//      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
//      return 0;
//     }
//     char michar = 'v';
//     Conjuntoletras con;
//     f1 >> con;
//     Bolsaletras mibolsa;
//     Bolsaletras bolsa2(5,con);
//
//
//     mibolsa.setletraBolsa(michar);
//     mibolsa.setletraBolsa('j');
//     mibolsa.setletraBolsa('a');
//     mibolsa.setletraBolsa('i');
//     mibolsa.setletraBolsa('c');
//     //cout << mibolsa.getletraBolsa(0) << endl;
//     mibolsa.letrasAleatorias(4);
//     // for (int i = 0; i < mibolsa.sizeVectorenJuego(); i++)
//     // {
//     //     cout <<  mibolsa.getletraEnjuego(i) << " ";
//     // }
//     // cout << endl;
//
//
//
//     cout <<  "Letras a jugar obtenidas de un conjunto" << endl;
//     for (int i = 0; i < bolsa2.sizeVectorenJuego(); i++)
//     {
//         cout  << bolsa2.getletraEnjuego(i) << " ";
//     }
//     cout << endl;
//
//     cout << "Operador salida" << endl;
//     cout << mibolsa;
//
//
//     return 0;
// }
