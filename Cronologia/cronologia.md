
# Práctica 2. Cronología
#### Patricia Maldonado Mancilla
#### Jesús Pérez Terrón


## Ejecución
Para ejecutar solo hace falta invocar este método de make

> make run

Compila el programa con todas sus dependencias y posteriormente ejecuta.

## Datos de entrada
Tenemos dos archivos de datos de ejemplo que son los siguientes:

a.txt
```
1234 1
*) ggg

```

crono.txt

```
1900 2
*)Hola
*)Adios
1909 1
*)ffff
1902 1
*)Primero

```

## Funciones implementadas

Cronologia
```
Cronologia operator=(const Cronologia &crono);

Cronologia operator+(const Cronologia &crono);

void operator+=(const Cronologia &crono);
```

Fecha_Historica

```
Fecha_Historica operator=(const Fecha_Historica &fecha);

```
En pruebacronologia hemos probado todos los operadores anteriores.
Con `cronologia3 = mi_cronologia` hemos comprobado el operador asignación de cronología.

La función del operador+ es similar al operador+= y el que se ve en la salida es éste último solamente.

El operador= de fecha histórica es obligatorio para asignar fechas históricas del vector de fechas históricas de cronología. Por ejemplo se usa aquí: `event[neventos]=eh`
