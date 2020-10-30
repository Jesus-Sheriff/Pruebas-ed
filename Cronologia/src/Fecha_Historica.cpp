#include <iostream>
#include "Fecha_Historica.h"

using namespace std;

//Resize simple
  void Fecha_Historica::resize(int r){
     string *aux = new string[r];   
     for(int i=0; i<numeventos; ++i){
        aux[i]=str[i]; 
     }
     delete[] str;
     str = aux;
     reservados = r;
  }

//Constructor vacío
  Fecha_Historica::Fecha_Historica():anio(0),reservados(0),numeventos(0),str(0){}


//Constructor con parametros año, cadena de eventos y número de eventos a añadir
  Fecha_Historica::Fecha_Historica(int a, string *s, int n):reservados(n),numeventos(n){
     assert(a >= 0 && a<= 9999);
     anio = a;
     string *str = new string[n];   
     for (int i=0; i<n; i++)
        str[i]=s[i];
  }

//Constructor de copias
   Fecha_Historica::Fecha_Historica(const Fecha_Historica& e){
      str = new string[e.reservados];
      anio=e.anio;
      numeventos = e.numeventos;
      reservados = e.numeventos;
      for(int i=0; i<numeventos; ++i)
         str[i] = e.str[i];
   }

   
//Método de acceso a año
   int Fecha_Historica::getAnio(){
    return anio;
   }


//Añade un evento
  void Fecha_Historica::aniadirevento(string& event){
     if (numeventos == reservados){
        if (numeventos==0)
           resize(1);
        else
        resize(2*reservados);
     }
     str[numeventos]=event;
     numeventos++;
  }

  Fecha_Historica Fecha_Historica::operator=(const Fecha_Historica &fecha)
  {
     if (this != &fecha)
     {

        delete[] str;
        str = new string[fecha.reservados];
        anio=fecha.anio;
        numeventos = fecha.numeventos;
        reservados = fecha.numeventos;
        for (int i = 0; i < numeventos; ++i)
           str[i] = fecha.str[i];
     }
     return *this;
  }

  //Buscador de eventos
  bool Fecha_Historica::buscarEventos(string s, Fecha_Historica &matches){
     bool encontrado=false;
     for (int i=0; i < numeventos; ++i){
        if(str[i].find(s) != -1 ){
           matches.aniadirevento(str[i]);
           encontrado = true;
        }
     }
     if (encontrado){
        matches.anio=anio;
      }
    return encontrado;       
   }

//Operador <<
  ostream& operator<< (ostream& os, const Fecha_Historica& e){
        os << e.anio << " " << e.numeventos << endl;
        for (int i = 0; i < e.numeventos; i++)
        {
            os << e.str[i] << endl;
        }
        return os;
  }

//Operador >>
  istream& operator>> (istream& is, Fecha_Historica& e){
     char b, f; //esto para el formato de asteriscos facil de 2019
     string s;
     //int anio, numeventos;
     //cout << e.anio << " e anio  ";
     is >> e.anio >> e.numeventos;
      // cout << "e.anio: " << e.anio << " ";
      // cout << "e.numeventos: " << e.numeventos << " ";
     getline(is, s);
   e.reservados = e.numeventos;
   delete[] e.str;
   e.str = new string[e.reservados];
   for (int i = 0; i < e.numeventos; i++)
   {
      /* code */
      is >> b >> f;
      getline(is, s);
      e.str[i] = s;
      //cout << "e.str[] " << e.str[i] << endl;
   }
     return is;
  }  
