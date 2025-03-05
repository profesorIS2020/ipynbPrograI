
#include <iostream>
using namespace std;

int main() {
    int widgets, gizmos;
    cout << "Ingrese el número de widgets: ";
    cin >> widgets;
    cout << "Ingrese el número de gizmos: ";
    cin >> gizmos;

    int totalWeight = widgets * 75 + gizmos * 112;
    cout << "El peso total del pedido es " << totalWeight << " gramos." << endl;
    return 0;
}

