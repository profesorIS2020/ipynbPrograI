
 // Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector {
private:
    double* elementos;  // Pointer: dynamic array to store elements
    int dimension;      // Number of elements (vector dimension)

public:
    // Constructors and Destructor
    Vector();                        // Default constructor
    Vector(int dim);                // Constructor with specific dimension
    Vector(const Vector& otro);     // Copy constructor (uses deep copy)
    ~Vector();                      // Destructor: free memory

    // Assignment operator
    Vector& operator=(const Vector& otro);  // Deep copy assignment

    // Accessor methods
    int getDimension() const;
    double getElemento(int indice) const;
    void setElemento(int indice, double valor);

    // Basic operations
    double calcularMagnitud() const;
    void mostrar() const;

    // Operations using references (const Vector&)
    Vector sumar(const Vector& otro) const;
    Vector restar(const Vector& otro) const;
    double productoPunto(const Vector& otro) const;

    // Advanced operations using references and pointers
    Vector& normalizar();                     // Modifies this object, returns a reference to self
    double calcularAngulo(const Vector& otro) const;
    Vector* proyectar(const Vector& otro) const; // Returns pointer to new Vector object (heap)

    // Static method using pointer-to-pointer (const Vector**)
    static bool sonOrtogonales(const Vector** vectores, int numVectores);
};

#endif // VECTOR_H
