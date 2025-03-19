#include <iostream>
#include <iomanip> // Include the <iomanip> header to access std::setprecision
#include "TArrayInt.h"
int main(){
  TArrayInt a(10); //declaración de un objeto de la clase TArrayInt. 5 es el tamaño del arreglo
  a.SetElement(0,4);//asigna el valor 4 al primer elemento del arreglo del objeto b
  a.SetElement(1,6);//asigna el valor 6 al segundo elemento del arreglo del objeto b
  a.SetElement(2,3);//asigna el valor 3 al tercero elemento del arreglo del objeto b
  a.SetElement(3,0);//asigna el valor 2 al cuarto elemento del arreglo del objeto b
  a.SetElement(4,11);//asigna el valor 1 al quinto elemento del arreglo del objeto b
  a.SetElement(5,0);//asigna el valor 7 al sexto elemento del arreglo del objeto b
  a.SetElement(6,2);//asigna el valor 4 al septimo elemento del arreglo del objeto b
  a.SetElement(7,0);//asigna el valor 3 al octavo elemento del arreglo del objeto b
  a.SetElement(8,2);//asigna el valor 2 al noveno elemento del arreglo del objeto b
  a.SetElement(9,9);//asigna el valor 1 al decimo elemento del arreglo del objeto b

std::cout <<"¿Qué longitud tiene el array a?:" << a.GetLength() << std::endl;
std::cout <<"¿Cuánto zeros tiene el array a?:" << a.CountZeros() << std::endl;//imprime el primer elemento del arreglo del objeto a
std::cout <<"El array a está lleno? :" << a.IsFull() << std::endl;//Verifica si el array está lleno

std::cout <<"Insertando un nuevo elemento :" << a.InsertLast(6) << std::endl;

std::cout <<"Después de la inserción de un último elemnto ¿Qué longitud tiene el array a?:" << a.GetLength() << std::endl;

std::cout <<"Elemento 1 del array a :" << a.GetElement(0) << std::endl;//imprime el primer elemento del arreglo del objeto a
std::cout << "Elemento 2 del array a :" << a.GetElement(1) << std::endl;//imprime el segundo elemento del arreglo del objeto a
std::cout << "Elemento 3 del array a :" << a.GetElement(2) << std::endl;//imprime el segundo elemento del arreglo del objeto a
std::cout <<"Elemento 4 del array a :" << a.GetElement(3) << std::endl;//imprime el primer elemento del arreglo del objeto a
std::cout << "Elemento 5 del array a :" << a.GetElement(4) << std::endl;//imprime el segundo elemento del arreglo del objeto a
std::cout << "Elemento 6 del array a :" << a.GetElement(5) << std::endl;//imprime el segundo elemento del arreglo del objeto a
std::cout <<"Elemento 7 del array a :" << a.GetElement(6) << std::endl;//imprime el primer elemento del arreglo del objeto a
std::cout << "Elemento 8 del array a :" << a.GetElement(7) << std::endl;//imprime el segundo elemento del arreglo del objeto a
std::cout << "Elemento 9 del array a :" << a.GetElement(8) << std::endl;//imprime el segundo elemento del arreglo del objeto a
std::cout <<"Elemento 10 del array a :" << a.GetElement(9) << std::endl;//imprime el primer elemento del arreglo del objeto a
std::cout <<"Elemento 11 del array a :" << a.GetElement(10) << std::endl;//imprime el primer elemento del arreglo del objeto a

int suma = a.Sum();//obtiene la suma de los elementos del arreglo del objeto a
std::cout << "Suma de los elementos del array a:" << suma << std::endl;//imprime la suma de los elementos del arreglo del objeto a

float c = a.Average();//obtiene el promedio de los elementos del arreglo del objeto a
std::cout << "Promedio de los elementos del array a:" << std::fixed <<  std::setprecision(4) << c << std::endl;//imprime el promedio de los elementos del arreglo del objeto a
TArrayInt b(0); //declaración de un objeto de la clase TArrayInt. 5 es el tamaño del arreglo
b.IsEmpty();//verifica si el arreglo del objeto b está vacío 
std::cout << "El array b está vacío?:" << b.IsEmpty() << std::endl;

  return 0;
}