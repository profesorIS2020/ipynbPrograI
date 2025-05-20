#include "library.h"
#include <iostream>
#include <algorithm>
#include <functional>

// Implementación de la excepción personalizada
BibliotecaException::BibliotecaException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

// ----- IMPLEMENTACIÓN DE LIBRO -----

// Constructor
Libro::Libro(int id, const std::string& titulo, const std::string& autor)
    : id(id), titulo(titulo), autor(autor), disponible(true) {
    std::cout << "Libro creado: " << titulo << " por " << autor << std::endl;
}

// Destructor
Libro::~Libro() {
    std::cout << "Libro eliminado: " << titulo << std::endl;
}

// Métodos básicos (getters)
int Libro::getId() const {
    return id;
}

std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}

bool Libro::estaDisponible() const {
    return disponible;
}

// Método con referencia como parámetro
void Libro::cambiarDisponibilidad(bool& estado) {
    disponible = estado;
    // Además, actualiza el estado pasado por referencia para mostrar que fue exitoso
    estado = true;
}

// Método con parámetro const reference (común para strings para evitar copias)
void Libro::actualizarTitulo(const std::string& nuevoTitulo) {
    titulo = nuevoTitulo;
}

// Método que devuelve una referencia (permite modificar directamente)
std::string& Libro::obtenerAutorModificable() {
    return autor;
}

// Método con parámetros por valor y por referencia
void Libro::actualizarDetalles(std::string nuevoTitulo, const std::string& nuevoAutor) {
    // nuevoTitulo es una copia (parámetro por valor)
    // nuevoAutor es una referencia constante (evita copias)
    titulo = nuevoTitulo;
    autor = nuevoAutor;
}

// ----- IMPLEMENTACIÓN DE BIBLIOTECA -----

// Constructor
Biblioteca::Biblioteca(const std::string& nombre) : nombre(nombre) {
    std::cout << "Biblioteca inicializada: " << nombre << std::endl;
}

// Destructor
Biblioteca::~Biblioteca() {
    std::cout << "Biblioteca cerrada: " << nombre << std::endl;
    // No necesitamos liberar memoria manualmente gracias a unique_ptr
}

// Métodos privados de búsqueda (sobrecargados para versión const y no-const)
Libro* Biblioteca::buscarLibroPorId(int id) {
    for (auto& libro : coleccion) {
        if (libro->getId() == id) {
            return libro.get(); // Devuelve un puntero crudo (raw pointer)
        }
    }
    return nullptr; // No encontrado
}

const Libro* Biblioteca::buscarLibroPorId(int id) const {
    for (const auto& libro : coleccion) {
        if (libro->getId() == id) {
            return libro.get();
        }
    }
    return nullptr;
}

// Método simple: Agregar libro
void Biblioteca::agregarLibro(int id, const std::string& titulo, const std::string& autor) {
    // Verificar que no exista ya un libro con el mismo ID
    if (buscarLibroPorId(id) != nullptr) {
        throw BibliotecaException("Error: Ya existe un libro con el ID " + std::to_string(id));
    }
    
    // Crear un nuevo libro con puntero inteligente
    std::unique_ptr<Libro> nuevoLibro = std::make_unique<Libro>(id, titulo, autor);
    coleccion.push_back(std::move(nuevoLibro));
}

// Método simple: Mostrar catálogo
void Biblioteca::mostrarCatalogo() const {
    std::cout << "\n----- Catálogo de la Biblioteca " << nombre << " -----" << std::endl;
    
    if (coleccion.empty()) {
        std::cout << "El catálogo está vacío." << std::endl;
        return;
    }
    
    for (const auto& libro : coleccion) {
        std::cout << "ID: " << libro->getId() 
                  << " | Título: " << libro->getTitulo() 
                  << " | Autor: " << libro->getAutor()
                  << " | Estado: " << (libro->estaDisponible() ? "Disponible" : "Prestado")
                  << std::endl;
    }
    std::cout << "---------------------------------------------\n" << std::endl;
}

// Método con puntero: Obtener libro
Libro* Biblioteca::obtenerLibro(int id) {
    return buscarLibroPorId(id);
}

// Método con puntero: Eliminar libro
bool Biblioteca::eliminarLibro(int id) {
    auto it = std::find_if(coleccion.begin(), coleccion.end(), 
                          [id](const std::unique_ptr<Libro>& libro) {
                              return libro->getId() == id;
                          });
    
    if (it != coleccion.end()) {
        coleccion.erase(it); // El destructor de unique_ptr libera la memoria
        return true;
    }
    
    return false;
}

// Método con referencia: Prestar libro
void Biblioteca::prestarLibro(int id, bool& exito) {
    exito = false; // Por defecto, asumimos que no será exitoso
    
    Libro* libro = buscarLibroPorId(id);
    if (libro && libro->estaDisponible()) {
        bool disponible = false; // Cambiamos a no disponible
        libro->cambiarDisponibilidad(disponible);
        exito = true;
    }
}

// Método con referencia: Devolver libro
void Biblioteca::devolverLibro(int id, bool& exito) {
    exito = false;
    
    Libro* libro = buscarLibroPorId(id);
    if (libro && !libro->estaDisponible()) {
        bool disponible = true;
        libro->cambiarDisponibilidad(disponible);
        exito = true;
    }
}

// Método complejo con excepciones: Buscar por título
const Libro& Biblioteca::buscarLibroPorTitulo(const std::string& titulo) const {
    for (const auto& libro : coleccion) {
        // Búsqueda simple por coincidencia exacta
        if (libro->getTitulo() == titulo) {
            return *libro;
        }
    }
    
    // Si llegamos aquí, no se encontró el libro
    throw BibliotecaException("No se encontró ningún libro con el título: " + titulo);
}

// Método más complejo con references y algoritmos: Buscar por autor
std::vector<std::reference_wrapper<Libro>> Biblioteca::buscarLibrosPorAutor(const std::string& autor) {
    std::vector<std::reference_wrapper<Libro>> resultados;
    
    for (auto& libroPtr : coleccion) {
        if (libroPtr->getAutor() == autor) {
            // Añadimos una referencia al libro, no una copia
            resultados.push_back(std::ref(*libroPtr));
        }
    }
    
    return resultados;
}

// Método muy complejo con punteros a funciones y algoritmos
void Biblioteca::reorganizarColeccion(void (*criterioOrdenamiento)(std::vector<std::unique_ptr<Libro>>&)) {
    if (coleccion.empty()) {
        throw BibliotecaException("No hay libros para reorganizar");
    }
    
    try {
        // Aplicamos el criterio de ordenamiento pasado como función
        criterioOrdenamiento(coleccion);
    } catch (const std::exception& e) {
        throw BibliotecaException("Error al reorganizar: " + std::string(e.what()));
    }
}