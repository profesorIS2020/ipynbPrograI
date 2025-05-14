#include <iostream>
#include "library_management.h"
/*para compilar  g++ -std=c++11 q1.cpp main.cpp -o library*/
int main() {
    try {
        // Crear instancia de la biblioteca
        Biblioteca miBiblioteca;
        
        // Agregar algunos libros
        miBiblioteca.agregarLibro(Libro(1, "Don Quijote de la Mancha", "Miguel de Cervantes", true));
        miBiblioteca.agregarLibro(Libro(2, "Cien a�os de soledad", "Gabriel Garc�a M�rquez", true));
        miBiblioteca.agregarLibro(Libro(3, "El principito", "Antoine de Saint-Exup�ry", true));
        
        // Mostrar el cat�logo inicial
        std::cout << "\nMostrando cat�logo inicial:" << std::endl;
        miBiblioteca.mostrarCatalogo();
        
        // Prestar un libro
        std::cout << "\nPrestando libro ID 2:" << std::endl;
        try {
            miBiblioteca.prestarLibro(2);
        } catch (const BibliotecaException& e) {
            std::cerr << "Error al prestar: " << e.what() << std::endl;
        }
        
        // Intentar prestar un libro ya prestado
        std::cout << "\nIntentando prestar libro ya prestado (ID 2):" << std::endl;
        try {
            miBiblioteca.prestarLibro(2);
        } catch (const BibliotecaException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }
        
        // Intentar buscar un libro inexistente
        std::cout << "\nBuscando libro inexistente (ID 10):" << std::endl;
        try {
            Libro libro = miBiblioteca.buscarPorId(10);
            std::cout << "Libro encontrado: " << libro.titulo << std::endl;
        } catch (const BibliotecaException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }
        
        // Devolver un libro
        std::cout << "\nDevolviendo libro ID 2:" << std::endl;
        try {
            miBiblioteca.devolverLibro(2);
        } catch (const BibliotecaException& e) {
            std::cerr << "Error al devolver: " << e.what() << std::endl;
        }
        
        // Mostrar cat�logo actualizado
        std::cout << "\nMostrando cat�logo actualizado:" << std::endl;
        miBiblioteca.mostrarCatalogo();
        
        // Contar libros disponibles
        std::cout << "\nLibros disponibles: " << miBiblioteca.contarDisponibles() << std::endl;
        
        // Intentar agregar un libro con ID duplicado
        std::cout << "\nIntentando agregar libro con ID duplicado:" << std::endl;
        try {
            miBiblioteca.agregarLibro(Libro(1, "Libro duplicado", "Autor X", true));
        } catch (const BibliotecaException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error general: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
