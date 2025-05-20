// main.cpp
#include "Vector.h"
#include <iostream>
/*g++ -o vector main.cpp Vector.cpp */

// Function using REFERENCE: modifies the original vector
void escalarPorReferencia(Vector& v, double escalar) {
    for (int i = 0; i < v.getDimension(); ++i) {
        double valor = v.getElemento(i);
        v.setElemento(i, valor * escalar);
    }
}

// Function using POINTER: modifies the original vector
void escalarPorPuntero(Vector* v, double escalar) {
    for (int i = 0; i < v->getDimension(); ++i) {
        double valor = v->getElemento(i);
        v->setElemento(i, valor * escalar);
    }
}

// Function that returns a dynamically allocated vector
Vector* crearVectorUnitario(int dim, double valor) {
    Vector* v = new Vector(dim);
    for (int i = 0; i < dim; ++i) {
        v->setElemento(i, valor);
    }
    return v;
}

int main() {
    try {
        std::cout << "\n Crear vector original:\n";
        Vector v1(3);
        v1.setElemento(0, 1.0);
        v1.setElemento(1, 2.0);
        v1.setElemento(2, 3.0);
        v1.mostrar();

        std::cout << "\n Escalar por REFERENCIA (x2):\n";
        escalarPorReferencia(v1, 2.0);  // Pass by reference
        v1.mostrar();

        std::cout << "\n Escalar por PUNTERO (x0.5):\n";
        escalarPorPuntero(&v1, 0.5);  // Pass by pointer
        v1.mostrar();

        std::cout << "\n Copia PROFUNDA (deep copy):\n";
        Vector v2 = v1;  // Copy constructor
        escalarPorReferencia(v2, 10.0);
        std::cout << "Original: ";
        v1.mostrar();
        std::cout << "Copia    : ";
        v2.mostrar();

        std::cout << "\n Proyección (uso de puntero como retorno):\n";
        Vector base(3);
        base.setElemento(0, 1);
        base.setElemento(1, 0);
        base.setElemento(2, 0);

        Vector* proy = v1.proyectar(base);  // Devuelve puntero
        proy->mostrar();
        delete proy;  //  Evita fuga de memoria

        std::cout << "\n Conjunto de vectores y ortogonalidad:\n";
        Vector* vx = crearVectorUnitario(3, 1);
        Vector* vy = crearVectorUnitario(3, 0);
        vy->setElemento(1, 1);  // vx = [1,1,1], vy = [0,1,0]
        Vector* vz = crearVectorUnitario(3, 0);
        vz->setElemento(2, 1);  // vz = [0,0,1]

        const Vector* vectores[] = { vx, vy, vz };
        bool orto = Vector::sonOrtogonales(vectores, 3);
        std::cout << "¿Son ortogonales? " << (orto ? "Sí" : "No") << std::endl;

        std::cout << "\n Liberando memoria manualmente:\n";
        delete vx;
        delete vy;
        delete vz;

    } catch (const std::exception& e) {
        std::cerr << " Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
