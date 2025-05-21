#include "library.h"
#include <iostream>

// Implementación de la clase Pila
Pila::Pila() : tope(nullptr), tamaño(0) {}

Pila::~Pila() {
    while (!estaVacia()) {
        Libro libro;
        pop(libro);
    }
}

void Pila::push(const Libro& libro) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->libro = libro;
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
    tamaño++;
}

bool Pila::pop(Libro& libro) {
    if (estaVacia()) {
        return false;
    }
    
    Nodo* temp = tope;
    libro = temp->libro;
    tope = tope->siguiente;
    delete temp;
    tamaño--;
    return true;
}

bool Pila::estaVacia() const {
    return tope == nullptr;
}

int Pila::obtenerTamaño() const {
    return tamaño;
}

void Pila::mostrar() const {
    if (estaVacia()) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }
    
    std::cout << "Contenido de la pila (desde el tope):" << std::endl;
    Nodo* actual = tope;
    int posicion = 1;
    
    while (actual != nullptr) {
        std::cout << posicion << ". ID: " << actual->libro.id 
                 << ", Título: " << actual->libro.titulo 
                 << ", Autor: " << actual->libro.autor << std::endl;
        actual = actual->siguiente;
        posicion++;
    }
}

// Implementación de la clase Cola
Cola::Cola() : frente(nullptr), final(nullptr), tamaño(0) {}

Cola::~Cola() {
    while (!estaVacia()) {
        Libro libro;
        desencolar(libro);
    }
}

void Cola::encolar(const Libro& libro) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->libro = libro;
    nuevoNodo->siguiente = nullptr;
    
    if (estaVacia()) {
        frente = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
    }
    
    final = nuevoNodo;
    tamaño++;
}

bool Cola::desencolar(Libro& libro) {
    if (estaVacia()) {
        return false;
    }
    
    Nodo* temp = frente;
    libro = temp->libro;
    frente = frente->siguiente;
    
    if (frente == nullptr) {
        final = nullptr;
    }
    
    delete temp;
    tamaño--;
    return true;
}

bool Cola::estaVacia() const {
    return frente == nullptr;
}

int Cola::obtenerTamaño() const {
    return tamaño;
}

void Cola::mostrar() const {
    if (estaVacia()) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }
    
    std::cout << "Contenido de la cola (desde el frente):" << std::endl;
    Nodo* actual = frente;
    int posicion = 1;
    
    while (actual != nullptr) {
        std::cout << posicion << ". ID: " << actual->libro.id 
                 << ", Título: " << actual->libro.titulo 
                 << ", Autor: " << actual->libro.autor << std::endl;
        actual = actual->siguiente;
        posicion++;
    }
}

// Implementación de la clase Biblioteca
Biblioteca::Biblioteca() {}

void Biblioteca::agregarLibroDevuelto(const Libro& libro) {
    librosDevueltos.push(libro);
    std::cout << "Libro '" << libro.titulo << "' agregado a la pila de libros devueltos." << std::endl;
}

bool Biblioteca::obtenerLibroDevuelto(Libro& libro) {
    if (librosDevueltos.estaVacia()) {
        std::cout << "No hay libros devueltos disponibles." << std::endl;
        return false;
    }
    
    librosDevueltos.pop(libro);
    std::cout << "Libro '" << libro.titulo << "' retirado de la pila de libros devueltos." << std::endl;
    return true;
}

void Biblioteca::reservarLibro(const Libro& libro) {
    librosReservados.encolar(libro);
    std::cout << "Libro '" << libro.titulo << "' agregado a la cola de reservas." << std::endl;
}

bool Biblioteca::entregarLibroReservado(Libro& libro) {
    if (librosReservados.estaVacia()) {
        std::cout << "No hay libros reservados pendientes." << std::endl;
        return false;
    }
    
    librosReservados.desencolar(libro);
    std::cout << "Libro '" << libro.titulo << "' entregado de la cola de reservas." << std::endl;
    return true;
}

void Biblioteca::mostrarLibrosDevueltos() const {
    std::cout << "\n=== LIBROS DEVUELTOS RECIENTEMENTE (PILA) ===" << std::endl;
    librosDevueltos.mostrar();
}

void Biblioteca::mostrarLibrosReservados() const {
    std::cout << "\n=== LIBROS RESERVADOS (COLA) ===" << std::endl;
    librosReservados.mostrar();
}