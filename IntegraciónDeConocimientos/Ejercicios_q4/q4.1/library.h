#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <iostream>

// Estructura para representar un libro
struct Libro {
    std::string titulo;
    std::string autor;
    int id;
};

// Estructura para un nodo de pila o cola
struct Nodo {
    Libro libro;
    Nodo* siguiente;
};

// Clase para implementar una pila (Stack - LIFO: Last In First Out)
class Pila {
private:
    Nodo* tope;
    int tamaño;

public:
    Pila();
    ~Pila();
    void push(const Libro& libro);
    bool pop(Libro& libro);
    bool estaVacia() const;
    int obtenerTamaño() const;
    void mostrar() const;
};

// Clase para implementar una cola (Queue - FIFO: First In First Out)
class Cola {
private:
    Nodo* frente;
    Nodo* final;
    int tamaño;

public:
    Cola();
    ~Cola();
    void encolar(const Libro& libro);
    bool desencolar(Libro& libro);
    bool estaVacia() const;
    int obtenerTamaño() const;
    void mostrar() const;
};

// Clase principal de la biblioteca
class Biblioteca {
private:
    Pila librosDevueltos;
    Cola librosReservados;

public:
    Biblioteca();
    void agregarLibroDevuelto(const Libro& libro);
    bool obtenerLibroDevuelto(Libro& libro);
    void reservarLibro(const Libro& libro);
    bool entregarLibroReservado(Libro& libro);
    void mostrarLibrosDevueltos() const;
    void mostrarLibrosReservados() const;
};

#endif // LIBRARY_H