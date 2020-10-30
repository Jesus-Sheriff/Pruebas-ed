#include "guiatlf.h"
#include <fstream>
int main(int argc , char * argv[]){
  if (argc!=3){
      cout<<"Dime el nombre del fichero con la guia"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){ // si no he hecho bien la lectura
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }

  ifstream f2(argv[2]);
  if (!f2){ // si no he hecho bien la lectura
      cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
      return 0;
  }

 Guia_Tlf g;
 Guia_Tlf h;

 f>>g; // lee y los carga en la guia g
f2>>h;
 cout<<"La guia insertada "<<g<<endl;
 cin.clear();
 cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;
 string t;
 while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }
 cin.clear();//borra strings
 // cout<<"Dime el nombre que quieres borrar"<<endl;
 //
 // while (getline(cin,n)){
	//    g.borrar(n);
	//    cout<<"Dime el nombre que quieres borrar"<<endl;
 // }
 //
 cout<<"Dime el nombre que quieres borrar"<<endl;

 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar"<<endl;
 }

 cin.clear();
 cout<<"Vamos a borrar"<<endl;
 while (getline(cin,n)){
 cout<<"Dime nombre"<<endl;
    getline(cin,n);
   cout<<"Dime telefono"<<endl;
      getline(cin,t);
	   g.borrar(n,t);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar"<<endl;
}

cin.clear();
 cout<<"Vamos a borrar pasando un telefono"<<endl;
 while (getline(cin,t)){
	   g.borrart(t);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar"<<endl;
 }



 cin.clear();
 // Guia_Tlf otraguia;
 // cout<<"Introduce otra guia ([Pulse CTRL+D para finalizar])"<<endl;
 // cin>>otraguia; cin.clear();
 Guia_Tlf un = g+h;
 Guia_Tlf dif = g-h;
 cout<<endl<<"La union de las dos guias: "<<un<<endl;

 cout<<endl<<"La diferencia de las dos guias:"<<dif<<endl;

 cout<<endl<<"Dime un nombre para establecer los previos"<<endl;
 cin>>n;
 string tlf= g.gettelefono(n);
 Guia_Tlf p = g.previos(n,tlf);
 cout<<endl<<"Los nombre previos: "<<p<<endl;


 cout<<"Listando la guia con iteradores:"<<endl;
 Guia_Tlf::iterator it; // estoy usando el iterator de fuera de la clase sin pasar por datos
 for (it=g.begin(); it!=g.end(); ++it)
     cout<<*it<<endl;

}
