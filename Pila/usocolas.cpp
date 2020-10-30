#include <iostream>
#include <pilamax_Cola.h>

using namespace std;

int main(){
	
  PilaMax p;
  int i;

  p.poner(6);
  for ( i=0; i<10 ; i++) 
    p.poner(i);
   

     
  p.quitar();

  p.poner(3);

  PilaMax  q(p);
  PilaMax  j=q;
   cout << "\nMáximo de p: " << p.maximo() << endl;

   cout << "\nMáximo de q: "<< q.maximo() << endl;

   cout << "\nMáximo de j: "<< j.maximo() << endl;
  
  while (!p.vacia())
  {
    cout << p.tope() << " ";
    p.quitar();
  }

 cout << "\nOperador de copia q(p): " << endl;
  while (!q.vacia())
  {
    cout << q.tope() << " ";
    q.quitar();
  }
 
cout <<endl;


   cout << "\nOperador= : " << endl;
  while (!j.vacia())
  {
    cout << j.tope() << " ";
    j.quitar();
  }




  return 0;
}
