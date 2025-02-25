/** Escribe un programa que le pida al usuario que ingrese su nombre. El programa debe responder con un mensaje que diga hola al usuario, 
usando su nombre. Utiliza 13 líneas de código **/
#include <iostream>
#include <string>
using namespace std;
/** Programa que pide el nombre al usuario y lo saluda*/
int main() {
    string nombre;
    cout << "Ingrese su nombre: ";
//   Obtener el nombre por línea de comandos 
    getline(cin, nombre);
//Mostrar el resultado
    cout << "Hola, " << nombre << "!" << endl;
    return 0;
}
