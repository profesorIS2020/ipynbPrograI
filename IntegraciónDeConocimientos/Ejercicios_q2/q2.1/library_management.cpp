#include "library_management.h"
#include <iostream>
#include <algorithm>

// Constructor de la clase Biblioteca
Biblioteca::Biblioteca() : numLibros(0) {
    // Inicializar el cat�logo con libros vac�os
    for (auto& libro : catalogo) {
        libro = Libro();
    }
}

// M�todo para agregar un libro al cat�logo
void Biblioteca::agregarLibro(const Libro& libro) {
    try {
        if (numLibros >= MAX_LIBROS) {
            throw BibliotecaException("Error: Capacidad m�xima de la biblioteca alcanzada");
        }
        
        // Verificar si ya existe un libro con el mismo ID
        for (int i = 0; i < numLibros; i++) {
            if (catalogo[i].id == libro.id && libro.id != 0) {
                throw BibliotecaException("Error: Ya existe un libro con el ID " + std::to_string(libro.id));
            }
        }
        
        // Agregar el libro al cat�logo
        catalogo[numLibros] = libro;
        numLibros++;
        std::cout << "Libro \"" << libro.titulo << "\" agregado con �xito." << std::endl;
    }
    catch (const BibliotecaException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
    catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
        throw BibliotecaException("Error interno al agregar libro");
    }
}

// M�todo para prestar un libro
void Biblioteca::prestarLibro(int id) {
    try {
        bool encontrado = false;
        
        for (int i = 0; i < numLibros; i++) {
            if (catalogo[i].id == id) {
                encontrado = true;
                if (!catalogo[i].disponible) {
                    throw BibliotecaException("Error: El libro ya est� prestado");
                }
                catalogo[i].disponible = false;
                std::cout << "Libro \"" << catalogo[i].titulo << "\" prestado con �xito." << std::endl;
                break;
            }
        }
        
        if (!encontrado) {
            throw BibliotecaException("Error: No se encontr� un libro con el ID " + std::to_string(id));
        }
    }
    catch (const BibliotecaException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
}

// M�todo para devolver un libro
void Biblioteca::devolverLibro(int id) {
    try {
        bool encontrado = false;
        
        for (int i = 0; i < numLibros; i++) {
            if (catalogo[i].id == id) {
                encontrado = true;
                if (catalogo[i].disponible) {
                    throw BibliotecaException("Error: El libro no estaba prestado");
                }
                catalogo[i].disponible = true;
                std::cout << "Libro \"" << catalogo[i].titulo << "\" devuelto con �xito." << std::endl;
                break;
            }
        }
        
        if (!encontrado) {
            throw BibliotecaException("Error: No se encontr� un libro con el ID " + std::to_string(id));
        }
    }
    catch (const BibliotecaException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
}

// M�todo para buscar un libro por su ID
Libro Biblioteca::buscarPorId(int id) const {
    for (int i = 0; i < numLibros; i++) {
        if (catalogo[i].id == id) {
            return catalogo[i];
        }
    }
    throw BibliotecaException("Error: No se encontr� un libro con el ID " + std::to_string(id));
}

// M�todo para mostrar el cat�logo completo
void Biblioteca::mostrarCatalogo() const {
    if (numLibros == 0) {
        std::cout << "La biblioteca est� vac�a." << std::endl;
        return;
    }
    
    std::cout << "=== CAT�LOGO DE LIBROS ===" << std::endl;
    for (int i = 0; i < numLibros; i++) {
        std::cout << "ID: " << catalogo[i].id << std::endl;
        std::cout << "T�tulo: " << catalogo[i].titulo << std::endl;
        std::cout << "Autor: " << catalogo[i].autor << std::endl;
        std::cout << "Estado: " << (catalogo[i].disponible ? "Disponible" : "Prestado") << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

// M�todo para contar libros disponibles
int Biblioteca::contarDisponibles() const {
    int contador = 0;
    for (int i = 0; i < numLibros; i++) {
        if (catalogo[i].disponible) {
            contador++;
        }
    }
    return contador;
}
