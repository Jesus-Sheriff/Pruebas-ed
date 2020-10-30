#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc<2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   Cronologia cronologia2;
   if (argc == 3)
   {
      
      ifstream f2(argv[2]);
      if (!f2)
      {
         cout << "No puedo abrir el fichero " << argv[2] << endl;
         return 0;
      }
      f2 >> cronologia2;
   }

   Cronologia mi_cronologia;
//cout << mi_cronologia;
   f >> mi_cronologia; //Cargamos en memoria
   
   cout << "Cronología leida del archivo: " << endl << mi_cronologia << endl;
//    cout << mi_cronologia;
//    Cronologia buscadora;

   
   if (argc==3)
   {
      
      Cronologia cronologia3;
      cronologia2 += mi_cronologia;
      cout << "Cronología2 += mi_cronologia: "<< endl << cronologia2;
      cronologia3 = mi_cronologia;
      cout << "Cronología3 = mi_cronologia: "<< endl << cronologia3;
      
   }
   
   
    Cronologia copia(cronologia2); //Utilización del constructor de copias
    cronologia2 = copia.buscarEventos("Ho");
//   /* To-do: Ej: buscar un evento y restringir copia a los acontecimientos con ese evento, después imprimir para comprobar */
    cout << "Evento encontrado con \"Ho\":" << endl << cronologia2;
  

}
