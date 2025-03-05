
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un entero positivo: ";
    cin >> n;
    int suma = (n * (n + 1)) / 2;
    cout << "La suma de los primeros " << n << " enteros positivos es " << suma << endl;
    return 0;
}
