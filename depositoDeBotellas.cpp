
#include <iostream>
#include <iomanip>
using namespace std;
/*Programa para leer el número de contenedores y mostrar reembolso*/
int main() {
    int lessThanOne, moreThanOne;
    cout << "Ingrese el número de contenedores de 1 litro o menos: ";
    cin >> lessThanOne;
    cout << "Ingrese el número de contenedores de más de 1 litro: ";
    cin >> moreThanOne;
    // Calcular el reembolso
    double refund = (lessThanOne * 0.10) + (moreThanOne * 0.25);
   //Mostrar el reembolso
    cout << "El reembolso total es $ " << std::fixed << std::setprecision(2) << refund << endl;
    return 0;
}
