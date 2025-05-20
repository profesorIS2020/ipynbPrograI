#include "library.h"
#include <iostream>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <functional>

// Funciones de ordenamiento para demostrar punteros a funciones
void ordenarPorId(std::vector<std::unique_ptr<Libro>>& libros) {
    std::sort(libros.begin(), libros.end(),
        [](const std::unique_ptr<Libro>& a, const std::unique_ptr<Libro>& b) {
            return a->getId() < b->getId();
        });
}

void ordenarPorTitulo(std::vector<std::unique_ptr<Libro>>& libros) {
    std::sort(libros.begin(), libros.end(),
        [](const std::unique_ptr<Libro>& a, const std::unique_ptr<Libro>& b) {
            return a->getTitulo() < b->getTitulo();
        });
}

void ordenarPorAutor(std::vector<std::unique_ptr<Libro>>& libros) {
    std::sort(libros.begin(), libros.end(),
        [](const std::unique_ptr<Libro>& a, const std::unique_ptr<Libro>& b) {
            return a->getAutor() < b->getAutor();
        });
}

// Función para demostrar la modificación de datos a través de referencias
void mostrarYModificarLibros(std::vector<std::reference_wrapper<Libro>>& libros) {
    std::cout << "\n----- Libros encontrados -----" << std::endl;
    for (auto& libroRef : libros) {
        Libro& libro = libroRef.get();
        std::cout << "Libro: " << libro.getTitulo() << " por " << libro.getAutor() << std::endl;
        
        // Modificación directa a través de la referencia
        std::string& autorRef = libro.obtenerAutorModificable();
        autorRef = autorRef + " (Verificado)";
    }
}

int main() {
    try {
        // Crear una biblioteca
        Biblioteca miBiblioteca("Biblioteca Central");
        
        // 1. DEMOSTRACIÓN DE MÉTODOS SIMPLES
        std::cout << "\n===> DEMOSTRACIÓN DE MÉTODOS SIMPLES" << std::endl;
        
        // Agregar algunos libros
        miBiblioteca.agregarLibro(1, "Don Quijote de la Mancha", "Miguel de Cervantes");
        miBiblioteca.agregarLibro(2, "Cien años de soledad", "Gabriel García Márquez");
        miBiblioteca.agregarLibro(3, "El principito", "Antoine de Saint-Exupéry");
        miBiblioteca.agregarLibro(4, "1984", "George Orwell");
        miBiblioteca.agregarLibro(5, "Crimen y castigo", "Fiódor Dostoyevski");
        
        // Mostrar el catálogo inicial
        miBiblioteca.mostrarCatalogo();
        
        // 2. DEMOSTRACIÓN DE MÉTODOS CON PUNTEROS
        std::cout << "\n===> DEMOSTRACIÓN DE MÉTODOS CON PUNTEROS" << std::endl;
        
        // Obtener un libro usando puntero
        Libro* libro1984 = miBiblioteca.obtenerLibro(4);
        if (libro1984) {
            std::cout << "Libro encontrado por puntero: " << libro1984->getTitulo() << std::endl;
            
            // Modificar el libro a través del puntero
            libro1984->actualizarTitulo("1984 (Edición Especial)");
            std::cout << "Título actualizado: " << libro1984->getTitulo() << std::endl;
        }
        
        // Eliminar un libro
        bool eliminado = miBiblioteca.eliminarLibro(5);
        std::cout << "¿Libro eliminado? " << (eliminado ? "Sí" : "No") << std::endl;
        
        // 3. DEMOSTRACIÓN DE MÉTODOS CON REFERENCIAS
        std::cout << "\n===> DEMOSTRACIÓN DE MÉTODOS CON REFERENCIAS" << std::endl;
        
        // Prestar un libro usando referencia para el estado
        bool exitoPrestamo = false;
        miBiblioteca.prestarLibro(1, exitoPrestamo);
        std::cout << "¿Préstamo exitoso? " << (exitoPrestamo ? "Sí" : "No") << std::endl;
        
        // Mostrar catálogo actualizado
        miBiblioteca.mostrarCatalogo();
        
        // Devolver el libro
        bool exitoDevolucion = false;
        miBiblioteca.devolverLibro(1, exitoDevolucion);
        std::cout << "¿Devolución exitosa? " << (exitoDevolucion ? "Sí" : "No") << std::endl;
        
        // 4. DEMOSTRACIÓN DE MÉTODOS COMPLEJOS CON EXCEPCIONES
        std::cout << "\n===> DEMOSTRACIÓN DE MÉTODOS CON EXCEPCIONES" << std::endl;
        
        try {
            const Libro& libroEncontrado = miBiblioteca.buscarLibroPorTitulo("El principito");
            std::cout << "Libro encontrado: " << libroEncontrado.getTitulo() 
                      << " por " << libroEncontrado.getAutor() << std::endl;
            
            // Intentar buscar un libro que no existe
            const Libro& libroNoExistente = miBiblioteca.buscarLibroPorTitulo("Libro inexistente");
        }
        catch (const BibliotecaException& e) {
            std::cout << "Excepción capturada: " << e.what() << std::endl;
        }
        
        // 5. DEMOSTRACIÓN DE MÉTODOS MÁS COMPLEJOS CON REFERENCIAS Y ALGORITMOS
        std::cout << "\n===> DEMOSTRACIÓN DE MÉTODOS COMPLEJOS" << std::endl;
        
        // Buscar libros por autor y modificarlos usando referencias
        auto librosGabriel = miBiblioteca.buscarLibrosPorAutor("Gabriel García Márquez");
        mostrarYModificarLibros(librosGabriel);
        
        // Mostrar catálogo actualizado después de modificar los autores
        miBiblioteca.mostrarCatalogo();
        
        // 6. DEMOSTRACIÓN DE MÉTODOS MUY COMPLEJOS CON PUNTEROS A FUNCIONES
        std::cout << "\n===> DEMOSTRACIÓN DE MÉTODOS MUY COMPLEJOS" << std::endl;
        
        std::cout << "\nOrdenamiento por título:" << std::endl;
        miBiblioteca.reorganizarColeccion(ordenarPorTitulo);
        miBiblioteca.mostrarCatalogo();
        
        std::cout << "\nOrdenamiento por autor:" << std::endl;
        miBiblioteca.reorganizarColeccion(ordenarPorAutor);
        miBiblioteca.mostrarCatalogo();
        
        std::cout << "\nOrdenamiento por ID:" << std::endl;
        miBiblioteca.reorganizarColeccion(ordenarPorId);
        miBiblioteca.mostrarCatalogo();
        
        // Demostrar manejo de errores con intentos de operaciones inválidas
        std::cout << "\n===> DEMOSTRACIÓN DE MANEJO DE ERRORES" << std::endl;
        
        try {
            // Intentar agregar un libro con ID duplicado
            miBiblioteca.agregarLibro(1, "Libro duplicado", "Autor X");
        }
        catch (const BibliotecaException& e) {
            std::cout << "Error atrapado: " << e.what() << std::endl;
        }
        
    }
    catch (const std::exception& e) {
        std::cerr << "Error general: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n¡Programa finalizado correctamente!" << std::endl;
    return 0;
}