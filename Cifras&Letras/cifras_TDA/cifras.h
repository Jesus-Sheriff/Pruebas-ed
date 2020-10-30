
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class solucion
{
private:
    vector<int> elementos;           //elementos disponibles para realizar operaciones
    vector<vector<int> > operaciones; //tripletas correspondientes a las operaciones hasta llegar a la solucion
    vector<char> operando;           //vector de los operadores en orden
public:
    solucion();
    bool restaPosible(int a, int b);
    bool divisionPosible(int a, int b);
    void borrar(vector<int> &v, int a, int b);
    bool esta(vector<int> v, int result);
    void mostrar(solucion v);
    solucion codigo(solucion sol, char oper, int i, int j); 
    // Función adaptada: Solo muestra una solución.
    void cyl(solucion sol, int resultado, int tam, vector<int> el);
    // Operadores y funciones creadas Jesús y Patri
    int operator[](const int x) const;
    int sizeElementos();
    void push_back(int num);
    vector<int> getElementos();
};
