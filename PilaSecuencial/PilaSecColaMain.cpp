#include <iostream>
#include <string>
#include "PilaCola.h"
int main()
{
 /* std::cout << "Pila Secuencial" << std::endl;
  TListaS pila(5);
  std::string* cadena;
  std::cout <<  pila.Vacia() << std::endl;

  cadena = new std::string("Hola");
  pila.Anadir(cadena);
  cadena = new std::string("Mundo");
  pila.Anadir(cadena);
  cadena = new std::string("!");
  pila.Anadir(cadena);
   std::cout <<  pila.Longitud() << std::endl;
   std::cout <<  pila.Vacia() << std::endl;

  while (!pila.Vacia())
  {
    cadena = (std::string*)pila.Eliminar(pila.Longitud() - 1);
    std::cout << *cadena << std::endl;
  }
  std::cout <<  pila.Vacia() << std::endl;*/
  TPilaSec pila(5);
  std::string* cadena;
  std::cout <<   "Preguntando si la pila está vacía : " << pila.Vacia() << std::endl;
  pila.Anadir(new std::string("Hola"));
  pila.Anadir(new std::string("Mundo"));
  pila.Anadir(new std::string("!"));
  std::cout <<  "Monitoreo de la longitud de la pila : " << pila.Longitud() << std::endl;
  std::cout <<  "Preguntando si la pila está vacía nuevamente : " << pila.Vacia() << std::endl;
  cadena = (std::string*)pila.Primero();
  std::cout << "Pidiendo el primero : " << *cadena << std::endl;
  while (!pila.Vacia())
  {
    cadena = (std::string*)pila.Primero();
    std::cout << "Pidiendo el primero antes de eliminar: " << *cadena << std::endl;
    cadena = (std::string*)pila.Eliminar();
    std::cout << "Eliminando " << *cadena << std::endl;
  }
  std::cout <<  "Preguntando si la pila está vacía después de eliminar todo : " << pila.Vacia() << std::endl;
  return 0;
}

