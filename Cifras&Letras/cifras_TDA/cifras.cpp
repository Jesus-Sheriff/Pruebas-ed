
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "cifras.h"

using namespace std;

static int cont = 0;

solucion::solucion()
{
}

bool solucion::restaPosible(int a, int b)
{
    bool posible = true;
    if (a <= b)
        posible = false;
    return posible;
}

bool solucion::divisionPosible(int a, int b)
{
    bool posible = false;
    if (a > b)
        if (a % b == 0)
            posible = true;
    return posible;
}
//En el vector v busca los enteros a y b y los borra
void solucion::borrar(vector<int> &v, int a, int b)
{
    int i = 0, tam = v.size();
    bool encA = false, encB = false;
    while (i < tam)
    {
        if (v[i] == a and !encA)
        {
            v.erase(v.begin() + i);
            encA = true;
            tam--;
        }
        else if (v[i] == b and !encB)
        {
            v.erase(v.begin() + i);
            encB = true;
            tam--;
        }
        else
            i++;
    }
}
//Esta el entero result en el vector v?
bool solucion::esta(vector<int> v, int result)
{
    bool esta = false;
    for (int i = 0; i < v.size() and !esta; i++)
        if (v[i] == result)
            esta = true;
    return esta;
}

void solucion::mostrar(solucion v)
{
    for (int i = 0; i < v.operaciones.size(); i++)
        cout << v.operaciones[i][0] << v.operando[i] << v.operaciones[i][1] << " = " << v.operaciones[i][2] << endl;
    cout << endl;
}
//Funcion para evitar la repetición de código en la funcion cyl
solucion solucion::codigo(solucion sol, char oper, int i, int j)
{
    solucion s = sol;
    int operacion;
    if (oper == '+')
        operacion = s.elementos[i] + s.elementos[j];
    if (oper == '-')
        operacion = s.elementos[i] - s.elementos[j];
    if (oper == 'x')
        operacion = s.elementos[i] * s.elementos[j];
    if (oper == '/')
        operacion = s.elementos[i] / s.elementos[j];
    vector<int> op;
    op.push_back(s.elementos[i]);
    op.push_back(s.elementos[j]);
    op.push_back(operacion);
    s.operaciones.push_back(op);
    s.operando.push_back(oper);
    borrar(s.elementos, s.elementos[i], s.elementos[j]);
    s.elementos.push_back(operacion);
    return s;
}

void solucion::cyl(solucion sol, int resultado, int tam, vector<int> el)
{
    if (tam == 1)
    {
        if (sol.elementos[0] == resultado)
        {
            mostrar(sol);
            cont++;
        }
    }
    //PARA OBTENER UNA SOLUCIÓN NO HACE FALTA ESTE CODIGO

    // else if(esta(sol.elementos, resultado)){
    //   mostrar(sol);
    //   cont++;
    // }
    else if (cont < 1)
    { //PARA OBTENER UNA SOLUCIÓN
        int operacion, i, j;
        solucion s;
        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                if (i < j)
                {
                    s = codigo(sol, '+', i, j); //SUMA
                    cyl(s, resultado, tam - 1, el);
                    s = codigo(sol, 'x', i, j); //MULTIPLICACION
                    cyl(s, resultado, tam - 1, el);
                }
                if (i != j)
                {
                    if (restaPosible(sol.elementos[i], sol.elementos[j]))
                    {
                        s = codigo(sol, '-', i, j); //RESTA
                        cyl(s, resultado, tam - 1, el);
                    }
                    if (divisionPosible(sol.elementos[i], sol.elementos[j]))
                    {
                        s = codigo(sol, '/', i, j); //DIVISION
                        cyl(s, resultado, tam - 1, el);
                    }
                }
            }
        }
    }
}

int solucion::operator[](const int x) const
{
    return elementos[x];
}

int solucion::sizeElementos()
{
    return elementos.size();
}

void solucion::push_back(int num)
{
    elementos.push_back(num);
}
vector<int> solucion::getElementos()
{
    return elementos;
}

int main()
{
    solucion v;
    int num = -1, resultado;
    int ivector;
    int objetivo;
    srand (time(NULL));
    int C [] = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};
    // Crear un vector con los valores a escoger
    // Generar 6 nos aleatorios q seran los elementos del vector a coger
    // Meterlos en v.elementos

    for(int i=0; i<6; ++i)
    {
        ivector = rand() % 14 ;
        v.push_back(C[ivector]) ;
    }
    cout << "Elementos introducidos: " << endl;
    
    for(int i=0; i<v.sizeElementos(); i++)
        cout << "| " << v[i] << " ";
        
    cout << endl;
    objetivo = rand() % 899+100 ;
    // while (num != 0)
    // {
    //     system("clear");
    //     cout << "NUMEROS A OPERAR" << endl;
    //     for (int i = 0; i < v.sizeElementos(); i++)
    //         cout << "| " << v[i] << " ";
    //     cout << "|" << endl;
    //     cout << "Introduce un número y pulsa enter (para dejar de meter numeros introduce 0)" << endl;
    //     cin >> num;
    //     if (num != 0)
    //         v.push_back(num);
    // }

    // cout << "Ahora introduce el resultado a conseguir" << endl;
    // cin >> resultado;
    resultado=objetivo;
    cout << "Resultado a buscar: " <<resultado << endl;
  

    v.cyl(v, resultado, v.sizeElementos(), v.getElementos());
    cout << "SOLUCIONES ENCONTRADAS: " << cont << endl;
}
