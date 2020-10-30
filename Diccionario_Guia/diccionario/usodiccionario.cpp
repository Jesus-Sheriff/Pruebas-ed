#include <iostream>
#include <fstream>
#include "diccionario.h"

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream &operator<<(ostream &os, const Diccionario<string, string> &D)
{

	list<data<string, string> >::const_iterator it;

	for (it = D.begin(); it != D.end(); ++it)
	{

		list<string>::const_iterator it_s;

		os << endl
		   << (*it).clave << endl
		   << " informacion asociada:" << endl;
		for (it_s = (*it).info_asoci.begin(); it_s != (*it).info_asoci.end(); ++it_s)
		{
			os << (*it_s) << endl;
		}
		os << "**************************************" << endl;
	}

	return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream &operator>>(istream &is, Diccionario<string, string> &D)
{
	// cout << "debud <<" << endl;
	int np;
	is >> np; // lee numero de palabras
	// cout << "np: " << np << endl;
	is.ignore();					  //quitamos \n
	Diccionario<string, string> Daux; //carga la información
	for (int i = 0; i < np; i++)
	{
		string clave;
		// cout << "debug: 1" << endl;
		getline(is, clave); //compilador,programa,sentencia

		int ns;
		is >> ns; //leo numero de sentencias
		// cout << "debug: 2" << ns << endl;

		is.ignore(); //quitamos \n
		list<string> laux;
		for (int j = 0; j < ns; j++)
		{
			string s;
			getline(is, s); //leo cada definición

			// cout<<"Significado leido "<<s<<endl;
			laux.insert(laux.end(), s);
		}
		Daux.Insertar(clave, laux);
	}
	D = Daux;
	return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string> &l)
{
	list<string>::const_iterator it_s;

	for (it_s = l.begin(); it_s != l.end(); ++it_s)
	{
		cout << *it_s << endl;
	}
}

// void sumadiccionarios(Diccionario<string, string> &D,Diccionario<string, string> &D2,Diccionario<string, string> &suma){
// 	Diccionario<string, string>::iterator it;

// 	for (it = D.begin(); it != D.end(); ++it){
// 		AddSignificado_Palabra()
// 	}
// }

/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Dime el nombre del fichero con el diccionario" << endl;
		return 0;
	}
	ifstream f(argv[1]);
	if (!f)
	{ // si no he hecho bien la lectura
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}
	Diccionario<string, string> D;
	cout << "Voy a leer el diccionario: " << endl;

	f >> D;
	cout << "Aquí tienes el diccionario leído: " << endl;

	cout << D;

	if (argc == 3){
		ifstream g(argv[2]);
		if (!g)
		{ // si no he hecho bien la lectura
			cout << "No puedo abrir el fichero " << argv[2] << endl;
			return 0;
		}
		Diccionario<string, string> D2;
		cout << "Voy a leer el diccionario 2: " << endl;

		g >> D2;
		cout << "Aquí tienes el diccionario 2 leído: " << endl;

		cout << D2;

		Diccionario<string, string> suma;

		// sumadiccionarios(D,D2,suma);

		// cout << "Aquí tienes el diccionario SUMA: " << endl;

		// cout << suma;
	}
	string a;


	cout << "Introduce una palabra" << endl;
	cin >> a;

	list<string> l = D.getInfo_Asoc(a);

	if (l.size() > 0)
		EscribeSigni(l);
}
