#include "library.h"
#include <iostream>
#include <limits>

// Función para mostrar el menú y obtener la opción del usuario
int mostrarMenu() {
    int opcion;
    std::cout << "\n====== SISTEMA DE BIBLIOTECA ======" << std::endl;
    std::cout << "1. Agregar libro devuelto (PILA)" << std::endl;
    std::cout << "2. Procesar libro devuelto (PILA)" << std::endl;
    std::cout << "3. Mostrar libros devueltos (PILA)" << std::endl;
    std::cout << "4. Reservar un libro (COLA)" << std::endl;
    std::cout << "5. Entregar libro reservado (COLA)" << std::endl;
    std::cout << "6. Mostrar libros reservados (COLA)" << std::endl;
    std::cout << "7. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
    
    while (!(std::cin >> opcion) || opcion < 1 || opcion > 7) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opción inválida. Intente de nuevo: ";
    }
    
    return opcion;
}

// Función para ingresar datos de un libro
Libro ingresarDatosLibro() {
    Libro libro;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Ingrese el título del libro: ";
    std::getline(std::cin, libro.titulo);
    
    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, libro.autor);
    
    std::cout << "Ingrese el ID del libro: ";
    while (!(std::cin >> libro.id) || libro.id <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "ID inválido. Debe ser un número positivo: ";
    }
    
    return libro;
}

// Función principal
int main() {
    Biblioteca biblioteca;
    int opcion;
    Libro libro;
    
    std::cout << "Bienvenido al Sistema de Biblioteca" << std::endl;
    std::cout << "Este programa demuestra el uso de PILAS y COLAS en C++" << std::endl;
    
    do {
        opcion = mostrarMenu();
        
        switch (opcion) {
            case 1: // Agregar libro devuelto (PILA)
                std::cout << "\n== AGREGAR LIBRO DEVUELTO (operación PUSH en PILA) ==" << std::endl;
                biblioteca.agregarLibroDevuelto(ingresarDatosLibro());
                break;
                
            case 2: // Procesar libro devuelto (PILA)
                std::cout << "\n== PROCESAR LIBRO DEVUELTO (operación POP en PILA) ==" << std::endl;
                biblioteca.obtenerLibroDevuelto(libro);
                break;
                
            case 3: // Mostrar libros devueltos (PILA)
                biblioteca.mostrarLibrosDevueltos();
                break;
                
            case 4: // Reservar un libro (COLA)
                std::cout << "\n== RESERVAR LIBRO (operación ENCOLAR en COLA) ==" << std::endl;
                biblioteca.reservarLibro(ingresarDatosLibro());
                break;
                
            case 5: // Entregar libro reservado (COLA)
                std::cout << "\n== ENTREGAR LIBRO RESERVADO (operación DESENCOLAR en COLA) ==" << std::endl;
                biblioteca.entregarLibroReservado(libro);
                break;
                
            case 6: // Mostrar libros reservados (COLA)
                biblioteca.mostrarLibrosReservados();
                break;
                
            case 7: // Salir
                std::cout << "\nGracias por usar el Sistema de Biblioteca." << std::endl;
                break;
        }
        
        if (opcion != 7) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
        
    } while (opcion != 7);
    
    return 0;
}