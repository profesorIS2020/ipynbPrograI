
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cout << "Ingrese el primer entero: ";
    cin >> a;
    cout << "Ingrese el segundo entero: ";
    cin >> b;

    cout << "La suma de a y b es " << a + b << endl;
    cout << "La diferencia cuando b se resta de a es " << a - b << endl;
    cout << "El producto de a y b es " << a * b << endl;
    if(b != 0) {
        cout << "El cociente cuando a se divide entre b es " << static_cast<double>(a) / b << endl;
        cout << "El resto cuando a se divide entre b es " << a % b << endl;
    } else {
        cout << "División por cero no permitida." << endl;
    }
    if(a > 0) {
        cout << "El resultado de log10(a) es " << log10(a) << endl;
    } else {
        cout << "log10 no definido para a <= 0." << endl;
    }
    cout << "El resultado de a^b es " << pow(a, b) << endl;

    return 0;
}

