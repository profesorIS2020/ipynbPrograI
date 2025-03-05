
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double deposito;
    cout << "Ingrese la cantidad de dinero depositada: ";
    cin >> deposito;

    double tasa = 0.04; // 4% anual
    for (int anio = 1; anio <= 3; anio++) {
        double saldo = deposito * pow(1 + tasa, anio);
        cout << "Saldo despues de " << anio << " año(s): $" << fixed << setprecision(2) << saldo << endl;
    }
    return 0;
}
