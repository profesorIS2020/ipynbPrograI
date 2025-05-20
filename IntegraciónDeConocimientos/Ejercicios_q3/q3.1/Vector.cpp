// Vector.cpp
#include "Vector.h"

// Constructor por defecto
Vector::Vector() : dimension(0), elementos(nullptr) {
    // No se asigna memoria si no se indica una dimensión
}

// Constructor con dimensión
Vector::Vector(int dim) : dimension(dim) {
    if (dim <= 0)
        throw std::invalid_argument("La dimensión debe ser positiva.");
    elementos = new double[dim];  // Memoria dinámica con new
    for (int i = 0; i < dim; ++i)
        elementos[i] = 0.0;       // Inicializa a ceros
}

// Constructor de copia (deep copy)
Vector::Vector(const Vector& otro) : dimension(otro.dimension) {
    elementos = new double[dimension];  // Copia profunda: nueva memoria
    for (int i = 0; i < dimension; ++i)
        elementos[i] = otro.elementos[i];
}

// Destructor
Vector::~Vector() {
    delete[] elementos;  // Liberación de memoria dinámica
}

// Operador de asignación (deep copy + self-assignment)
Vector& Vector::operator=(const Vector& otro) {
    if (this != &otro) {  // Evita auto-asignación
        delete[] elementos;  // Limpia datos actuales
        dimension = otro.dimension;
        elementos = new double[dimension];  // Nueva memoria
        for (int i = 0; i < dimension; ++i)
            elementos[i] = otro.elementos[i];
    }
    return *this;
}

// Getters
int Vector::getDimension() const {
    return dimension;
}

double Vector::getElemento(int indice) const {
    if (indice < 0 || indice >= dimension)
        throw std::out_of_range("Índice fuera de rango.");
    return elementos[indice];
}

void Vector::setElemento(int indice, double valor) {
    if (indice < 0 || indice >= dimension)
        throw std::out_of_range("Índice fuera de rango.");
    elementos[indice] = valor;
}

// Magnitud (norma Euclídea)
double Vector::calcularMagnitud() const {
    double suma = 0.0;
    for (int i = 0; i < dimension; ++i)
        suma += elementos[i] * elementos[i];
    return std::sqrt(suma);
}

// Mostrar el vector
void Vector::mostrar() const {
    std::cout << "[ ";
    for (int i = 0; i < dimension; ++i)
        std::cout << elementos[i] << " ";
    std::cout << "]" << std::endl;
}

// Suma de vectores usando REFERENCIA
Vector Vector::sumar(const Vector& otro) const {
    if (dimension != otro.dimension)
        throw std::invalid_argument("Las dimensiones no coinciden.");
    Vector resultado(dimension);
    for (int i = 0; i < dimension; ++i)
        resultado.elementos[i] = elementos[i] + otro.elementos[i];
    return resultado;  // Devuelve copia (por valor)
}

// Resta de vectores
Vector Vector::restar(const Vector& otro) const {
    if (dimension != otro.dimension)
        throw std::invalid_argument("Las dimensiones no coinciden.");
    Vector resultado(dimension);
    for (int i = 0; i < dimension; ++i)
        resultado.elementos[i] = elementos[i] - otro.elementos[i];
    return resultado;
}

// Producto punto
double Vector::productoPunto(const Vector& otro) const {
    if (dimension != otro.dimension)
        throw std::invalid_argument("Las dimensiones no coinciden.");
    double suma = 0.0;
    for (int i = 0; i < dimension; ++i)
        suma += elementos[i] * otro.elementos[i];
    return suma;
}

// Normaliza el vector (modifica este objeto → devuelve REFERENCIA)
Vector& Vector::normalizar() {
    double mag = calcularMagnitud();
    if (mag == 0)
        throw std::runtime_error("No se puede normalizar un vector nulo.");
    for (int i = 0; i < dimension; ++i)
        elementos[i] /= mag;
    return *this;  // Devuelve referencia a sí mismo
}

// Calcula el ángulo entre dos vectores
double Vector::calcularAngulo(const Vector& otro) const {
    double producto = productoPunto(otro);
    double mags = calcularMagnitud() * otro.calcularMagnitud();
    if (mags == 0)
        throw std::runtime_error("No se puede calcular el ángulo con un vector nulo.");
    return std::acos(producto / mags);  // Radianes
}

// Proyección sobre otro vector → devuelve PUNTERO a nuevo objeto
Vector* Vector::proyectar(const Vector& otro) const {
    if (dimension != otro.dimension)
        throw std::invalid_argument("Las dimensiones no coinciden.");
    double escalar = productoPunto(otro) / otro.productoPunto(otro);
    Vector* proy = new Vector(dimension);  //  Memoria dinámica → debe liberarse luego
    for (int i = 0; i < dimension; ++i)
        proy->elementos[i] = escalar * otro.elementos[i];
    return proy;
}

// Verifica ortogonalidad entre varios vectores (usa PUNTERO a PUNTERO)
bool Vector::sonOrtogonales(const Vector** vectores, int numVectores) {
    for (int i = 0; i < numVectores; ++i) {
        for (int j = i + 1; j < numVectores; ++j) {
            if (vectores[i]->productoPunto(*vectores[j]) != 0)
                return false;
        }
    }
    return true;
}
