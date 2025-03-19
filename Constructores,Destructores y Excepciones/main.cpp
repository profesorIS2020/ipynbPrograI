

#include "TListaNumerosEnterosSeq.h"
#include <iostream>

int main() {
std::cout << "Esta es una compilación de la lista" << std::endl;
    // Crear una lista con capacidad para 10 elementos
    //TListaNumerosEnterosSeq lista(10);
    TListaNumerosEnterosSeq lista(10, 10);

    // Añadir algunos números a la lista
    for (int i = 0; i < 10; i++) {
        lista.Anadir(i);
    }

    // Imprimir los elementos de la lista
    for (int i = 0; i < lista.Longitud(); i++) {
        std::cout << lista.Obtener(i) << std::endl;
    }

    return 0;
}