/** Crea un programa que lea el largo y el ancho del campo de un granjero del usuario en pies. Muestra el área del campo en acres. Resuélvelo en 14 líneas
Pista: Hay 43,560 pies cuadrados en un acre.**/

#include <iostream>
using namespace std;
/*Programa que calcula el área de un campo en acres*/
int main() {
    double largo, ancho;
    cout << "Ingrese el largo del campo en pies: ";
    cin >> largo;
    cout << "Ingrese el ancho del campo en pies: ";
    cin >> ancho;
// Cálculo del área en acres
    double acres = (largo * ancho) / 43560.0;
    cout << "El área del campo es " << acres << " acres." << endl;
    return 0;
}
