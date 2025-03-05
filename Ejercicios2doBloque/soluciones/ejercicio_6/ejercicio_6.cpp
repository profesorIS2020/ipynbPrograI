
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double cost;
    cout << "Ingrese el costo de la comida: ";
    cin >> cost;

    double tax = cost * 0.05; // Tasa de impuesto del 5%
    double tip = cost * 0.18;
    double total = cost + tax + tip;

    cout << "Impuesto: $ " << fixed << setprecision(2) << tax << endl;
    cout << "Propina: $ " << tip << endl;
    cout << "Total: $ " << total << endl;
    return 0;
}
