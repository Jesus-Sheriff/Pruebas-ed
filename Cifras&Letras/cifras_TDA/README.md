# Práctica Cifras

## ED 
### Jesús M. Pérez Terrón | Patricia Maldonado Mancilla

## Intrucciones

Para compilar y ejecutar simplemente hay que hacer  `make run`.

A continuación se muestra un ejemplo de salida:

```
$ make run
g++ -o ./cifras ./cifras.cpp
./cifras 
Elementos introducidos: 
| 7 | 4 | 7 | 6 | 3 | 10 
Resultado a buscar: 719
7x7 = 49
6+49 = 55
3+10 = 13
55x13 = 715
4+715 = 719

SOLUCIONES ENCONTRADAS: 1
```

## Observaciones y método de juego

- El `main` principal hace un juego automático, no obstante se deja comentado el fragmento para que el usuario pueda jugar si así se desea en el futuro.

- El programa solo devuelve la primera solución que encuentra para que la ejecución no sea eterna.

- Si no encuentra solución exacta, dice que no la ha encontrado y finaliza (no realiza una aproximación).

- Se han creado una serie de funciones para adaptar el programa a un TDA. Estas son: 

```
int operator[](const int x) const;
int sizeElementos();
void push_back(int num);
vector<int> getElementos();
```



