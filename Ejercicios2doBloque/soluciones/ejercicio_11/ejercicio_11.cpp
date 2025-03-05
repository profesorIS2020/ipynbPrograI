
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double mpg;
    cout << "Ingrese la eficiencia en millas por galón (MPG): ";
    cin >> mpg;
    if(mpg <= 0) {
        cout << "El valor de MPG debe ser positivo." << endl;
        return 1;
    }
    double l_per_100km = 235.214583 / mpg;
    cout << "La eficiencia en litros por 100 km es " << fixed << setprecision(2) << l_per_100km << endl;
    return 0;
}
