#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

// Excepción personalizada para problemas relacionados con la biblioteca
class BibliotecaException : public std::runtime_error {
public:
    explicit BibliotecaException(const std::string& mensaje);
};

// Clase para representar un libro
class Libro {
private:
    int id;
    std::string titulo;
    std::string autor;
    bool disponible;

public:
    // Constructor y destructor
    Libro(int id, const std::string& titulo, const std::string& autor);
    ~Libro();

    // Métodos básicos
    int getId() const;
    std::string getTitulo() const;
    std::string getAutor() const;
    bool estaDisponible() const;

    // Métodos con referencias
    void cambiarDisponibilidad(bool& estado);
    void actualizarTitulo(const std::string& nuevoTitulo);
    
    // Método que devuelve referencia
    std::string& obtenerAutorModificable();
    
    // Método con parámetros por valor y por referencia
    void actualizarDetalles(std::string nuevoTitulo, const std::string& nuevoAutor);
};

// Clase para la gestión de la biblioteca
class Biblioteca {
private:
    std::string nombre;
    std::vector<std::unique_ptr<Libro>> coleccion;
    
    // Método privado para buscar un libro - uso interno
    Libro* buscarLibroPorId(int id);
    const Libro* buscarLibroPorId(int id) const;  // Versión constante
    
public:
    // Constructor y destructor
    Biblioteca(const std::string& nombre);
    ~Biblioteca();
    
    // Métodos simples
    void agregarLibro(int id, const std::string& titulo, const std::string& autor);
    void mostrarCatalogo() const;
    
    // Métodos con punteros
    Libro* obtenerLibro(int id);
    bool eliminarLibro(int id);
    
    // Métodos con referencias
    void prestarLibro(int id, bool& exito);
    void devolverLibro(int id, bool& exito);
    
    // Métodos complejos con manejo de errores
    const Libro& buscarLibroPorTitulo(const std::string& titulo) const;
    
    // Método más complejo con punteros inteligentes
    std::vector<std::reference_wrapper<Libro>> buscarLibrosPorAutor(const std::string& autor);
    
    // Método muy complejo con algoritmos, punteros y excepciones
    void reorganizarColeccion(void (*criterioOrdenamiento)(std::vector<std::unique_ptr<Libro>>&));
};

#endif // BIBLIOTECA_H