/** Escribe un programa que le pida al usuario que ingrese el ancho y el largo de una habitación. 
Una vez que se hayan leído los valores, tu programa debe calcular y mostrar el área de la habitación. 
El largo y el ancho se ingresarán como números de punto flotante. Incluye unidades en tu prompt y mensaje de salida; 
ya sea pies o metros, dependiendo de con qué unidad te sientas más cómodo trabajando. Utilice 14 líneas de código **/

#include <iostream>
using namespace std;
/*Programa para calcular el área de una habitación*/
int main() {
    double largo, ancho;
    cout << "Ingrese la longitud de la habitación en metros: ";
    cin >> largo;
    cout << "Ingrese el ancho de la habitación en metros: ";
    cin >> ancho;
    double area = largo * ancho;
// Mostrar el resultado
    cout << "El área de la habitación es " << area << " metros cuadrados." << endl;
    return 0;
}
